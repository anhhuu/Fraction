//
// Fraction library Source Code
// Copyright (c) 2016 panhhuu.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
// 



#include "Fraction.h"

CFractions::CFractions()
{
	this->m_numerator = 0;
	this->m_denominator = 1;
}

CFractions::CFractions(const int numerator, const int denominator)
{
	this->m_numerator = numerator;
	if(denominator == 0)
	{
		this->m_denominator = 1;
	} else
	{
		this->m_denominator = denominator;
	}
}

int CFractions::getNumerator()
{
	return this->m_numerator;
}

void CFractions::setNumerator(const int numerator)
{
	this->m_numerator = numerator;
}

int CFractions::getDenominator()
{
	return this->m_denominator;
}

void CFractions::setDenominator(const int denominator)
{
	this->m_denominator = denominator;
}

int CFractions::gcd(int number1, int number2)
{
	while(number2 != 0)
	{
		int temp = number2;
		number2 = number1 % number2;
		number1 = temp;
	}
	if(number1 > 0)
	{
		return number1;
	} else
	{
		return -number1;
	}

}

double CFractions::convertToDouble()
{
	return ((static_cast<double>(this->m_numerator)) / (static_cast<double>(this->m_denominator)));
}

int CFractions::covertToInt()
{
	return ((this->m_numerator) / (this->m_denominator));
}

const CFractions &CFractions::operator=(const int number)
{
	this->m_numerator = number;
	this->m_denominator = 1;
	return *this;
}

CFractions CFractions::operator-() const
{
	CFractions temp{ 0, 1 };
	temp.m_numerator = -(this->m_numerator);
	temp.m_denominator = this->m_denominator;
	return temp;
}

const CFractions CFractions::operator+(const CFractions &fraction) const
{
	CFractions temp{ 0, 1 };
	temp.m_numerator = (this->m_numerator) * (fraction.m_denominator) + (fraction.m_numerator) * (this->m_denominator);
	temp.m_denominator = (this->m_denominator) * (fraction.m_denominator);

	int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

	temp.m_numerator = temp.m_numerator / gcd;
	temp.m_denominator = temp.m_denominator / gcd;

	return temp;
}

const CFractions CFractions::operator-(const CFractions &fraction) const
{
	CFractions temp{ 0, 1 };
	temp.m_numerator = (this->m_numerator) * (fraction.m_denominator) - (fraction.m_numerator) * (this->m_denominator);
	temp.m_denominator = (this->m_denominator) * (fraction.m_denominator);

	int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

	temp.m_numerator = temp.m_numerator / gcd;
	temp.m_denominator = temp.m_denominator / gcd;

	return temp;
}

const CFractions CFractions::operator*(const CFractions &fraction) const
{
	CFractions temp{ 0, 1 };
	temp.m_numerator = (this->m_numerator) * (fraction.m_numerator);
	temp.m_denominator = (this->m_denominator) * (fraction.m_denominator);

	int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

	temp.m_numerator = temp.m_numerator / gcd;
	temp.m_denominator = temp.m_denominator / gcd;

	return temp;
}

const CFractions CFractions::operator/(const CFractions &fraction) const
{
	if(fraction.m_numerator == 0)
	{
		std::cout << "Error! Can not divied for 0\n";
		exit(-1);
	} else
	{
		CFractions temp{ 0, 1 };
		temp.m_numerator = (this->m_numerator) * (fraction.m_denominator);
		temp.m_denominator = (this->m_denominator) * (fraction.m_numerator);

		int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

		temp.m_numerator = temp.m_numerator / gcd;
		temp.m_denominator = temp.m_denominator / gcd;

		return temp;
	}
}

const CFractions CFractions::operator+(const int number) const
{
	CFractions temp{ 0, 1 };
	temp.m_numerator = (this->m_numerator) + number * (this->m_denominator);
	temp.m_denominator = this->m_denominator;

	int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

	temp.m_numerator = temp.m_numerator / gcd;
	temp.m_denominator = temp.m_denominator / gcd;

	return temp;
}

const CFractions CFractions::operator-(const int number) const
{
	CFractions temp{ 0, 1 };
	temp.m_numerator = (this->m_numerator) - number * (this->m_denominator);
	temp.m_denominator = this->m_denominator;

	int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

	temp.m_numerator = temp.m_numerator / gcd;
	temp.m_denominator = temp.m_denominator / gcd;

	return temp;
}

