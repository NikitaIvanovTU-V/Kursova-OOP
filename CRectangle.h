#pragma once
#include "CGraphicObject.h"

    class CRectangle :public CGraphicObject
    {
    private:
        double m_dWidth;
        double m_dHeight;
    public:
        CRectangle();

        CRectangle(const double width, const double height);

        double Area()const;
        double Perimeter()const;

        ostream& Output(ostream& out)const;

        friend istream& operator>>(istream& in, CRectangle& obj);

        istream& Input(istream& in);

    };
    istream& operator>>(istream& in, CRectangle& obj);