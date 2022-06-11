#pragma once
class CComplex
{
public:
	CComplex(double real = 0, double image = 0);
	double Re()const;
	double Im()const;
	double GetMagnitude()const;
	double GetArgument()const;

	CComplex operator+(CComplex const& c) const;
	CComplex operator-(CComplex const& c) const;
private:
	double m_re, m_im;
};

CComplex operator+(double f, CComplex const& c);
CComplex operator-(double f, CComplex const& c);