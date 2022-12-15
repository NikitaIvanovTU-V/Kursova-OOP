#pragma once
#include <iostream>
#include <fstream>
using std::ostream;
using std::istream;
    class CGraphicObject
    {
    public:
        virtual double Area()const=0;
        virtual double Perimeter()const=0;
        virtual ostream& Output(ostream& out)=0;
        virtual istream& Input(istream& in)=0;

    };
