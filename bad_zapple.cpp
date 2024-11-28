#include "bad_zapple.hpp"

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
