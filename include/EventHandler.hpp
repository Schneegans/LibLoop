#ifndef EVENTHANDLER_HPP_
#define EVENTHANDLER_HPP_

namespace loop {

struct EventHandler {

	EventHandler() {};
	virtual ~EventHandler() {};

	virtual void run() = 0;
};

}

#endif /* EVENTHANDLER_HPP_ */
