#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout<<"Enter the highest degree of n :";
    int length;
    cin>>length;
    float coeff[length], total = 0;
    for (int i = 0; i <= length; i++)
    {
        cout<<"Enter coefficient of n^"<<i<<" : ";
        cin>>coeff[i];
    }
    float n;
    cout<<"Enter value of n : ";
    cin>>n;
    for (int i = 0; i <= sizeof(coeff)/sizeof(coeff[0]); i++)
    {
        total += coeff[i] * pow(n, i);
    }
    cout << "f(" << n << ") = " << total << endl;
    return 0;
}
