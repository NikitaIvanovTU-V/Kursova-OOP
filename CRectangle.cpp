#include "CRectangle.h"
CRectangle::CRectangle()
{
    m_dWidth = 0;
    m_dHeight = 0;
}
CRectangle::CRectangle(const double width, const double height)
{
    m_dWidth = width;
    m_dHeight = height;
}
double CRectangle::Area()const
{
    return (m_dHeight * m_dWidth);
}
double CRectangle::Perimeter()const
{
    return ((m_dHeight + m_dWidth) * 2);
}
ostream& CRectangle::Output(ostream& out)const
{
    out << " Height: " << m_dHeight << " Width: " << m_dWidth << " Area: " << Area() << " Perimeter: " << Perimeter() << std::endl;
    return out;
}
istream& operator>>(istream& in, CRectangle& obj)
{
    in >> obj.m_dWidth >> obj.m_dHeight;
    return in;
}
istream& CRectangle::Input(istream& in)
{
    in >> m_dWidth >> m_dHeight;
    return in;
}