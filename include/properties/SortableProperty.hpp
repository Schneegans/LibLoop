#ifndef SORTABLE_PROPERTY_HPP_
#define SORTABLE_PROPERTY_HPP_

#include "properties/Property.hpp"

namespace loop {

template<typename T>
class SortableProperty : public virtual Property<T> {

	public:
		SortableProperty(): Property<T>(){}

		SortableProperty(T const& value):
            Property<T>(value) {}

        SortableProperty(SortableProperty<T> const& to_copy):
            Property<T>(to_copy) {}

        virtual ~SortableProperty() {}

        bool operator>(SortableProperty<T> const& rhs) const {
            return Property<T>::get() > rhs.get();
        }

        bool operator>(T const& rhs) const {
            return Property<T>::get() > rhs;
        }

        bool operator>=(SortableProperty<T> const& rhs) const {
            return Property<T>::get() >= rhs.get();
        }

        bool operator>=(T const& rhs) const {
            return Property<T>::get() >= rhs;
        }

        bool operator<(SortableProperty<T> const& rhs) const {
            return Property<T>::get() < rhs.get();
        }

        bool operator<(T const& rhs) const {
            return Property<T>::get() < rhs;
        }

        bool operator<=(SortableProperty<T> const& rhs) const {
            return Property<T>::get() <= rhs.get();
        }

        bool operator<=(T const& rhs) const {
            return Property<T>::get() <= rhs;
        }

};

}

#endif /* SORTABLE_PROPERTY_HPP_ */



