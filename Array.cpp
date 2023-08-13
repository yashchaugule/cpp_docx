/*
WAP to accept and print a 2D Array
*/

#include <iostream>

using namespace std;


//Function to accept 2D Array
void acceptArray(int a[3][3])
{
  for(int i=0; i<3; i++)
  { //will track row
    for(int j=0; j<3; j++)
    {  // will track column
      cout<<"Enter value: ";
      cin>>a[i][j];
    }
  }
}

//Function to print 2D Array
void printArray(int a[3][3])
{
  for(int i=0; i<3; i++){ //will track row
    for(int j=0; j<3; j++){  // will track column
      cout<<a[i][j]<<"\t";
    }
    cout<<endl;
  }
}

int main() {
  //Array Declaration
  int a[3][3];

  //Calling the functions
  acceptArray(a);
  printArray(a);

}
