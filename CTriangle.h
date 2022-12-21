#pragma once
#include "CGraphicObject.h"

    class CTriangle :public CGraphicObject
    {
    private:
        double m_dSideA;
        double m_dSideB;
        double m_dSideC;
    public:
        CTriangle();

        CTriangle(const double A, const double B, const double C);

        double Area()const override;
        double Perimeter()const override;

        ostream& Output(ostream& out)const override;

        friend istream& operator>>(istream& in, CTriangle& obj);
      
        istream& Input(istream& in) override;
        static const double PI;
        bool IsATriangle();
    };
    istream& operator>>(istream& in, CTriangle& obj);