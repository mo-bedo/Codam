#ifndef SPAN_HHP
# define SPAN_HHP

# define SPAN_PRINT_CONSTRUCTOR_MSG	false

#include <exception>
#include <vector>

class Span
{
private :
	Span ();
	Span &operator= (const Span &);

	unsigned int const	_maxInts;
public :

	std::vector<int>	_storedInts;


	Span (unsigned const &);
	Span (const Span &);
	~Span ();

	void	addNumber(int);
	void	addRange(std::vector<int>);
	long	longestSpan();
	long	shortestSpan();

	void	printInt() const;

	class NoSpanFound : public std::exception {
	public :
		const char * what() const throw();
	};

	class SpanFull : public std::exception {
	public :
		const char * what() const throw();
	};


};

#endif //		Span_HHP
