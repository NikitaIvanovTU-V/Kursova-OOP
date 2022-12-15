#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <chrono>
#include "CRectangle.h"
const double PI = 3.14159265358979311600;
using namespace std;
enum CGraphicObjectType
{
    Rectangle=2,
    Square,
    Circle,
    Triangle

};
/*class CRectangle :public CGraphicObject
{
private:
    double m_dWidth;
    double m_dHeight;
public:
    CRectangle()
    {
        m_dWidth = 0;
        m_dHeight = 0;
    }

    CRectangle(const double width, const double height)
    {
        m_dWidth = width;
        m_dHeight = height;
    }
    double Area()const
    {
        return (m_dHeight * m_dWidth);
    }
    double Perimeter()const
    {
        return ((m_dHeight + m_dWidth) * 2);
    }
    ostream& Output(ostream& out)const
    {
        out << " Height: " << m_dHeight << " Width: " << m_dWidth << " Area: " << Area() << " Perimeter: " << Perimeter() << endl;
        return out;
    }
    friend istream& operator>>(istream& in, CRectangle& obj)
    {
        in >> obj.m_dWidth >> obj.m_dHeight;
        return in;
    }
    istream& Input(istream& in)
    {
        in >>m_dWidth >>m_dHeight;
        return in;
    }
};
*/
class CSquare :public CGraphicObject
{
private:
    double m_dWidth;
public:
    CSquare()
    {
        m_dWidth = 0;
    }
    CSquare(const double width)
    {
        m_dWidth = width;
    }
    double Area()const
    {
        return (m_dWidth * m_dWidth);
    }
    double Perimeter()const
    {
        return (m_dWidth*4);
    }
    ostream& Output(ostream& out)const
    {
        out << " Width: " << m_dWidth << " Area: " << Area() << " Perimeter: " << Perimeter() << endl;
        return out;
    }
    friend istream& operator>>(istream& in, CSquare& obj)
    {
        in >> obj.m_dWidth;
        return in;
    }
    friend ostream& operator<<(ostream& out, CSquare& obj)
    {
        out << obj.m_dWidth;
    }
    istream& Input(istream& in)
    {
        in >> m_dWidth;
        return in;
    }
};
class CCircle :public CGraphicObject
{
private:
    double m_dRadius;
public:
    CCircle()
    {
        m_dRadius = 0;
    }
    CCircle(const double radius)
    {
        m_dRadius = radius;
    }
    double Area()const
    {
        return (PI * m_dRadius * m_dRadius);
    }
    double Perimeter()const
    {
        return (2* PI * m_dRadius);
    }
    ostream& Output(ostream& out)const
    {
        out << " Radius: " << m_dRadius << " Area: " << Area() << " Circumference: " << Perimeter() << endl;
        return out;
    }
    friend istream& operator>>(istream& in, CCircle& obj)
    {
        in >> obj.m_dRadius;
        return in;
    }
    istream& Input(istream& in)
    {
        in >> m_dRadius;
        return in;
    }
};
class CTriangle :public CGraphicObject
{
private:
    double m_dSideA;
    double m_dSideB;
    double m_dSideC;
public:
    CTriangle()
    {
        m_dSideA = 0;
        m_dSideB = 0;
        m_dSideC = 0;
    }
    CTriangle(const double A, const double B, const double C)
    {
        m_dSideA = A;
        m_dSideB = B;
        m_dSideC = C;
    }
    double Area()const
    {
        double p = Perimeter() / 2;
        return (sqrt(p*(p-m_dSideA) * (p - m_dSideB) * (p - m_dSideC)));
    }
    double Perimeter()const
    {
        return (m_dSideA + m_dSideB + m_dSideC);
    }
    ostream& Output(ostream& out)const
    {
        out << " A: " << m_dSideA << " B: " << m_dSideB << " C: " << m_dSideC << " Area: " << Area() << " Perimeter: " << Perimeter() << endl;
        return out;
    }
    friend istream& operator>>(istream& in, CTriangle& obj)
    {
        in >> obj.m_dSideA >> obj.m_dSideB >> obj.m_dSideC;
        return in;
    }
    istream& Input(istream& in)
    {
        in >> m_dSideA >> m_dSideB >> m_dSideC;
        return in;
    }
};


class CGraphicObjectsSet {
private:
    vector<CGraphicObject*> m_vObjects;
    double rand()
    {

        uniform_real_distribution<double> unif(0, 100);
        default_random_engine re(chrono::system_clock::now().time_since_epoch().count());
        return unif(re);

    }
public:
    CGraphicObjectsSet()
    {

        m_vObjects.emplace_back(new CRectangle(rand(), rand()));
        m_vObjects.emplace_back(new CSquare(rand()));
        m_vObjects.emplace_back(new CCircle(rand()));
        m_vObjects.emplace_back(new CTriangle(rand(), rand(),rand()));

    }
    CGraphicObjectsSet(const string& f)
    {
        ifstream file(f);
        if (file.good())
        {
            while (!(file.peek() == EOF))
            {
                int type;
                file >> type;
                switch ((CGraphicObjectType)type)
                {
                case Rectangle:
                {
                    m_vObjects.emplace_back(new CRectangle);
                    m_vObjects.back()->Input(file);
                    break;
                }
                case Square:
                {
                    m_vObjects.emplace_back(new CSquare);
                    m_vObjects.back()->Input(file);
                    break;
                }
                case Circle:
                {
                    m_vObjects.emplace_back(new CCircle);
                    m_vObjects.back()->Input(file);
                    break;
                }
                case Triangle:
                {
                    m_vObjects.emplace_back(new CTriangle);
                    m_vObjects.back()->Input(file);
                    break;
                }
                default: break;
                }
            }
        }
        file.close();
    }
    CGraphicObjectsSet(const vector<CGraphicObject*>& cont)
    {
        m_vObjects = cont;
    }
    void ReadIn(istream& in)
    {
        while (!(in.peek() == EOF))
        {
            int type;
            in >> type;
            switch ((CGraphicObjectType)type)
            {
            case Rectangle:
            {
                m_vObjects.emplace_back(new CRectangle);
                m_vObjects.back()->Input(in);
                break;
            }
            case Square:
            {
                m_vObjects.emplace_back(new CSquare);
                m_vObjects.back()->Input(in);
                break;
            }
            case Circle:
            {
                m_vObjects.emplace_back(new CCircle);
                m_vObjects.back()->Input(in);
                break;
            }
            case Triangle:
            {
                m_vObjects.emplace_back(new CTriangle);
                m_vObjects.back()->Input(in);
                break;
            }
            default: break;
            }
        }

    }
    void WriteTo(ostream& out)
    {
        for (int i=0;i<m_vObjects.size();i++)
        {
            m_vObjects[i]->Output(out);
        }
    }
    double TotalArea()
    {
        double sum = 0;
        for(int i=0;i<m_vObjects.size();i++)
        {
            sum+=m_vObjects[i]->Area();
        }
        return sum;
    }
    double TotalPerimeter()
    {
        double sum = 0;
        for (int i = 0; i < m_vObjects.size(); i++)
        {
            sum += m_vObjects[i]->Perimeter();
        }
        
        return sum;
    }
};


int main()
{

    CGraphicObjectsSet set1("f.txt"),set2;
    cout << set1.TotalPerimeter() << endl;
    cout << set1.TotalArea()<<endl;
    set1.WriteTo(cout);
    ifstream file("f.txt");
    set2.ReadIn(file);
    set2.WriteTo(cout);
    
}