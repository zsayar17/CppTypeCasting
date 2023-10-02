#ifndef __INTCLASS_HPP__
#define  __INTCLASS_HPP__

#include "BaseCastClass.hpp"

class IntClass : virtual public BaseCastClass
{
	private:
		int int_value;

		void checkOverflow();

	protected:
		int	getIntValue() const;
		void setIntValue(int int_value);

		bool isInt();

		void printInt();

	public:
		IntClass();
		IntClass(const IntClass& other);
		IntClass& operator=(const IntClass& other);
		~IntClass();

};




#endif
