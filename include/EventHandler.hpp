/*
 * EventHandler.hpp
 *
 *  Created on: 20.11.2012
 *      Author: simon
 */

#ifndef EVENTHANDLER_HPP_
#define EVENTHANDLER_HPP_

#include <functional>

namespace loop {

struct EventHandler {

	EventHandler() {};
	virtual ~EventHandler() {};

	virtual void run() = 0;
};

}

#endif /* EVENTHANDLER_HPP_ */
