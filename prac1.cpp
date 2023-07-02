#include <iostream>
using namespace std;

class Set
{
    char name; // set name (name for the set)
    int size;  // size= number of elements in the set
    int *set;  // the set array itself

public:
    void initSet(char _name)
    {
        name = _name;
        cout << "\nEnter number of elements in set " << name << " : ";
        cin >> size;
        set = new int[size];
        for (int i = 0; i < size; i++)
        {
            cout << "Enter the element at position " << i + 1 << " : ";
            cin >> set[i];
        }
        distinct();
        output();
    }
    void distinct()
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
    bool isMember(int element)
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
    bool isSubset(Set set_2)
    {
        for (int i = 0; i < set_2.size; i++)
        {
            if (!isMember(set_2.set[i]))
            {
                return false;
            }
        }
        return true;
    }
    void output()
    {
        cout << " {";
        for (int i = 0; i < size; i++)
        {
            cout << set[i] << ",";
        }
        cout << "}";
    }
    void powerSet()
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
    Set setUnion(Set set_2)
    {
        Set result;
        result.set = new int[size + set_2.size];
        result.size = 0;
        for (int i = 0; i < size; i++)
        {
            result.set[result.size++] = set[i];
        }
        for (int j = 0; j < set_2.size; j++)
        {
            result.set[result.size++] = set_2.set[j];
        }
        result.distinct();
        return result;
    }
    Set setIntersection(Set set_2)
    {
        Set result;
        result.size = 0;
        for (int i = 0; i < size; i++)
        {
            if (set_2.isMember(set[i]))
            {
                result.size++;
            }
        }
        result.set = new int[result.size];
        result.size = 0;
        for (int i = 0; i < size; i++)
        {
            if (set_2.isMember(set[i]))
            {
                result.set[result.size++] = set[i];
            }
        }
        return result;
    }
    Set setDifference(Set set_2)
    {
        Set result;
        result.size = size;
        for (int i = 0; i < set_2.size; i++)
        {
            if (isMember(set_2.set[i]))
            {
                result.size--;
            }
        }
        result.set = new int[result.size];
        result.size = 0;
        for (int j = 0; j < size; j++)
        {
            if (!set_2.isMember(set[j]))
            {
                result.set[result.size++] = set[j];
            }
        }
        return result;
    }
    Set setSymmetricDifference(Set set_2)
    {
        Set result = (setUnion(set_2)).setDifference(setIntersection(set_2));
        return result;
    }
    void setCartesianProduct(Set set_2)
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
};
char menu()
{
    cout << "\n==========MENU==========\n";
    cout << "1) Check whether an element belongs to the set or not.\n"; // done
    cout << "2) List all the elements of the power set of a set.\n";
    cout << "3) Check whether one set is a subset of the other or not.\n"; // done
    cout << "4) Union and Intersection of two Sets.\n";                    // done
    cout << "5) Complement: Assume Universal Set as per the input elements from the user.\n";
    cout << "6) Set Difference and Symmetric Difference between two sets.\n";
    cout << "7) Cartesian Product of Sets. \n";
    cout << "8) Exit.\n";
    cout << "Choose an option (1-8):";
    char choice;
    cin >> choice;
    return choice;
}
int main()
{
    Set set1, set2;
    set1.initSet('1');
    set2.initSet('2');
    cout << "\n========================\nSet 1 : ";
    set1.output();
    cout << "\nSet 2 : ";
    set2.output();
    char menu_option;
    do
    {
        menu_option = menu();
        switch (menu_option)
        {
        case ('1'):
            int set_choice, element1;
            cout << "====================\nWhich set to search element in (1/2):";
            cin >> set_choice;
            cout << "Enter an element to check in set " << set_choice << " : ";
            cin >> element1;
            if (set_choice == 1)
            {
                if (set1.isMember(element1))
                {
                    cout << "Element " << element1 << " belongs to ";
                    set1.output();
                }
                else
                {
                    cout << "Element " << element1 << " does not belong to ";
                    set1.output();
                }
            }
            else if (set_choice == 2)
            {
                if (set2.isMember(element1))
                {
                    cout << "Element " << element1 << " belongs to ";
                    set2.output();
                }
                else
                {
                    cout << "Element " << element1 << " does not belong to ";
                    set2.output();
                }
            }
            break;
        case ('2'):
            cout << "Which set to list power set of (1/2):";
            cin >> set_choice;
            if (set_choice == 1)
            {
                cout << "====================\nThe power set of set 1 is :\n";
                set1.powerSet();
            }
            else if (set_choice == 2)
            {
                cout << "====================\nThe power set of set 2 is :\n";
                set2.powerSet();
            }
            break;
        case ('3'):
            if (set2.isSubset(set1))
            {
                cout << "====================\nset1 :";
                set1.output();
                cout << " is a subset of set2 :";
                set2.output();
            }
            else
            {
                cout << "====================\nset1 :";
                set1.output();
                cout << " is not a subset of set2 :";
                set2.output();
            }
            cout << endl;
            if (set1.isSubset(set2))
            {
                cout << "set2 :";
                set2.output();
                cout << " is a subset of set1 :";
                set1.output();
            }
            else
            {
                cout << "set2 :";
                set2.output();
                cout << " is not a subset of set1 :";
                set1.output();
            }
            break;
        case ('4'):
            cout << "========================\nThe union set is: ";
            (set1.setUnion(set2)).output();
            cout << "\nThe intersection set is: ";
            (set1.setIntersection(set2)).output();
            break;
        case ('5'):
            Set universal_set;
            cout << "====================\nPlease provide the universal set to find complement of set 1 & set 2:";
            universal_set.initSet('3');
            cout << "\n====================\nComplement of Set 1 : ";
            set1.output();
            cout << " is = ";
            (universal_set.setDifference(set1)).output();
            cout << "\n\nComplement of Set 2 : ";
            set2.output();
            cout << " is = ";
            (universal_set.setDifference(set2)).output();
            break;
        case ('6'):
            cout << "\n========================\nSet Difference : ";
            cout << "\nSet 1 - Set 2 :\n";
            set1.output();
            cout << " - ";
            set2.output();
            cout << " = ";
            (set1.setDifference(set2)).output();
            cout << "\n\nSet 2 - Set 1 :\n";
            set2.output();
            cout << " - ";
            set1.output();
            cout << " = ";
            (set2.setDifference(set1)).output();
            cout << "\n========================\nSet Symmetric Difference : ";
            cout << "\nSet 1 (+) Set 2 : ";
            set1.output();
            cout << " (+) ";
            set2.output();
            cout << " = ";
            (set1.setSymmetricDifference(set2)).output();
            break;
        case ('7'):
            cout << "\n========================\nCartesian Product : ";
            cout << "\nSet 1 x Set 2 : ";
            set1.output();
            cout << " x";
            set2.output();
            cout << " = " << endl;
            set1.setCartesianProduct(set2);
            break;
        default:
            if (menu_option != '8')
            {
                cout << "Invalid option entered! Please re-enter.";
            }
        }
    } while (menu_option != '8');
    cout << "\n====================\nExiting Program!";
    return 0;
}