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



#pragma once
#include <iostream>

class CFractions
{
private:
	int m_numerator;
	int m_denominator;

public:
	CFractions();
	CFractions(const int numerator, const int denominator);

	int getNumerator();
	void setNumerator(const int numerator);

	int getDenominator();
	void setDenominator(const int denominator);


	double convertToDouble();
	int covertToInt();

	friend std::istream &operator >> (std::istream &input, CFractions &fraction);
	friend std::ostream &operator<<(std::ostream &output, const CFractions &fraction);

	const CFractions &operator=(const int number);

	CFractions operator-() const;

	const CFractions operator+(const CFractions &fraction) const;
	const CFractions operator-(const CFractions &fraction) const;
	const CFractions operator*(const CFractions &fraction) const;
	const CFractions operator/(const CFractions &fraction) const;

	const CFractions operator+(const int number) const;
	const CFractions operator-(const int number) const;
	const CFractions operator*(const int number) const;
	const CFractions operator/(const int number) const;

	const friend CFractions operator+(const int &number, const CFractions &fraction);
	const friend CFractions operator-(const int &number, const CFractions &fraction);
	const friend CFractions operator*(const int &number, const CFractions &fraction);
	const friend CFractions operator/(const int &number, const CFractions &fraction);

	CFractions &operator++();
	CFractions operator++(const int);
	CFractions &operator--();
	CFractions operator--(const int);
	const CFractions &operator+=(const int number);
	const CFractions &operator-=(const int number);
	const CFractions &operator*=(const int number);
	const CFractions &operator/=(const int number);
	const CFractions &operator+=(const CFractions &fraction);
	const CFractions &operator-=(const CFractions &fraction);
	const CFractions &operator*=(const CFractions &fraction);
	const CFractions &operator/=(const CFractions &fraction);

	const bool operator>(const CFractions &fraction) const;
	const bool operator>=(const CFractions &fraction) const;
	const bool operator<(const CFractions &fraction) const;
	const bool operator<=(const CFractions &fraction) const;
	const bool operator==(const CFractions &fraction) const;
	const bool operator!=(const CFractions &fraction) const;

	friend const bool operator>(const int &number, const CFractions &fraction);
	friend const bool operator>=(const int &number, const CFractions &fraction);
	friend const bool operator<(const int &number, const CFractions &fraction);
	friend const bool operator<=(const int &number, const CFractions &fraction);
	friend const bool operator==(const int &number, const CFractions &fraction);
	friend const bool operator!=(const int &number, const CFractions &fraction);

	friend const bool operator>(const double &number, const CFractions &fraction);
	friend const bool operator>=(const double &number, const CFractions &fraction);
	friend const bool operator<(const double &number, const CFractions &fraction);
	friend const bool operator<=(const double &number, const CFractions &fraction);
	friend const bool operator==(const double &number, const CFractions &fraction);
	friend const bool operator!=(const double &number, const CFractions &fraction);

	const CFractions operator^(const int n) const;

	~CFractions();

private:
	int gcd(int mumber1, int number2);

};
