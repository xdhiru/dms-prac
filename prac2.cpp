#include <iostream>
using namespace std;

class Relation
{
public:
    int element_count,biggest_entry;
    int arr[2][100];
    Relation()
    {
        cout << "Enter number of elements in relation : ";
        cin >> element_count;
        cout << endl;
        for (int i = 0; i < element_count;)
        {
            cout << "Enter  element" << ++i << " of the relation :";
            cin >> arr[0][i] >> arr[1][i];
            if (arr[0][i]>biggest_entry) biggest_entry=arr[0][i];
            if (arr[1][i]>biggest_entry) biggest_entry=arr[1][i];
            cout << endl;
        }
        cout<<"Entered relation is : ";display_relation();
        // matrix[biggest_entry][biggest_entry];
    }
    void display_relation()
    {   cout<<"{";
        for (int i = 0; i < element_count; i++)
        {
            cout << "("<< arr[0][i] << ", " << arr[1][i] << "), ";
        }
        cout<<"}";
    }
    
};
int main()
{
    Relation a = Relation();
    return 0;
}