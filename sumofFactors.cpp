#include <iostream>

using namespace std;

int main() {

  int x, sum = 0, counter;

  cout<<"\nEnter an integer: ";
  cin>>x;

  for(counter = 1; counter<x; counter++)
  {
    if(x%counter == 0)
    {
      sum = sum + counter;
    }
  }

  cout<<"\nSum of Factors: "<<sum;
}
