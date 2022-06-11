#include "CComplex.h"
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
double CComplex::GetMagnitude()const
{
	return sqrt(pow(m_re, 2) + pow(m_im, 2));
}
double CComplex::GetArgument()const
{
	return atan2(m_im, m_re);
}