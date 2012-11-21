#include "Scheduler.hpp"

namespace loop {

Scheduler::Scheduler() {}

Scheduler::~Scheduler() {}

void Scheduler::execute_delayed(std::function<void()> callback, double delay) {

	ev::timer* timer = new ev::timer();
	timer->set<Scheduler, &Scheduler::self_callback>(this);
	timer->start(delay, 0);

	tasks_.insert(std::make_pair(timer, callback));
}

void Scheduler::self_callback(ev::timer& timer, int revents) {
	auto callback(tasks_.find(&timer));

	if (callback != tasks_.end()) {
		callback->second();
		tasks_.erase(&timer);
		delete &timer;
	}
}

}


