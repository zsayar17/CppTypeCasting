#include "MyClasses.hpp"

Base::~Base() {};

Base * generate(void) {
	int random;

	random = rand() % 3 + 1;
	switch (random)
	{
		case 1:
			std::cout << "A created\n";
			return (new A);
			break;
		case 2:
			std::cout << "B created\n";
			return (new B);
			break;
		case 3:
			std::cout << "C created\n";
			return (new C);
			break;
	}
	return (NULL);
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) std::cout << "This is A\n";
	else if (dynamic_cast<B*>(p)) std::cout << "This is B\n";
	else if (dynamic_cast<C*>(p)) std::cout << "This is C\n";

}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "This is A\n";
		(void)a;
		return;
	}
	catch(const std::exception& e) {}

	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "This is B\n";
		(void)b;
		return;
	}
	catch(const std::exception& e) {}
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "This is C\n";
		(void)c;
		return;
	}
	catch(const std::exception& e) {}
}

int main()
{
	std::srand(std::time(NULL));
	const int base_count = 5;

	Base *base[base_count];
	std::cout << "Generate\n";
	for (int i = 0; i < base_count; i++) base[i] = generate();

	std::cout << "\nIdentify with ptr\n";
	for (int i = 0; i < base_count; i++) identify(base[i]);

	std::cout << "\nIdentify with ref\n";
	for (int i = 0; i < base_count; i++) identify(*base[i]);

	std::cout << "\nDelete\n";
	for (int i = 0; i < base_count; i++) delete base[i];
}
