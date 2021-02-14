// author: a.voss@fh-aachen.de

#include <iostream>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;
using std::thread;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

void start_and_wait_for_thread() {
    thread([]() -> void {
        printf("- starte worker-thread...\n");
        sleep_for(milliseconds(1000));
        printf("- worker-thread fertig...\n");
    }).join();
}

int main() {
    printf("starte main-thread...\n");
    start_and_wait_for_thread();
    sleep_for(milliseconds(3000));
    printf("main-thread fertig\n");
    return 0;
}

// start_and_wait_for_thread();
// disassemble --name main
// register read rip
// thread list
