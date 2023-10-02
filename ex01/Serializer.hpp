#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <iostream>

struct Data
{
	int x;
	int y;
	int c;
};

class Serializer
{
	private:

	public:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();

		static unsigned long int serialize(Data* ptr);
		static Data* deserialize(unsigned long int  raw);
};

#endif
