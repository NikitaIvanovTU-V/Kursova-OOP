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

        double Area()const override;
        double Perimeter()const override;

        ostream& Output(ostream& out)const override;

        friend istream& operator>>(istream& in, CRectangle& obj);

        istream& Input(istream& in) override;

    };
    istream& operator>>(istream& in, CRectangle& obj);