#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int n, C;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of C: ";
    cin >> C;
    if (n <= 0 || C < 0 || C > 10)
    {
        cout << "Invalid input! numbers cannot be negative, sum cannot be negative or >10 ." << endl;
        cout << "Press any key to exit...";
        getch();
        return 0;
    }
    cout << "Solutions found for the equation are :" << endl;
    int ans[10] = {0,0,0,0,0,0,0,0,0,0};
    int sum = 0;
    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            sum += ans[i];
        }
        if (sum == C)
        {
            for (int i = 0; i < n; i++)
            {
                cout << ans[i] << ",";
            }
            cout << endl;
        }
        int i = n - 1;
        while (i >= 0 && sum == C)
        {
            sum-=ans[i];
            ans[i] = 0;
            i--;
        }
        if (i < 0)
        {
            break;
        }
        ans[i]++;
        sum=0;
    }
    return 0;
}