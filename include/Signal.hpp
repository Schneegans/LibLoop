#ifndef SIGNAL_HPP_
#define SIGNAL_HPP_

#include <map>

namespace loop {

template<typename ...Parameters>
class Signal {

	public:
		Signal(): current_id_(0) {}

        template<typename F, typename ...Args>
        int connect_member(F&& f, Args&&... a) const{
			callbacks_.insert(std::make_pair(++current_id_, std::bind(f, a...)));
			return current_id_;
		}

		int connect(std::function<void(Parameters...)> const& callback) const{
			callbacks_.insert(std::make_pair(++current_id_, callback));
			return current_id_;
		}

		void disconnect(int id) const{
			callbacks_.erase(id);
		}

		void emit(Parameters... p) {
			for (auto& callback: callbacks_) {
				callback.second(p...);
			}
		}

	private:
		mutable std::map<int, std::function<void(Parameters...)>> callbacks_;
		mutable int current_id_;
};

}

#endif /* SIGNAL_HPP_ */
