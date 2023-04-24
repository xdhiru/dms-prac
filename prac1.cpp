#include <iostream>
using namespace std;

class Set
{
public:
    int number; //set number (like a name for the set)
    int size;   //size= number of elements in the set
    int *set;  //the set array itself
    void remove_duplicate_elements();


    void create_set(int set_number);
    void output_set();
    bool isMember();
    // void power_set();
    void set_union(Set x);
};

void Set::create_set(int set_number)
{
    number=set_number;
    
    cout << "Enter number of elements in set "<<number<<" : ";
    cin >> size;
    set= new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element at position " << i + 1 << " : ";
        cin >> set[i];
    }
    
    remove_duplicate_elements();
    
    output_set();
    
}
void Set::remove_duplicate_elements()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (set[i] == set[j])
            {
                for (int k = j; k < size - 1; k++)
                {
                    set[k] = set[k + 1];
                }
                size--;
                j--;
            }
        }
    }
}
bool Set::isMember()
{
    
    int element1;
    cout << "Enter an element to check in set "<<number<<" : ";
    cin >> element1;
    for (int i = 0; i < size; i++)
    {
        if (set[i] == element1)
        {
            return true;
        }
    }
    return false;
}
void Set::output_set()
{
    cout<<size<<"{ ";
    for (int i = 0; i < size; i++)
    {
        cout << set[i] << ",";
    }
    cout << "}" << endl;
}
// void Set::power_set()
// {
//     int subset_element_count;
//     for (int i=size;i>0;i--)
//     {
//         subset_element_count=size-i;
//         cout<<"{";
//         for (int j=0;j<subset_element_count;j++)
//         {
//             cout<<set[j];
//         }
//         cout<<"}";

//     }
    
    
// }

void Set::set_union(Set set_2)
{
    Set union_set;
    
    union_set.size=size+set_2.size;
    cout<<"################"<<union_set.size;
    union_set.set= new int[size+set_2.size];
    int k=0;
    for (int i=0;i<size;i++)
    {
        union_set.set[k++]=set[i];
    }
    for (int j=0;j<set_2.size;j++)
    {
        union_set.set[k++]=set[j];
    }
        cout<<"################"<<union_set.size;

    union_set.remove_duplicate_elements();
        cout<<"################"<<union_set.size;

    union_set.output_set();

}
int main()
{
    Set set1, set2;
    set1.create_set(1);
    set2.create_set(2);
    int menu_option=0;
    cout<<"set 1 size:"<<set1.size;
    while (1)
    {
        cout << "\n0) Exit." << endl;
        cout << "1) Check whether an element belongs to the set or not and return value as true/false.\n";
        cout << "2) List all the elements of the power set of a set.\n";
        cout << "3) Check whether one set is a subset of the other or not.\n";
        cout << "4) Union and Intersection of two Sets.\n";
        cout << "5) Complement: Assume Universal Set as per the input elements from the user.\n";
        cout << "6) Set Difference and Symmetric Difference between two sets.\n";
        cout << "7) Cartesian Product of Sets\nChoose an option (0-7):";
        cin >> menu_option;
        switch (menu_option)
        {
        case (0):
            exit(0);
            break;

        case (1):
            int set_choice;
            cout << "Which set to search element in:";
            cin >> set_choice;
            if (set_choice == 1)
            {
                cout << set1.isMember();
            }
            else if (set_choice == 2)
            {
                cout << set2.isMember();
            }
            break;
        // case(2):
        //     cout << "Which set to list power set of:";
        //     cin >> set_choice;
        //     if (set_choice == 1)
        //     {
        //         cout << "The power set of set 1 is :\n{ {}, ";
        //         set1.power_set();
        //     }
        //     else if (set_choice == 2)
        //     {
        //         cout << "The power set of set 2 is :\n{ {}, ";
        //         set2.power_set();
        //     }
        //     break;
        case(4):
            cout<<"The union_set is:";
            set1.set_union(set2);
            break;
        }
    }

    return 0;
}
