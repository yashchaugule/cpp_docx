/*
WAP to accept and print an array (Using functions)
*/
#include <iostream>

using namespace std;

//Function to accept an array
void acceptArray(int a[], int size){
    for(int i=0; i<size; i++){
    cout<<"Enter a value: ";
    cin>>a[i];
  }
}

//Function to print an array
void printArray(int a[], int size){
  for(int i=0; i<size; i++){
    cout<<a[i]<<endl;
  }
}

int main() {
  int a[10], size = 10, i;

  //Accept Array a
  cout<<"\nEnter elements for Array a: \n";
  acceptArray(a, size);

  //Print Array accept
  cout<<"\n\nGiven array is: \n";
  printArray(a, size);
}
