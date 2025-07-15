#include <atomic>
#include <condition_variable>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;
class MySemaphore {
public:
  MySemaphore(int n) { sources.store(n); }

  bool try_wait() {
    int cur = sources.load();
    while (cur > 0) {
      if (sources.compare_exchange_weak(cur, cur - 1)) {
        return true;
      }
      cur = sources.load();
    }
    return false;
  }

  void wait() {
    while (true) {
      int cur = sources.load();
      if (cur > 0) {
        if (sources.compare_exchange_weak(cur, cur - 1)) {
          return;
        }
      }
    }
  }

  void signal() { sources.fetch_add(1); }

private:
  atomic<int> sources;
};
// Shared resource
int sharedCounter = 0;
MySemaphore mySemaphore(1);

// Function to increment the counter with locking
void incrementCounter(int iterations) {
  for (int i = 0; i < iterations; ++i) {
    while (true) {
      if (mySemaphore.try_wait()) {
        ++sharedCounter;
        mySemaphore.signal();
        break;
      }
    }
  }
}

int main() {
  const int numThreads = 4;
  const int iterationsPerThread = 100000;

  // Create multiple threads
  std::vector<std::thread> threads;
  for (int i = 0; i < numThreads; ++i) {
    threads.emplace_back(incrementCounter, iterationsPerThread);
  }

  // Wait for all threads to finish
  for (auto &thread : threads) {
    thread.join();
  }

  // Print the final result
  std::cout << "Final counter value: " << sharedCounter << std::endl;
  std::cout << "Expected value: " << numThreads * iterationsPerThread
            << std::endl;

  return 0;
}