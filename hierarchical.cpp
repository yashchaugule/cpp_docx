//Implement Hierarchical Inheritance.
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
};

class color: public shape{
  public:
  float cost;
  void acceptCost();
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

float color :: totalCost(){
  return (length * breadth * cost);
}

void color :: displayValues(){
  cout<<"\nLength: "<<length;
  cout<<"\nBreadth: "<<breadth;
  cout<<"\nArea: "<<length * breadth;
  cout<<"\nCost of coloring: "<<cost;
  cout<<"\nTotal Cost: "<<totalCost();
}

int main() {
  color r1;
  r1.acceptValues();
  r1.acceptCost();
  r1.displayValues();
}
