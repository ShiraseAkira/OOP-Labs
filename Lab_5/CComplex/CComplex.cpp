#include "CComplex.h"
#include <cfloat>
#include <cmath>
CComplex::CComplex(double real, double image)
	:m_re(real)
	,m_im(image)
{}

double CComplex::Re()const 
{
	return m_re;
}
double CComplex::Im()const
{
	return m_im;
}

void CComplex::SetRe(double val)
{
	m_re = val;
}
void CComplex::SetIm(double val)
{
	m_im = val;
}

double CComplex::GetMagnitude()const
{
	return sqrt(pow(m_re, 2) + pow(m_im, 2));
}
double CComplex::GetArgument()const
{
	return atan2(m_im, m_re);
}

// binary +
CComplex CComplex::operator+ (CComplex const& c) const {
	return CComplex(Re() + c.Re(), Im() + c.Im());
}
CComplex operator+ (double f, CComplex const& c) {
	return CComplex(f) + c;
}

// binary -
CComplex CComplex::operator- (CComplex const& c) const {
	return CComplex(Re() - c.Re(), Im() - c.Im());
}
CComplex operator- (double f, CComplex const& c) {
	return CComplex(f) - c;
}

// binary *
CComplex CComplex::operator* (CComplex const& c) const {
	return CComplex(Re() * c.Re() - Im() * c.Im(), Im() * c.Re() + Re() * c.Im());
}
CComplex operator* (double f, CComplex const& c) {
	return c * f;
}

// binary /
CComplex CComplex::operator/ (CComplex const& c) const {
	double denominator = c.Re()*c.Re() + c.Im()*c.Im();
	double real = Re() * c.Re() + Im() * c.Im();
	double image = Im() * c.Re() - Re() * c.Im();
	return CComplex(real / denominator, image / denominator);
}
CComplex operator/ (double f, CComplex const& c) {
	return CComplex(f) / c;
}

// +=
CComplex& CComplex::operator+= (CComplex const& c) {
	SetRe(Re() + c.Re());
	SetIm(Im() + c.Im());

	return *this;
}

// -=
CComplex& CComplex::operator-= (CComplex const& c) {
	SetRe(Re() - c.Re());
	SetIm(Im() - c.Im());

	return *this;
}

// *=
CComplex& CComplex::operator*= (CComplex const& c) {
	double r = Re() * c.Re() - Im() * c.Im();
	SetIm(Im() * c.Re() + Re() * c.Im());
	SetRe(r);

	return *this;
}

// /=
CComplex& CComplex::operator/= (CComplex const& c) {
	double denominator = c.Re() * c.Re() + c.Im() * c.Im();
	double real = Re() * c.Re() + Im() * c.Im();
	double image = Im() * c.Re() - Re() * c.Im();

	SetRe(real / denominator);
	SetIm(image / denominator);

	return *this;
}

// ==
bool CComplex::operator == (CComplex const& c) const {
	return std::abs(Re() - c.Re()) < DBL_EPSILON && std::abs(Im() - c.Im()) < DBL_EPSILON;
}
bool CComplex::operator != (CComplex const& c) const {
	return !(*this == c);
}

bool operator== (double f, CComplex const& c)
{
	return c == f;
}
bool operator!= (double f, CComplex const& c)
{
	return !(c == f);
}

// + -
CComplex CComplex::operator+() const
{
	return *this;
}
CComplex CComplex::operator-() const
{
	return CComplex(-Re(), -Im());
}

// << >>
std::ostream& operator<< (std::ostream& stream, CComplex const& c)
{
	stream << c.Re()
		<< ((c.Im() >= 0) ? "+" : "")
		<< c.Im()
		<< "i";
	return stream;
}

//std::istream& operator>> (std::istream& stream, CComplex const& c)
//{
//
//}