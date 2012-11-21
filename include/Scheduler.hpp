#ifndef SCHEDULER_HPP_
#define SCHEDULER_HPP_

#include <ev++.h>
#include <functional>
#include <map>

namespace loop {

class Scheduler {
	public:
		Scheduler();
		~Scheduler();

		void execute_delayed(std::function<void()> callback, double delay);

	private:
		void self_callback(ev::timer& timer, int revents);

		std::map<ev::timer*, std::function<void()>> tasks_;
};

}

#endif /* SCHEDULER_HPP_ */
