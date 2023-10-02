#ifndef __FLOATCLASS_HPP__
#define  __FLOATCLASS_HPP__

#include "BaseCastClass.hpp"

class FloatClass : virtual public BaseCastClass
{
	private:
		float float_value;

		void checkOverflow();
		void setPseudo();
		int getFrictonalPartCount();

	protected:
		float getFloatValue() const;
		void setFloatValue(float float_value);
		bool IsFloat();

		void printFloat();
	public:
		FloatClass();
		FloatClass(const FloatClass& other);
		FloatClass& operator=(const FloatClass& other);
		~FloatClass();

};




#endif
