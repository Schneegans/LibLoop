#ifndef STREAMABLE_PROPERTY_HPP_
#define STREAMABLE_PROPERTY_HPP_

#include "properties/Property.hpp"

#include <ostream>

namespace loop {

template<typename T>
class StreamableProperty : public virtual Property<T> {

	public:
		StreamableProperty(): Property<T>(){}

		StreamableProperty(T const& value):
            Property<T>(value) {}

        StreamableProperty(StreamableProperty<T> const& to_copy):
            Property<T>(to_copy) {}

        virtual ~StreamableProperty() {}

};

template<typename T>
std::ostream& operator<<(std::ostream& os, StreamableProperty<T> const& rhs) {
    return (os << rhs.get());
}

}

#endif /* STREAMABLE_PROPERTY_HPP_ */




