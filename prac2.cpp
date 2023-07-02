#include <iostream>
using namespace std;

class Relation
{
public:
    int *set1, set_element_count;;
    int **mat;
    int *relation,relation_element_count;
    Relation()
    {
        inputSet();
        displaySet();
        inputRelation();
        removeDuplicates();
        displayRelation();
        createMatrix();
        fillMatrix();
        displayMatrix();
        if (isReflexive())
        {
            cout << "\nThe relation is reflexive" << endl;
        }
        else
        {
            cout << "\nThe relation is not reflexive" << endl;
        }
    }
    void inputSet(){
        cout << "Enter the numebr of elements of set over which relation is defined:";
        cin >> set_element_count;
        set1 = new int[set_element_count];
        for (int i = 0; i < set_element_count; i++)
        {
            cout << "Enter element " << i + 1 << " of the set :";
            cin >> set1[i];
        }
    }
    void displaySet(){
        cout << "Entered set : {";
        for (int i = 0; i < set_element_count; i++)
        {
            cout << set1[i] << ", ";
        }
        cout << " }\n";
    }
    void inputRelation(){
        cout << "Enter number of elements in the relation :";
        cin >> relation_element_count;
        relation = new int[relation_element_count];
        for (int i = 0; i < relation_element_count * 2; i += 2)
        {
            cout << "Enter value 1 of element " << i / 2 + 1 << " : ";
            cin >> relation[i];
            cout << "Enter value 2 of element " << i / 2 + 1 << " : ";
            cin >> relation[i + 1];
        }
    }
    void displayRelation()
    {
        cout << "Entered relation is : " << endl;
        cout << "{ ";
        for (int i = 0; i < relation_element_count * 2; i += 2)
        {
            cout << "{" << relation[i] << "," << relation[i + 1] << "}, ";
        }
        cout << " }" << endl;
    }
    void removeDuplicates()
    {
        for (int i = 0; i < relation_element_count * 2; i += 2)
        {
            for (int j = i + 2; j < relation_element_count * 2; j += 2)
            {
                if (relation[i] == relation[j] && relation[i + 1] == relation[j + 1])
                {
                    for (int k = j; k < relation_element_count * 2; k += 2)
                    {
                        relation[k] = relation[k + 2];
                        relation[k + 1] = relation[k + 3];
                        relation_element_count--;
                        j -= 2;
                        i -= 2;
                    }
                }
            }
        }
    }
    void createMatrix()
    {
        mat = new int *[set_element_count];
        for (int i = 0; i < set_element_count; i++)
        {
            mat[i] = new int[set_element_count];
            for (int j = 0; j < set_element_count; j++)
            {
                mat[i][j] = 0;
            }
        }
    }
    void fillMatrix()
    {
        int x, y;
        for (int i = 0; i < relation_element_count * 2; i += 2)
        {
            x = relation[i];
            y = relation[i + 1];
            mat[x][y] = 1;
        }
    }
    void displayMatrix()
    {
        cout << "   ";
        for (int i = 0; i < set_element_count; i++)
        {
            cout << set1[i] << ", ";
        }
        cout << endl
             << "__";
        for (int i = 0; i < set_element_count; i++)
        {
            cout << "___";
        }
        cout << endl;
        for (int i = 0; i < set_element_count; i++)
        {
            cout << set1[i] << " |";
            for (int j = 0; j < set_element_count; j++)
            {
                cout << mat[i][j] << ", ";
            }
            cout << endl;
        }
    }
    bool isReflexive()
    {
        for (int i = 0; i < set_element_count; i++)
        {
            if (!mat[i][i])
            {
                return 0;
            }
        }
        return 1;
    }
    bool isTransitive()
    {
        for (int i = 0; i < set_element_count; i++)
        {
            for (int j = 0; j < set_element_count; j++)
            {
                if (mat[i][j] == 1)
                {
                    for (int k = 0; k < set_element_count; k++)
                    {
                        if (mat[j][k] == 1 && mat[i][k] != 1)
                        {
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
};

int main()
{
    Relation R;
    return 0;
}