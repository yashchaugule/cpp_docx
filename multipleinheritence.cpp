/*Implement 
Multiple 
Inheritance.*/
#include <iostream>
using namespace std;

class shape{
  public:
  float length, breadth;
  void acceptValues();
};

class color{
  public:
  float cost;
  void acceptCost();
};

class rectangle : public shape, public color{
  public:
  float area();
  float totalCost();
  void displayValues();
};

void shape :: acceptValues(){
  cout<<"\nEnter length and breadth: ";
  cin>>length>>breadth;
}

void color :: acceptCost(){
  cout<<"\nEnter cost: ";
  cin>>cost;
}

float rectangle :: area(){
  return (length*breadth);
}

float rectangle :: totalCost(){
  return (area() * cost);
}

void rectangle :: displayValues(){
  cout<<"\nLength: "<<length;
  cout<<"\nBreadth: "<<breadth;
  cout<<"\nArea: "<<area();
  cout<<"\nCost of coloring: "<<cost;
  cout<<"\nTotal Cost: "<<totalCost();
}


int main() {
  rectangle r1;
  r1.acceptValues();
  r1.acceptCost();
  r1.displayValues();
}
