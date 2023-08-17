//Implement Hybrid Inheritance

#include <iostream>
using namespace std;

class student{
  public:
  int rollno;
  float p, c, m;
  char name[80];

  void acceptDetails(){
    cout<<"\nEnter name: ";
    cin.getline(name, 80);
    cout<<"\nEnter roll number: ";
    cin>>rollno;
  }
};

class test: public student{
  public:
  void acceptMarks(){
      cout<<"\nEnter marks for pcm: ";
      cin>>p>>c>>m;
  }
};

class sports{
  public:
  float sp;
  void acceptSportsMarks(){
    cout<<"\nEnter sports marks: ";
    cin>>sp;
  }
};

class result: public test, public sports{
  public:
  float total;
  float findTotal(){    
    total = p+c+m+sp;
    return total;
  }

  void displayValues(){
    cout<<"\nName: "<<name;
    cout<<"\nRoll Number: "<<rollno;
    cout<<"\nPhysics: "<<p;
    cout<<"\nChemistry: "<<c;
    cout<<"\nMaths: "<<m;
    cout<<"\nSports: "<<sp;
    cout<<"\nTotal Marks: "<<findTotal();
  }
};


int main() {
  result r1;
  r1.acceptDetails();
  r1.acceptMarks();
  r1.acceptSportsMarks();
  r1.displayValues();  
}
