#ifndef __BASECASTCLASS_HPP__
#define __BASECASTCLASS_HPP__

#include <iostream>
#include <limits>
#include <climits>
#include <cerrno>
#include <cstdlib>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

class BaseCastClass
{
	private:
		std::string	str;
		bool		is_special;
		int			type;

	protected:
		enum {
			NON, CHAR, INT, FLOAT, DOUBLE, SCALAR_COUNT
		};

		bool getIsSpecial() const;
		int getType() const;
		std::string getStr() const;

		void setIsSpecial(bool is_special);
		void setType(int type);
		void setStr(std::string str);

		void isValid();
		void checkPseudo();

		class OutOfRange : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class InvalidArg : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class ImpossibleError : public std::exception
		{
			public:
				const char *what() const throw();
		};
	public:
		BaseCastClass();
		BaseCastClass(std::string str);
		BaseCastClass(const BaseCastClass& other);
		BaseCastClass& operator=(const BaseCastClass& other);
		~BaseCastClass();
};


#endif
