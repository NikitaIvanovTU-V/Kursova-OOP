#pragma once
#include "CGraphicObject.h"

    class CCircle :public CGraphicObject
    {
    private:
        double m_dRadius;
    public:
        CCircle();

        CCircle(const double width);

        double Area()const override;
        double Perimeter()const override;

        ostream& Output(ostream& out)const override;

        friend istream& operator>>(istream& in, CCircle& obj);
      
        istream& Input(istream& in) override;
        static const double PI;
    };
    istream& operator>>(istream& in, CCircle& obj);
