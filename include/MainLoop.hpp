#ifndef MAINLOOP_HPP_
#define MAINLOOP_HPP_

#include "Event.hpp"
#include <functional>

namespace loop {

class MainLoop {
	public:
		MainLoop();
		~MainLoop();

		void start();
		void stop();

		void on_event(std::function<void(Event)> callback);

	private:
		std::function<void(Event)> callback_;
};

}

#endif /* MAINLOOP_HPP_ */
