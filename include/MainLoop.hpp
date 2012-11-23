#ifndef MAINLOOP_HPP_
#define MAINLOOP_HPP_

#include <functional>

namespace loop {

class MainLoop {
	public:
		MainLoop();
		~MainLoop();

		void start();
		void stop();

};

}

#endif /* MAINLOOP_HPP_ */
