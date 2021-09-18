#include <chrono>
#include <condition_variable>
#include <iostream>
#include <thread>
#include <vector>

#define _THREAD_COUNT 3

std::mutex mutex_sum;

void work(size_t start, size_t end, size_t &sum);

// Threads, Mutex, ref
int main() {
  // Überlegen Sie sich eine geeignete parallele Strategie mit mehreren Threads
  // und summieren Sie die Zahlen 1..n parallel und thread-safe in einer
  // gemeinsamen lokalen Summenvariablen auf.

  std::cout << "_THREAD_COUNT " << _THREAD_COUNT << std::endl;

  size_t n{};
  std::cout << "n: (should be greater than " << _THREAD_COUNT << ") ";
  std::cin >> n;

  if (n <= _THREAD_COUNT) {
    std::cout << "n too small" << std::endl;
    return 0;
  }

  size_t sum{0};

  std::vector<std::thread *> threads(_THREAD_COUNT);
  double part = 1.0 * n / _THREAD_COUNT;

  static auto timer_start = std::chrono::high_resolution_clock::now();

  for (size_t i{0}; i < _THREAD_COUNT; ++i) {
    threads.at(i) =
        new std::thread(work, i * part + 1, (i + 1) * part, std::ref(sum));
  }

  for (auto *thread : threads) {
    thread->join();
  }

  // Messen Sie die Zeit jeweils für keine Parallelisierung, für zwei Threads,
  // drei Threads usw.
  std::cout << "time taken: "
            << (double)(std::chrono::duration_cast<std::chrono::microseconds>(
                            std::chrono::high_resolution_clock::now() -
                            timer_start)
                            .count())
            << "µs" << std::endl;

  std::cout << "sum = " << sum << " (should be " << (n * (n + 1) / 2) << ")"
            << std::endl;

  // Ab wie vielen Threads wird es nicht mehr schneller bzw. wird es überhaupt
  // schneller?
}

void work(size_t start, size_t end, size_t &sum) {
  size_t temp = 0;
  for (size_t i{start}; i <= end; ++i) {
    temp += i;
  }

  std::lock_guard<std::mutex> lock(mutex_sum);
  sum += temp;
}