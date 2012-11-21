#include "Timer.hpp"

namespace loop {

Timer::Timer(double tick_time) {

	timer_.set<Timer, &Timer::self_callback>(this);
	timer_.start(tick_time, tick_time);
}

void Timer::self_callback(ev::timer& timer, int revents) {
	on_tick.emit();
}

}


