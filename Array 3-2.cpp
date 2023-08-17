/*
WAP to find maximum and minimum from all array elements. 
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

//to find max and min
int findMax(int a[], int size){
  int max = a[0]; //Assuming that a[0] is MAXIMUM
  for(int i=1; i<size; i++){
      if(max < a[i]){ 
        max = a[i];
      }
  }
  return max;
}

int findMin(int a[], int size){
  int min = a[0]; //Assuming that a[0] is MINIMUM
  for(int i=1; i<size; i++){
      if(min > a[i]){ 
        min = a[i];
      }
  }
  return min;
}



int main() {
  int a[10], size = 10, i;
  //Accept Array a
  cout<<"\nEnter elements for Array a: \n";
  acceptArray(a, size);

  //Print Array accept
  cout<<"\n\nGiven array is: \n";
  printArray(a, size);

  cout<<"\nMax = "<<findMax(a, size);
  cout<<"\nMin = "<<findMin(a, size);

}
