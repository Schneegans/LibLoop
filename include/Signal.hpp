#ifndef SIGNAL_HPP_
#define SIGNAL_HPP_

#include <map>

namespace loop {

template<typename ...Parameters>
class Signal {

	public:
		Signal(): current_id_(0) {}

		int connect(std::function<void(Parameters...)> const& callback) {
			callbacks_.insert(std::make_pair(++current_id_, callback));
			return current_id_;
		}

		void disconnect(int id) {
			callbacks_.erase(id);
		}

		void emit(Parameters... p) {
			for (auto& callback: callbacks_) {
				callback.second(p...);
			}
		}

	private:
		std::map<int, std::function<void(Parameters...)>> callbacks_;
		int current_id_;
};

}

#endif /* SIGNAL_HPP_ */
