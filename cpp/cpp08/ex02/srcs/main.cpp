#include "MutantStack.tpp"

#include <iostream>

int main()
{
	std::cout << "MutantStack" << std::endl;
	MutantStack<int>	mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top = ";
	std::cout << mstack.top() << std::endl;
	std::cout << "size before pop = " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "size after pop = ";
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(-77);
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "iterate on Mustantstack" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
 
    std::cout << "\nList" << std::endl;
    std::list<int>    list;
    list.push_back(5);
    list.push_back(99);
    std::cout << "Top = " << list.back() << std::endl;
    std::cout << "Size before pop_back() = " << list.size() << std::endl;
    list.pop_back();
	std::cout << "Size after pop_back() = " << list.size() << std::endl;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(0);
    std::list<int>::iterator itlist = list.begin();
    std::list<int>::iterator itliste = list.end();
    ++itlist;
    --itlist;
	std::cout << "iterate on List" << std::endl;
    while(itlist != itliste){
        std::cout << *itlist << std::endl;
        ++itlist;
    }
    std::list<int> s2(list);

    std::cout << "\nMutantStack reverse" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    ++rit;
    --rit;
    while(rit != rite){
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << "\nList reverse" << std::endl;
    std::list<int>::reverse_iterator ritlist = list.rbegin();
    std::list<int>::reverse_iterator ritliste = list.rend();
    ++ritlist;
    --ritlist;
    while(ritlist != ritliste){
        std::cout << *ritlist << std::endl;
        ++ritlist;
    }
	return 0;
}
