#include <iostream>  
using namespace std;  
int main()  
{  
int n,num=0,m;    
cout<<"Enter a number: ";    
cin>>n;    
while(n>0)    
{    
m=n%10;    
num=num+m;    
n=n/10;    
}    
cout<<"Sum is= "<<num<<endl;    
return 0;  
} 
