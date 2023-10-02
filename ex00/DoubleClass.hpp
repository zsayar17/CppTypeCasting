#ifndef __DOUBLECLASS_HPP__
#define  __DOUBLECLASS_HPP__

#include "BaseCastClass.hpp"

class DoubleClass : virtual public BaseCastClass
{
	private:
		double double_value;

		void checkOverflow();
		void setPseudo();
		int getFrictonalPartCount();

	protected:
		double getDoubleValue() const;
		void setDoubleValue(double double_value);

		bool IsDouble();

		void printDouble();

	public:
		DoubleClass();
		DoubleClass(const DoubleClass& other);
		DoubleClass& operator=(const DoubleClass& other);
		~DoubleClass();

};




#endif
