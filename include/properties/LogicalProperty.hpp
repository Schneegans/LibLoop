#ifndef LOGICAL_PROPERTY_HPP_
#define LOGICAL_PROPERTY_HPP_

#include "properties/ComparableProperty.hpp"

namespace loop {

template<typename T>
class LogicalProperty : public virtual ComparableProperty<T> {

	public:
		LogicalProperty(): Property<T>(){}

		LogicalProperty(T const& value):
            Property<T>(value) {}

        LogicalProperty(LogicalProperty<T> const& to_copy):
            Property<T>(to_copy) {}

        virtual ~LogicalProperty() {}

        bool operator&&(LogicalProperty<T> const& rhs) const {
            return Property<T>::get() && rhs.get();
        }

        bool operator&&(T const& rhs) const {
            return Property<T>::get() && rhs;
        }

        bool operator||(LogicalProperty<T> const& rhs) const {
            return Property<T>::get() || rhs.get();
        }

        bool operator||(T const& rhs) const {
            return Property<T>::get() || rhs;
        }

        bool operator&(LogicalProperty<T> const& rhs) const {
            return Property<T>::get() & rhs.get();
        }

        bool operator&(T const& rhs) const {
            return Property<T>::get() & rhs;
        }

        bool operator|(LogicalProperty<T> const& rhs) const {
            return Property<T>::get() | rhs.get();
        }

        bool operator|(T const& rhs) const {
            return Property<T>::get() | rhs;
        }

        LogicalProperty<T> operator!() const {
            return LogicalProperty<T>(!Property<T>::get());
        }
};

}

#endif /* LOGICAL_PROPERTY_HPP_ */



