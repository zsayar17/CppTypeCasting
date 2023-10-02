#ifndef __CAST_HPP__
#define __CAST_HPP__

#include "CharClass.hpp"
#include "IntClass.hpp"
#include "FloatClass.hpp"
#include "DoubleClass.hpp"


class Cast : public CharClass, public IntClass, public FloatClass, public DoubleClass
{
	private:

	public:
		Cast();
		Cast(std::string str);
		Cast(const Cast& other);
		Cast& operator=(const Cast& other);
		~Cast();

		void setValue();
		void printValues();
};

#endif
