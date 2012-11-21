#include "Timer.hpp"

namespace loop {

Timer::Timer(std::function<double()> callback, double delay):
		callback_(callback) {

	timer_.set<Timer, &Timer::self_callback>(this);
	timer_.start(delay, 0.0);
}

Timer::~Timer() {}

void Timer::self_callback(ev::timer &timer, int revents) {
	double delay(callback_());

	if (delay >= 0.0 )
		timer_.start(delay, 0.0);
}

}


