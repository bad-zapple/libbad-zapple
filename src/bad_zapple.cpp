#include "bad_zapple.hpp"
#include <iostream>

TestObj::TestObj() : value(42)
{

}

TestObj::~TestObj()
{

}

int TestObj::val() const
{
	return (value);
}

void TestObj::val(int _val)
{
	value = _val;
}

int test(int ac, char **av) {
	std::cout << "this is a test for compilation of lib" << std::endl;
	return 0;
}
