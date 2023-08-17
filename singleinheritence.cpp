//Implement Single Inheritance.

#include <iostream>
using namespace std;

class shape{
  public: 
  float length, breadth;
  void acceptValues();
};

class rectangle : public shape{
  public:
  float area();
  void displayValues();
};

void shape :: acceptValues(){
  cout<<"\nEnter length and breadth: ";
  cin>>length>>breadth;
}

float rectangle :: area(){
    return (length*breadth);
  }

void rectangle :: displayValues(){
    cout<<"\nLength: "<<length;
    cout<<"\nBreadth: "<<breadth;
  }

int main() {
  rectangle r1;
  r1.acceptValues();
  r1.displayValues();
  cout<<"\nArea is: "<<r1.area();
}
