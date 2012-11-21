#include "MainLoop.hpp"
#include <ev++.h>
#include <iostream>

namespace loop {

MainLoop::MainLoop() {}

MainLoop::~MainLoop() {}

void MainLoop::start() {
	struct ev_loop *loop = EV_DEFAULT;
	ev_run(loop, 0);
}

void MainLoop::stop() {
	struct ev_loop *loop = EV_DEFAULT;
	ev_break(loop, EVBREAK_ONE);
}

void MainLoop::on_event(std::function<void(Event)> callback) {
	callback_ = callback;
}

}
