#include <iostream>

using namespace std;

class shape
{
  public:
   float length, breadth;
  void acceptValues()
  {
    cout<<"Enter length:";
    cin>>length;
    cout<<"Enter breadth:";
    cin>>breadth;
  }
};

class color
{
  public:
   float cost;
  void acceptcost()
  {
    cout<<"Enter cost:";
    cin>>cost;
  }
};

class rectangle:public shape,public color
{
  public:
   float area();
   {return (length*breadth);}
  void display()
  {
    cout<<"Length:"<<length;
    cout<<"Breadth:"<<breadth;
    cout<<"Area:"<<area();
    cout<<"Total cost:"<<total cost();
  }
};
