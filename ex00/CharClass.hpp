#ifndef __CHARCLASS_HPP__
#define  __CHARCLASS_HPP__

#include "BaseCastClass.hpp"

class CharClass : virtual public BaseCastClass
{
	private:
		int char_value;

		void checkOverflow();
		void isPrintable();

		class NonDisplayable : public std::exception
		{
			public:
				const char *what() const throw();
		};

	protected:
		char getCharValue() const;
		void setCharValue(char char_value);
		bool isChar();

		void printChar();

	public:
		CharClass();
		CharClass(const CharClass& other);
		CharClass& operator=(const CharClass& other);
		~CharClass();


};




#endif
