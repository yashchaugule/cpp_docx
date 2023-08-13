#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter 3 nos:\n";
    cin >> a >> b >> c;
    if (a > b)
    {
        if (a > c)
        {
            cout << "Maximun is:" << a << endl;
        }
        else if (a < c)
        {
            cout << "Maximun is:" << c << endl;
        }
    }
    
    else if (b > a)   
    {
        if (b > c)
        {
            cout << "Maximun is:" << b << endl;
        }
        else if (b < c)
        {
            cout << "Maximun is:" << c << endl; 
        }
    }
}

