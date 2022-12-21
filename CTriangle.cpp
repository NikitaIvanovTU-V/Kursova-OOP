#include "CTriangle.h"
CTriangle::CTriangle()
    {
        m_dSideA = 0;
        m_dSideB = 0;
        m_dSideC = 0;
    }
   CTriangle::CTriangle(const double A, const double B, const double C)
    {
        m_dSideA = A;
        m_dSideB = B;
        m_dSideC = C;
    }
    double CTriangle::Area()const
    {
        double p = Perimeter() / 2;
        return (sqrt(p*(p-m_dSideA) * (p - m_dSideB) * (p - m_dSideC)));
    }
    double CTriangle::Perimeter()const
    {
        return (m_dSideA + m_dSideB + m_dSideC);
    }
    ostream& CTriangle::Output(ostream& out)const
    {
        out << " Side A: " << m_dSideA << " Side B: " << m_dSideB << " Side C: " << m_dSideC << " Area: " << Area() << " Perimeter: " << Perimeter() << std::endl;
        return out;
    }
    istream& operator>>(istream& in, CTriangle& obj)
    {
        in >> obj.m_dSideA >> obj.m_dSideB >> obj.m_dSideC;
        return in;
    }
    istream& CTriangle::Input(istream& in)
    {
        in >> m_dSideA >> m_dSideB >> m_dSideC;
        return in;
    }
    bool CTriangle::IsATriangle()
    {
        if ((m_dSideA < m_dSideB + m_dSideC) && (m_dSideB < m_dSideA + m_dSideC) && (m_dSideC < m_dSideB + m_dSideA))
            return true;
        else return false;
    }