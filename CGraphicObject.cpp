#include "CGraphicObject.h"
 double CGraphicObject::SumArea(double num,CGraphicObject* ptr)
    {
    return num+ptr->Area();
    }
 double CGraphicObject::SumPerimeter(double num,CGraphicObject* ptr)
     {
     return num+ptr->Perimeter();
     }