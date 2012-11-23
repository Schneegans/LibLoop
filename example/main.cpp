#include "loop.hpp"

#include <iostream>

class Greeter {
    public:
        Greeter(float greet_interval = 1.f):
            timer_(greet_interval) {
                timer_.on_tick.connect(std::bind(&loop::Signal<>::emit, &greet));
            }

        loop::Signal<> greet;

    private:
        loop::Timer timer_;
};

int main() {
    Greeter greety;
    greety.greet.connect([]() {
        std::cout << "Hello loop!" << std::endl;
    });

    loop::MainLoop loop;
    loop.start();
}
