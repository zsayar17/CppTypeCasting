#include "ScalarConverter.hpp"


//1.79769e+308 double max
//3.40282e+38 float max
//2147483647 int max
//'~'(126) char printable max, char max 127

/*
static cast
				!compile time!
	1- faster cast than implicitly cast
	2- to avoid unrelated pointer conversion.
	3- static_cast avoid cast from derived to private base pointer.
	4- it will cast from base to derived and it is dangerous.
*/
int main(int argc, char **argv)
{
	if (argc != 2) return (1);
	std::string str = static_cast<std::string>(*(argv + 1));

	ScalarConverter::convert(str);
}
