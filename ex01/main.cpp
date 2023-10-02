#include "Serializer.hpp"

int main()
{
	Data data;
	Data *data_ptr;
	unsigned long int value;

	data.c = 10;
	data.x = 20;
	data.y = 30;
	value = Serializer::serialize(&data);
	data_ptr = Serializer::deserialize(value);

	std::cout << "~Adress Test~" << std::endl;
	std::cout << "\tdata adress: " << &data << std::endl;
	std::cout << "\tdata_ptr contain adress: " << data_ptr << std::endl << std::endl;

	std::cout << "~Value Test~" << std::endl;
	std::cout << "\tdata values "  << data.c << " " << data.x << " " << data.y << std::endl;
	std::cout << "\tdata_ptr values "  << data_ptr->c << " " << data_ptr->x << " " << data_ptr->y << std::endl;

}
