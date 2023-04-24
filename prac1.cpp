#include <iostream>
using namespace std;

class Set
{
    int number; // set number (like a name for the set)
    int size;   // size= number of elements in the set
    int *set;   // the set array itself
    void remove_duplicate_elements();

public:
    void create_set(int set_number);
    void output_set();
    bool is_member(int element);
    bool is_subset(Set set_2);
    void power_set(); // void because it needs 2d array? so just printed.
    Set set_union(Set set_2);
    Set set_intersection(Set set_2);
    Set set_difference(Set set_2);
    Set set_symmetric_difference(Set set_2);
    void set_cartesian_product(Set set_2); // void because it needs 2d array? so just printed.
};
void Set::create_set(int set_number)
{
    number = set_number;
    cout << "\nEnter number of elements in set " << number << " : ";
    cin >> size;
    set = new int[size];
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
bool Set::is_member(int element)
{
    for (int i = 0; i < size; i++)
    {
        if (set[i] == element)
        {
            return true;
        }
    }
    return false;
}
bool Set::is_subset(Set set_2)
{
    for (int i = 0; i < set_2.size; i++)
    {
        if (!is_member(set_2.set[i]))
        {
            return false;
        }
    }
    return true;
}
void Set::output_set()
{
    cout << " {";
    for (int i = 0; i < size; i++)
    {
        cout << set[i] << ",";
    }
    cout << "}";
}
void Set::power_set()
{
    cout << "{ {}, ";
    for (int counter = 1; counter < 1 << size; counter++)
    {
        cout << "{";
        for (int j = 0; j < size; j++)
        {
            if ((counter & (1 << j)) != 0)
            {
                cout << set[j] << ",";
            }
        }
        cout << "}, ";
    }
    cout << " }\n";
}
Set Set::set_union(Set set_2)
{
    Set union_set;
    union_set.set = new int[size + set_2.size];
    union_set.size = 0;
    for (int i = 0; i < size; i++)
    {
        union_set.set[union_set.size++] = set[i];
    }
    for (int j = 0; j < set_2.size; j++)
    {
        union_set.set[union_set.size++] = set_2.set[j];
    }
    union_set.remove_duplicate_elements();
    return union_set;
}
Set Set::set_intersection(Set set_2)
{
    Set intersection_set;
    intersection_set.size = 0;
    for (int i = 0; i < size; i++)
    {
        if (set_2.is_member(set[i]))
        {
            intersection_set.size++;
        }
    }
    intersection_set.set = new int[intersection_set.size];
    intersection_set.size = 0;
    for (int i = 0; i < size; i++)
    {
        if (set_2.is_member(set[i]))
        {
            intersection_set.set[intersection_set.size++] = set[i];
        }
    }
    return intersection_set;
}
Set Set::set_difference(Set set_2)
{
    Set difference_set;
    difference_set.size = size;
    for (int i = 0; i < set_2.size; i++)
    {
        if (is_member(set_2.set[i]))
        {
            difference_set.size--;
        }
    }
    difference_set.set = new int[difference_set.size];
    difference_set.size = 0;
    for (int j = 0; j < size; j++)
    {
        if (!set_2.is_member(set[j]))
        {
            difference_set.set[difference_set.size++] = set[j];
        }
    }
    return difference_set;
}
Set Set::set_symmetric_difference(Set set_2)
{
    Set symmetric_difference_set = (set_union(set_2)).set_difference(set_intersection(set_2));
    return symmetric_difference_set;
}
void Set::set_cartesian_product(Set set_2)
{
    cout << "{";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < set_2.size; j++)
        {
            cout << "{" << set[i] << "," << set_2.set[j] << "}";
        }
        cout << ",";
    }
    cout << "}";
}
int main()
{
    Set set1, set2;
    set1.create_set(1);
    set2.create_set(2);
    int menu_option = 0;
    while (1)
    {
        cout << "\n========================\nSet 1 : ";
        set1.output_set();
        cout << "\nSet 2 : ";
        set2.output_set();
        cout << "\n==========MENU==========\n0) Exit." << endl;
        cout << "1) Check whether an element belongs to the set or not.\n"; // done
        cout << "2) List all the elements of the power set of a set.\n";
        cout << "3) Check whether one set is a subset of the other or not.\n"; // done
        cout << "4) Union and Intersection of two Sets.\n";                    // done
        cout << "5) Complement: Assume Universal Set as per the input elements from the user.\n";
        cout << "6) Set Difference and Symmetric Difference between two sets.\n";
        cout << "7) Cartesian Product of Sets. \nChoose an option (0-7):";
        cin >> menu_option;
        switch (menu_option)
        {
        case (0):
            cout << "====================\nThanks!";
            exit(0);
            break;
        case (1):
            int set_choice, element1;
            cout << "====================\nWhich set to search element in:";
            cin >> set_choice;
            cout << "Enter an element to check in set " << set_choice << " : ";
            cin >> element1;
            if (set_choice == 1)
            {
                if (set1.is_member(element1))
                {
                    cout << "Element " << element1 << " belongs to ";
                    set1.output_set();
                }
                else
                {
                    cout << "Element " << element1 << " does not belong to ";
                    set1.output_set();
                }
            }
            else if (set_choice == 2)
            {
                if (set2.is_member(element1))
                {
                    cout << "Element " << element1 << " belongs to ";
                    set2.output_set();
                }
                else
                {
                    cout << "Element " << element1 << " does not belong to ";
                    set2.output_set();
                }
            }
            break;
        case (2):
            cout << "Which set to list power set of:";
            cin >> set_choice;
            if (set_choice == 1)
            {
                cout << "====================\nThe power set of set 1 is :\n";
                set1.power_set();
            }
            else if (set_choice == 2)
            {
                cout << "====================\nThe power set of set 2 is :\n";
                set2.power_set();
            }
            break;
        case (3):
            if (set2.is_subset(set1))
            {
                cout << "====================\nset1 :";
                set1.output_set();
                cout << " is a subset of ";
                cout << "set2 :";
                set2.output_set();
            }
            else
            {
                cout << "====================\nset1 :";
                set1.output_set();
                cout << " is not a subset of ";
                cout << "set2 :";
                set2.output_set();
            }
            cout << endl;
            if (set1.is_subset(set2))
            {
                cout << "set2 :";
                set2.output_set();
                cout << " is a subset of ";
                cout << "set1 :";
                set1.output_set();
            }
            else
            {
                cout << "set2 :";
                set2.output_set();
                cout << " is not a subset of ";
                cout << "set1 :";
                set1.output_set();
            }
            break;
        case (4):
            cout << "========================\nThe union_set is: ";
            (set1.set_union(set2)).output_set();
            cout << "\nThe intersection_set is: ";
            (set1.set_intersection(set2)).output_set();
            break;
        case (5):
            Set universal_set;
            cout << "====================\nPlease provide the universal set to find complement of set 1 & set 2:";
            universal_set.create_set(3);
            cout << "\n====================\nComplement of Set 1 : ";
            set1.output_set();
            cout << " is = ";
            (universal_set.set_difference(set1)).output_set();
            cout << "\n\nComplement of Set 2 : ";
            set2.output_set();
            cout << " is = ";
            (universal_set.set_difference(set2)).output_set();
            break;
        case (6):
            cout << "\n========================\nSet Difference : ";
            cout << "\nSet 1 - Set 2 :\n";
            set1.output_set();
            cout << " - ";
            set2.output_set();
            cout << " = ";
            (set1.set_difference(set2)).output_set();
            cout << "\n\nSet 2 - Set 1 :\n";
            set2.output_set();
            cout << " - ";
            set1.output_set();
            cout << " = ";
            (set2.set_difference(set1)).output_set();
            cout << "\n========================\nSet Symmetric Difference : ";
            cout << "\nSet 1 (+) Set 2 : ";
            set1.output_set();
            cout << " (+) ";
            set2.output_set();
            cout << " = ";
            (set1.set_symmetric_difference(set2)).output_set();
            break;
        case (7):
            cout << "\n========================\nCartesian Product : ";
            cout << "\nSet 1 x Set 2 : ";
            set1.output_set();
            cout << " x";
            set2.output_set();
            cout << " = " << endl;
            set1.set_cartesian_product(set2);
            break;
        }
    }
    return 0;
}