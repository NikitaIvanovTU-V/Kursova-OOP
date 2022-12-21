#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include "CRectangle.h"
#include "CSquare.h"
#include "CCircle.h"
#include "CTriangle.h"
#include <numeric>
#include <iterator>
#include <time.h>
using namespace std;
enum CGraphicObjectType
{
    Rectangle=2,
    Square,
    Circle,
    Triangle

};

class CGraphicObjectsSet {
private:
    vector<CGraphicObject*> m_vObjects;
    
public:
    CGraphicObjectsSet()
    {
    srand (time(NULL));
        m_vObjects.emplace_back(new CRectangle(rand()%100+1, rand()%100+1));
        m_vObjects.emplace_back(new CSquare(rand()%100+1));
        m_vObjects.emplace_back(new CCircle(rand()%100+1));
        CTriangle* temp=new CTriangle(rand() % 100+1, rand() % 100 + 1, rand() % 100 + 1);
        while (!temp->IsATriangle())
        {
            temp = new CTriangle(rand() % 100 + 1, rand() % 100 + 1, rand() % 100 + 1);
        }
       
        m_vObjects.emplace_back(temp);

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
        sum=accumulate(m_vObjects.begin(),m_vObjects.end(),0.0,CGraphicObject::SumArea);
        return sum;
    }
    double TotalPerimeter()
    {

        double sum = 0;
        sum=accumulate(m_vObjects.begin(),m_vObjects.end(),0.0,CGraphicObject::SumPerimeter);
        return sum;
    }
};


int main()
{

    CGraphicObjectsSet set1("f.txt"),set2;
    set1.WriteTo(cout);
        ifstream f("f.txt");
        set2.ReadIn(f);
        f.close();
        set2.WriteTo(cout);
        cout<<" Total Area: "<<set2.TotalArea() << endl;
        cout<< " Total Perimeter: " << set2.TotalPerimeter()<<endl;
    
   
}