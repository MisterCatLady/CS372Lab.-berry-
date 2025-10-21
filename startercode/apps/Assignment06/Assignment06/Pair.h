#pragma once
//Step 1 A Pair Structure
//Define a template struct Pair<Key,Value > that only has two fields: first, of type Key, and second of type Value.
//We need this structure to be ordered by key values. So, here’s a little trick that appeared in recent versions of the language. 
//C++20 introduced the spaceship operator <=>, which is a comparison operator generator. 
//If you include a default overload of this operator in a struct or class, then the compiler knows to generate correct overloads of all of the comparison operator. 
// Put an include of the compare header in your header for the Pair<Key,Value> struct and add the following in the declaration of your struct:
//auto operator<=>(const Pair &) const = default;
#include <compare>
template <typename Key, typename Value>
struct Pair
{
	Key key;
	Value val;

	auto operator<=>(const Pair&) const = default;
};

