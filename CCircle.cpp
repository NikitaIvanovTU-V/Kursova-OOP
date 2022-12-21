#include "CCircle.h"

CCircle::CCircle()
    {
        m_dRadius = 0;
    }
    CCircle::CCircle(const double radius)
    {
        m_dRadius = radius;
    }
    double CCircle::Area()const
    {
        return (PI * m_dRadius * m_dRadius);
    }
    double CCircle::Perimeter()const
    {
        return (2* PI * m_dRadius);
    }
    ostream& CCircle::Output(ostream& out)const
    {
        out << " Radius: " << m_dRadius << " Area: " << Area() << " Circumference: " << Perimeter() << std::endl;
        return out;
    }
    istream& operator>>(istream& in, CCircle& obj)
    {
        in >> obj.m_dRadius;
        return in;
    }
    istream& CCircle::Input(istream& in)
    {
        in >> m_dRadius;
        return in;
    }
    const double CCircle::PI=3.14159265358979311600;