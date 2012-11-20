/*
 * MainLoop.cpp
 *
 *  Created on: 20.11.2012
 *      Author: simon
 */

#include "MainLoop.hpp"

#include <ev++.h>
#include <iostream>

namespace loop {

MainLoop::MainLoop() {

}

MainLoop::~MainLoop() {

}

void MainLoop::start() {
	std::cout << "run" << std::endl;
	struct ev_loop *loop = EV_DEFAULT;
	ev_run(loop, 0);
}

void MainLoop::stop() {
	std::cout << "quit" << std::endl;
	struct ev_loop *loop = EV_DEFAULT;
	ev_break(loop, EVBREAK_ONE);
}

}
