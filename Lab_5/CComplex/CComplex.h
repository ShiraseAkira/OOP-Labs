#pragma once
class CComplex
{
public:
	CComplex(double real = 0, double image = 0);
	double Re()const;
	double Im()const;
	double GetMagnitude()const;
	double GetArgument()const;

	void SetRe(double val);
	void SetIm(double val);

	CComplex operator+ (CComplex const& c) const;
	CComplex operator- (CComplex const& c) const;
	CComplex operator* (CComplex const& c) const;
	CComplex operator/ (CComplex const& c) const;

	CComplex& operator+= (CComplex const& c);
	CComplex& operator-= (CComplex const& c);
	CComplex& operator*= (CComplex const& c);
	CComplex& operator/= (CComplex const& c);

	bool operator == (CComplex const& c) const;
	bool operator != (CComplex const& c) const;

	CComplex operator+() const;
	CComplex operator-() const;
private:
	double m_re, m_im;
};

CComplex operator+ (double f, CComplex const& c);
CComplex operator- (double f, CComplex const& c);
CComplex operator* (double f, CComplex const& c);
CComplex operator/ (double f, CComplex const& c);

bool operator == (double f, CComplex const& c);
bool operator != (double f, CComplex const& c);
