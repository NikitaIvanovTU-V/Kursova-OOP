#include "CSquare.h"
CSquare::CSquare()
    {
        m_dWidth = 0;
    }
    CSquare::CSquare(const double width)
    {
        m_dWidth = width;
    }
    double CSquare::Area()const
    {
        return (m_dWidth * m_dWidth);
    }
    double CSquare::Perimeter()const
    {
        return (m_dWidth*4);
    }
    ostream& CSquare::Output(ostream& out)const
    {
        out << " Width: " << m_dWidth << " Area: " << Area() << " Perimeter: " << Perimeter() << std::endl;
        return out;
    }
    istream& operator>>(istream& in, CSquare& obj)
    {
        in >> obj.m_dWidth;
        return in;
    }
    istream& CSquare::Input(istream& in)
    {
        in >> m_dWidth;
        return in;
    }