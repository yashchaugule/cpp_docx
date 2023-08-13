/*
WAP to find sum and average of elements
*/

#include <iostream>

using namespace std;


//Function to accept 2D Array
void acceptArray(int a[3][3]){
  for(int i=0; i<3; i++){ //will track row
    for(int j=0; j<3; j++){  // will track column
      cout<<"Enter value: ";
      cin>>a[i][j];
    }
  }
}


int main() {
  //Array Declaration
  int a[3][3], max, min;

  //Calling the functions
  acceptArray(a);


  //Finding max and min
  max = min = a[0][0];
  //Assuming that a[0][0] is max as well as min value
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      if(max < a[i][j]){
        max = a[i][j];
      }
      if(min > a[i][j]){
        min = a[i][j];
      }    
    }
  }

cout<<"\nMax = "<<max;
cout<<"\nMin = "<<min;

}
