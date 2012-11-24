#ifndef NUMERIC_PROPERTY_HPP_
#define NUMERIC_PROPERTY_HPP_

#include "properties/SortableProperty.hpp"
#include "properties/StreamableProperty.hpp"

namespace loop {

template<typename T>
class NumericProperty : public virtual SortableProperty<T>, public virtual StreamableProperty<T> {

	public:
		NumericProperty():
            Property<T>() {}

		NumericProperty(T const& value):
            Property<T>(value) {}

        NumericProperty(NumericProperty<T> const& to_copy):
            Property<T>(to_copy) {}

        virtual ~NumericProperty() {}

        NumericProperty<T> operator+(NumericProperty<T> const& rhs) const {
            return NumericProperty(Property<T>::get() + rhs.get());
        }

        NumericProperty<T> operator+(T const& rhs) const {
            return NumericProperty(Property<T>::get() + rhs);
        }

        NumericProperty<T> operator-(NumericProperty<T> const& rhs) const {
            return NumericProperty(Property<T>::get() - rhs.get());
        }

        NumericProperty<T> operator-(T const& rhs) const {
            return NumericProperty(Property<T>::get() - rhs);
        }

        NumericProperty<T> operator*(NumericProperty<T> const& rhs) const {
            return NumericProperty(Property<T>::get() * rhs.get());
        }

        NumericProperty<T> operator*(T const& rhs) const {
            return NumericProperty(Property<T>::get() * rhs);
        }

        NumericProperty<T> operator/(NumericProperty<T> const& rhs) const {
            return NumericProperty(Property<T>::get() / rhs.get());
        }

        NumericProperty<T> operator/(T const& rhs) const {
            return NumericProperty(Property<T>::get() / rhs);
        }

        NumericProperty<T>& operator+=(NumericProperty<T> const& rhs) {
            set(Property<T>::get() + rhs.get());
            return *this;
        }

        NumericProperty<T>& operator+=(T const& rhs) {
            set(Property<T>::get() + rhs);
            return *this;
        }

        NumericProperty<T>& operator-=(NumericProperty<T> const& rhs) {
            set(Property<T>::get() - rhs.get());
            return *this;
        }

        NumericProperty<T>& operator-=(T const& rhs) {
            set(Property<T>::get() - rhs);
            return *this;
        }

        NumericProperty<T>& operator*=(NumericProperty<T> const& rhs) {
            set(Property<T>::get() * rhs.get());
            return *this;
        }

        NumericProperty<T>& operator*=(T const& rhs) {
            set(Property<T>::get() * rhs);
            return *this;
        }

        NumericProperty<T>& operator/=(NumericProperty<T> const& rhs) {
            set(Property<T>::get() / rhs.get());
            return *this;
        }

        NumericProperty<T>& operator/=(T const& rhs) {
            set(Property<T>::get() / rhs);
            return *this;
        }

        NumericProperty<T>& operator++() {
            T tmp(Property<T>::get());
            set(++tmp);
            return *this;
        }

        NumericProperty<T> operator++(int dummy) {
            T tmp(Property<T>::get());
            set(tmp++);
            return NumericProperty<T>(tmp);
        }

        NumericProperty<T>& operator--() {
            T tmp(Property<T>::get());
            set(--tmp);
            return *this;
        }

        NumericProperty<T> operator--(int dummy) {
            T tmp(Property<T>::get());
            set(tmp--);
            return NumericProperty<T>(tmp);
        }
};

}

#endif /* NUMERIC_PROPERTY_HPP_ */

