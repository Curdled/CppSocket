#include "Class.hpp"


int what::tests::getValue(what::tests::t enum_in)
{
	switch (enum_in)
	{
	case tests::one:
		return 1;
	case tests::two:
		return 2;
	case tests::three:
		return 3;
	case tests::four: 
		return 4;
	default:
		return 0;
	}
}