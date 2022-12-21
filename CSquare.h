#pragma once
#include "CGraphicObject.h"

    class CSquare :public CGraphicObject
    {
    private:
        double m_dWidth;
    public:
        CSquare();

        CSquare(const double width);

        double Area()const override;
        double Perimeter()const override;

        ostream& Output(ostream& out)const override;

        friend istream& operator>>(istream& in, CSquare& obj);
      
        istream& Input(istream& in) override;

    };
    istream& operator>>(istream& in, CSquare& obj);
  