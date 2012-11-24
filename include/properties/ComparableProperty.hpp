#ifndef COMPARABLE_PROPERTY_HPP_
#define COMPARABLE_PROPERTY_HPP_

#include "properties/Property.hpp"

namespace loop {

template<typename T>
class ComparableProperty : public virtual Property<T> {

	public:
		ComparableProperty(): Property<T>(){}

		ComparableProperty(T const& value):
            Property<T>(value) {}

        ComparableProperty(ComparableProperty<T> const& to_copy):
            Property<T>(to_copy) {}

        virtual ~ComparableProperty() {}

        bool operator==(ComparableProperty<T> const& rhs) const {
            return Property<T>::get() == rhs.get();
        }

        bool operator==(T const& rhs) const {
            return Property<T>::get() == rhs;
        }

        bool operator!=(ComparableProperty<T> const& rhs) const {
            return Property<T>::get() != rhs.get();
        }

        bool operator!=(T const& rhs) const {
            return Property<T>::get() != rhs;
        }
};

}

#endif /* COMPARABLE_PROPERTY_HPP_ */


