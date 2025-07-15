#include <atomic>
#include <condition_variable>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;
class MyMutex {

public:
  MyMutex() { flag.store(false); }
  bool trylock() {
    bool expected = false;
    if (!flag.compare_exchange_weak(expected, true)) {
      return false;
    }
    return true;
  }
  void unlock() { flag.store(false); }

private:
  atomic<bool> flag;
};
// Shared resource
int sharedCounter = 0;
MyMutex myMutex;

// Function to increment the counter with locking
void incrementCounter(int iterations) {
  for (int i = 0; i < iterations; ++i) {
    while (true) {
      if (myMutex.trylock()) {
        ++sharedCounter;
        myMutex.unlock();
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