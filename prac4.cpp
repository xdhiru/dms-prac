#include <iostream>
#include <conio.h>
using namespace std;

const int maxN = 10;

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
    int ans[maxN] = {0};
    while (1)
    {
        int sum = 0;
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
        while (i >= 0 && ans[i] == C)
        {
            ans[i] = 0;
            i--;
        }
        if (i < 0)
        {
            break;
        }
        ans[i]++;
    }
    return 0;
}