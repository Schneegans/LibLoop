#ifndef TIMER_HPP_
#define TIMER_HPP_

#include <ev++.h>
#include "Scheduler.hpp"
#include "Signal.hpp"

namespace loop {

class Timer {
	public:
		Timer(double tick_time);
		~Timer() {};

		Signal<> on_tick;

	private:
		void self_callback(ev::timer& timer, int revents);
		ev::timer timer_;
};

}

#endif /* TIMER_HPP_ */
