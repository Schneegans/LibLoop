#ifndef PROPERTY_HPP_
#define PROPERTY_HPP_

namespace loop {

template<typename T>
class Property {

	public:
		Property(){}

		Property(T const& value):
            value_(value) {}

        Property(Property<T> const& to_copy):
            value_(to_copy.value_) {}

        virtual ~Property() {}

        virtual Signal<T> const& on_change() const {
            return on_change_;
        }

        virtual void set(T const& value) {
            if (value != value_) {
                value_ = value;
                on_change_.emit(value_);
            }
        }

        virtual T const& get() const {
            return value_;
        }

        Property<T>& operator=(T const& rhs) {
            set(rhs);
            return *this;
        }

        Property<T>& operator=(Property<T> const& rhs) {
            set(rhs.value_);
            return *this;
        }

	private:
		T value_;
		Signal<T> on_change_;
};

}

#endif /* PROPERTY_HPP_ */

