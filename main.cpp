#include <emscripten.h>
#include <emscripten/threading.h>
#include <thread>
#include <vector>
#include <atomic>

std::atomic<int> counter(0);

void incrementCounter() {
    for (int i = 0; i < 1000000; ++i) {
        counter.fetch_add(1, std::memory_order_relaxed);
    }
}

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    int runThreads(int numThreads) {
        std::vector<std::thread> threads;
        for (int i = 0; i < numThreads; ++i) {
            threads.emplace_back(incrementCounter);
        }
        for (auto& t : threads) {
            t.join();
        }
        return counter.load();
    }
}