const CFractions CFractions::operator*(const int number) const
{
	CFractions temp{ 0, 1 };
	temp.m_numerator = (this->m_numerator) * number;
	temp.m_denominator = this->m_denominator;

	int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

	temp.m_numerator = temp.m_numerator / gcd;
	temp.m_denominator = temp.m_denominator / gcd;

	return temp;
}

const CFractions CFractions::operator/(const int number) const
{
	if(number == 0)
	{
		std::cout << "Error! Can not divied for 0\n";
		exit(-1);
	} else
	{
		CFractions temp{ 0, 1 };
		temp.m_numerator = (this->m_numerator);
		temp.m_denominator = this->m_denominator * number;

		int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

		temp.m_numerator = temp.m_numerator / gcd;
		temp.m_denominator = temp.m_denominator / gcd;

		return temp;
	}
}

CFractions &CFractions::operator++()
{
	*this = *this + 1;
	return *this;
}

CFractions CFractions::operator++(const int)
{
	CFractions temp{ this->m_numerator, this->m_denominator };
	*this = *this + 1;
	return temp;
}

CFractions &CFractions::operator--()
{
	*this = *this - 1;
	return *this;
}

CFractions CFractions::operator--(const int)
{
	CFractions temp{ this->m_numerator, this->m_denominator };
	*this = *this - 1;
	return temp;
}

const CFractions &CFractions::operator+=(const int number)
{
	*this = *this + number;
	return *this;
}

const CFractions &CFractions::operator-=(const int number)
{
	*this = *this - number;
	return *this;
}

const CFractions &CFractions::operator*=(const int number)
{
	*this = *this * number;
	return *this;
}

const CFractions &CFractions::operator/=(const int number)
{
	if(number == 0)
	{
		std::cout << "Error! Can not divied for 0\n";
		exit(-1);
	} else
	{
		*this = *this / number;
		return *this;
	}
}

const CFractions &CFractions::operator+=(const CFractions &fraction)
{
	*this = *this + fraction;
	return *this;
}

const CFractions &CFractions::operator-=(const CFractions &fraction)
{
	*this = *this - fraction;
	return *this;
}

const CFractions &CFractions::operator*=(const CFractions &fraction)
{
	*this = *this * fraction;
	return *this;
}

const CFractions &CFractions::operator/=(const CFractions &fraction)
{
	if(fraction.m_numerator == 0)
	{
		std::cout << "Error! Can not divied for 0\n";
		exit(-1);
	} else
	{
		*this = *this / fraction;
		return *this;
	}
}

const bool CFractions::operator>(const CFractions &fraction) const
{
	if((this->m_numerator) * (fraction.m_denominator) > (fraction.m_numerator) * (this->m_denominator))
	{
		return true;
	}
	return false;
}

const bool CFractions::operator>=(const CFractions &fraction) const
{
	if((this->m_numerator) * (fraction.m_denominator) >= (fraction.m_numerator) * (this->m_denominator))
	{
		return true;
	}
	return false;
}

const bool CFractions::operator<(const CFractions &fraction) const
{
	if((this->m_numerator) * (fraction.m_denominator) < (fraction.m_numerator) * (this->m_denominator))
	{
		return true;
	}
	return false;
}

const bool CFractions::operator<=(const CFractions &fraction) const
{
	if((this->m_numerator) * (fraction.m_denominator) <= (fraction.m_numerator) * (this->m_denominator))
	{
		return true;
	}
	return false;
}

const bool CFractions::operator==(const CFractions &fraction) const
{
	if((this->m_numerator) * (fraction.m_denominator) == (fraction.m_numerator) * (this->m_denominator))
	{
		return true;
	}
	return false;
}

const bool CFractions::operator!=(const CFractions &fraction) const
{
	if((this->m_numerator) * (fraction.m_denominator) != (fraction.m_numerator) * (this->m_denominator))
	{
		return true;
	}
	return false;
}

const CFractions CFractions::operator^(const int n) const
{
	CFractions temp{ (this->m_numerator), (this->m_denominator) };
	temp.m_numerator = static_cast<int>(pow(this->m_numerator, n));
	temp.m_denominator = static_cast<int>(pow(this->m_denominator, n));
	int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

	temp.m_numerator = temp.m_numerator / gcd;
	temp.m_denominator = temp.m_denominator / gcd;
	return temp;
}

