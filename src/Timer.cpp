/*
 * Timer.hpp
 *
 *  Created on: 20.11.2012
 *      Author: simon
 */

#include "Timer.hpp"

#include "EventHandler.hpp"

#include <functional>
#include <iostream>

namespace loop {

Timer::Timer(std::function<double()> callback, double delay):
			callback_(callback) {

	timer_.set<Timer, &Timer::self_callback>(this);
	timer_.start(delay, 0.0);
}

Timer::~Timer() {

}

void Timer::self_callback(ev::timer &timer, int revents) {
	double delay(-1.0);

	if ((delay = callback_()) >= 0.0 ) {
		std::cout << delay << std::endl;
		timer_.start(delay, 0.0);
	}
}

}


