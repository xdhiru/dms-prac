#include <iostream>
using namespace std;

class Set
{
    int size;
    int set[];
    void remove_duplicate_elements();
public:
    void create_set();
    void output_set();
    bool isMember(int j);
};

void Set::create_set()
{
    cout << "Enter number of elements in set: ";
    cin >> size;
    for (int i=0; i < size; i++)
    {
        cout << "Enter the element at position " << i+1 << " : ";
        cin >> set[i];
    }
    remove_duplicate_elements();
    output_set();
}
void Set::remove_duplicate_elements()
{
    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(set[i]==set[j])
            {
                for(int k=j;k<size-1;k++)
                {
                    set[k]=set[k+1];
                }
                size--;
                j--;
            }
        }
    }
}
bool Set::isMember(int j)
{
    for(int i=0;i<size;i++)
    {
        if(set[i]==j)
        {
            return true;
        }
    }
    return false;
}
void Set::output_set()
{
    cout<<"The set is :\n{";
    for(int i=0;i<size;i++)
    {
        cout<<set[i]<<",";
    }
    cout<<"}"<<endl;
}


int main()
{
    int element1;
    Set set1;
    set1.create_set();
    cout<<"Enter an element to check in set :";
    cin>>element1;
    cout<<set1.isMember(element1);

    return 0;
}