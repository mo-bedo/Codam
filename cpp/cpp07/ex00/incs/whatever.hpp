#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename swap_T>
void	swap (swap_T & a, swap_T & b)
{
	swap_T	temp = a;

	a = b;
	b = temp;
}

template <typename max_T>
max_T	max (max_T const a, max_T const b)
{
	return b >= a ? b : a;
}

template <typename min_T>
min_T	min (min_T const a, min_T const b)
{
	return b <= a ? b : a;
}

#endif 		// WHATEVER_HPP
