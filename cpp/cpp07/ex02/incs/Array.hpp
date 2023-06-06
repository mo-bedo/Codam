#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdio>

#define ARRAY_PRINT_CONSTRUCTOR_MSG true

template <typename T>
class Array {
private :
	std::size_t _size;
	T *			_elements;
public :
	Array ();
	Array (const unsigned int &);
	Array (const Array &);
	Array & operator = (const Array &);
	~Array (void);

	T & 		operator[] (std::size_t);

	std::size_t	size() const;
};

#endif