CFractions::~CFractions()
{
}

std::istream &operator >> (std::istream &input, CFractions &fraction)
{
	std::cout << "Numerator: ";
	input >> fraction.m_numerator;
	do
	{
		std::cout << "Denominator: ";
		input >> fraction.m_denominator;
	} while(fraction.m_denominator == 0);
	return input;
}

std::ostream &operator<<(std::ostream &output, const CFractions &fraction)
{
	if(fraction.m_numerator % fraction.m_denominator == 0)
	{
		output << (fraction.m_numerator / fraction.m_denominator);
	} else
	{
		if(fraction.m_denominator < 0)
		{
			output << -fraction.m_numerator << "/" << -fraction.m_denominator;
			//output << fraction.m_numerator << "/" << fraction.m_denominator;
		} else
		{
			output << fraction.m_numerator << "/" << fraction.m_denominator;
		}
	}
	return output;
}

const CFractions operator+(const int & number, const CFractions & fraction)
{
	CFractions temp{ 1,0 };
	temp = fraction + number;
	return temp;
}

const CFractions operator-(const int & number, const CFractions & fraction)
{
	CFractions temp{ 0, 1 };
	temp.m_numerator = number * (fraction.m_denominator) - (fraction.m_numerator);
	temp.m_denominator = fraction.m_denominator;

	int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

	temp.m_numerator = temp.m_numerator / gcd;
	temp.m_denominator = temp.m_denominator / gcd;

	return temp;
}

const CFractions operator*(const int & number, const CFractions & fraction)
{
	CFractions temp{ 1,0 };
	temp = fraction * number;
	return temp;
}

const CFractions operator/(const int & number, const CFractions & fraction)
{
	if(fraction.m_numerator == 0)
	{
		std::cout << "Error! Can not divied for 0\n";
		exit(-1);
	} else
	{
		CFractions temp{ 0, 1 };
		temp.m_numerator = number * (fraction.m_denominator);
		temp.m_denominator = fraction.m_numerator;

		int gcd = temp.gcd(temp.m_numerator, temp.m_denominator);

		temp.m_numerator = temp.m_numerator / gcd;
		temp.m_denominator = temp.m_denominator / gcd;

		return temp;
	}
}

const bool operator>(const int & number, const CFractions & fraction)
{
	if(static_cast<double>(number) > ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator))))
	{
		return true;
	} else
	{
		return false;
	}
}

const bool operator>=(const int & number, const CFractions & fraction)
{
	if(static_cast<double>(number) >= ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator))))
	{
		return true;
	} else
	{
		return false;
	}
}

const bool operator<(const int & number, const CFractions & fraction)
{
	if(static_cast<double>(number) < ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator))))
	{
		return true;
	} else
	{
		return false;
	}
}

const bool operator<=(const int & number, const CFractions & fraction)
{
	if(static_cast<double>(number) <= ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator))))
	{
		return true;
	} else
	{
		return false;
	}
}

const bool operator==(const int & number, const CFractions & fraction)
{
	if(static_cast<double>(number) == ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator))))
	{
		return true;
	} else
	{
		return false;
	}
}

const bool operator!=(const int & number, const CFractions & fraction)
{
	if(static_cast<double>(number) != ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator))))
	{
		return true;
	} else
	{
		return false;
	}
}

const bool operator>(const double & number, const CFractions & fraction)
{
	if(number > ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator))))
	{
		return true;
	} else
	{
		return false;
	}
}

const bool operator>=(const double & number, const CFractions & fraction)
{
	if(number >= ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator))))
	{
		return true;
	} else
	{
		return false;
	}
}

const bool operator<(const double & number, const CFractions & fraction)
{
	if(number < ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator))))
	{
		return true;
	} else
	{
		return false;
	}
}

const bool operator<=(const double & number, const CFractions & fraction)
{
	if(number <= ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator))))
	{
		return true;
	} else
	{
		return false;
	}
}

const bool operator==(const double & number, const CFractions & fraction)
{
	if(number == ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator))))
	{
		return true;
	} else
	{
		return false;
	}
}

const bool operator!=(const double & number, const CFractions & fraction)
{
	if(number != ((static_cast<double>(fraction.m_numerator)) / (static_cast<double>(fraction.m_denominator))))
	{
		return true;
	} else
	{
		return false;
	}
}
