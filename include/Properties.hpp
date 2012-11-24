#ifndef PROPERTIES_HPP_
#define PROPERTIES_HPP_

#include "properties/NumericProperty.hpp"
#include "properties/LogicalProperty.hpp"

namespace loop {

typedef NumericProperty<double> Double;
typedef NumericProperty<float> Float;
typedef NumericProperty<int> Int;
typedef NumericProperty<char> Char;
typedef NumericProperty<unsigned> UInt;
typedef NumericProperty<unsigned char> UChar;

typedef LogicalProperty<bool> Bool;

}

#endif /* PROPERTIES_HPP_ */

