#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
// 示例使用代码
#include <thread>
#include <vector>
// 日志级别枚举
enum class LogLevel { DEBUG, INFO, WARNING, ERROR };

// 日志系统类
class Logger {
private:
  std::ofstream file_stream_;       // 日志文件流
  std::mutex mutex_;                // 线程安全锁
  LogLevel min_level_;              // 最小日志级别
  bool console_output_;             // 是否输出到控制台
  const std::string log_file_path_; // 日志文件路径

  // 获取当前时间戳
  static std::string get_timestamp() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
    return ss.str();
  }

  // 将日志级别转换为字符串
  static std::string level_to_string(LogLevel level) {
    switch (level) {
    case LogLevel::DEBUG:
      return "DEBUG";
    case LogLevel::INFO:
      return "INFO";
    case LogLevel::WARNING:
      return "WARNING";
    case LogLevel::ERROR:
      return "ERROR";
    default:
      return "UNKNOWN";
    }
  }

  // 写入日志
  void write_log(LogLevel level, const std::string &message) {
    if (level < min_level_)
      return; // 忽略低于最小级别的日志

    std::lock_guard<std::mutex> lock(mutex_);
    std::string log_entry =
        "[" + get_timestamp() + "] [" + level_to_string(level) + "] " + message;

    // 输出到控制台
    if (console_output_) {
      std::cout << log_entry << std::endl;
    }

    // 输出到文件
    if (file_stream_.is_open()) {
      file_stream_ << log_entry << std::endl;
      file_stream_.flush(); // 确保立即写入
    }
  }

public:
  Logger(const std::string &log_file_path, LogLevel min_level = LogLevel::INFO,
         bool console_output = true)
      : min_level_(min_level), console_output_(console_output),
        log_file_path_(log_file_path) {
    file_stream_.open(log_file_path, std::ios::app);
    if (!file_stream_.is_open()) {
      std::cerr << "Failed to open log file: " << log_file_path << std::endl;
      console_output_ = true; // 回退到控制台输出
    }
  }

  ~Logger() {
    if (file_stream_.is_open()) {
      file_stream_.close();
    }
  }

  // 设置最小日志级别
  void set_min_level(LogLevel level) {
    std::lock_guard<std::mutex> lock(mutex_);
    min_level_ = level;
  }

  // 日志记录函数
  void log(LogLevel level, const std::string &message) {
    write_log(level, message);
  }

  // 便捷的日志级别方法
  void debug(const std::string &message) { log(LogLevel::DEBUG, message); }
  void info(const std::string &message) { log(LogLevel::INFO, message); }
  void warning(const std::string &message) { log(LogLevel::WARNING, message); }
  void error(const std::string &message) { log(LogLevel::ERROR, message); }
};

// 单例模式获取 Logger 实例
class LoggerSingleton {
public:
  static Logger &get_instance(const std::string &log_file_path = "app.log",
                              LogLevel min_level = LogLevel::INFO,
                              bool console_output = true) {
    static Logger instance(log_file_path, min_level, console_output);
    return instance;
  }
};

// 日志宏，简化使用
#define LOG_DEBUG(msg) LoggerSingleton::get_instance().debug(msg)
#define LOG_INFO(msg) LoggerSingleton::get_instance().info(msg)
#define LOG_WARNING(msg) LoggerSingleton::get_instance().warning(msg)
#define LOG_ERROR(msg) LoggerSingleton::get_instance().error(msg)

int main() {
  // 初始化日志系统
  Logger &logger = LoggerSingleton::get_instance("app.log", LogLevel::DEBUG);

  // 测试基本日志
  LOG_DEBUG("This is a debug message");
  LOG_INFO("Application started");
  LOG_WARNING("This is a warning");
  LOG_ERROR("An error occurred");

  // 测试并发日志
  std::vector<std::thread> threads;
  for (int i = 0; i < 5; ++i) {
    threads.emplace_back([i]() {
      LOG_INFO("Thread " + std::to_string(i) + " is running");
      LOG_DEBUG("Thread " + std::to_string(i) + " debug info");
    });
  }

  // 等待线程完成
  for (auto &t : threads) {
    t.join();
  }

  // 更改日志级别
  logger.set_min_level(LogLevel::WARNING);
  LOG_DEBUG("This debug message should not appear");
  LOG_WARNING("This warning should appear");

  return 0;
}