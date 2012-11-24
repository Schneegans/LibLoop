#include "loop.hpp"

#include <iostream>

class Greeter {
    public:
        Greeter(float greet_interval = 1.f):
            timer_(greet_interval) {
                timer_.on_tick.connect([&](){
                    std::cout << "Minding my own business..." << std::endl;
                    greet.emit();
                });
            }

        loop::Signal<> greet;

    private:
        loop::Timer timer_;
};

int main() {
    Greeter greety(2.f);
    loop::Scheduler scheduler;
    greety.greet.connect([&]() {
        scheduler.execute_delayed([](){
            std::cout << "Surprise!" << std::endl;
        }, 5);
    });

    loop::MainLoop loop;
    loop.start();
}
