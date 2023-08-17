/*
Implement Bubble Sort
*/

#include <iostream>

using namespace std;

void acceptArray(int a[], int size){
  for(int i=0; i<size; i++){
    cout<<"Enter a value: ";
    cin>>a[i];
  }
}

void printArray(int a[], int size){
  for(int i=0; i<size; i++){
    cout<<a[i]<<"\t";
  }
}

void bubbleSort(int a[], int size){
  int i, j;
  for(i=0; i<size; i++){
    for(j=0; j<(size-i-1); j++){
      if(a[j] < a[j+1]){
        //swap
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }

}


int main() {

  int a[10], size = 10;

  cout<<"\nEnter elements of the array: \n";
  acceptArray(a, size);

  cout<<"\nOriginal Array: ";
  printArray(a, size);

  bubbleSort(a, size);
  
  cout<<"\nSorted Array: ";
  printArray(a, size);
} 
