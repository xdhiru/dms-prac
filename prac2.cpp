#include <iostream>
using namespace std;

class Relation
{
public:
    int **mat, size;
    Relation()
    {
        createMatrix();
        displayMatrix();
        if (isReflexive()){
            cout<<"The relation is Reflexive Relation.\n";
        }else{
            cout<<"The relation is not Reflexive Relation.\n";
        }
        if (isSymmetric()){
            cout<<"The relation is Symmetric Relation.\n";
        }else{
            cout<<"The relation is not Symmetric Relation.\n";
        }
        if (isAntiSymmetric()){
            cout<<"The relation is Anti Symmetric Relation.\n";
        }else{
            cout<<"The relation is not Anti Symmetric Relation.\n";
        }
        if (isTransitive()){
            cout<<"The relation is Transitive Relation.\n";
        }else{
            cout<<"The relation is not Transitive Relation.\n";
        }
        if (isEquivalence()){
            cout<<"The relation is Equivalence Relation.\n";
        }else{
            cout<<"The relation is not Equivalece Relation.\n";
        }
        if (isPartialOrder()){
            cout<<"The relation is Partial Order Relation.\n";
        }else{
            cout<<"The relation is not Partial Order Relation.\n";
        }
    }
    void createMatrix()
    {
        cout << "Enters size of matrix :";
        cin >> size;
        mat = new int *[size];
        for (int i = 0; i < size; i++)
        {
            mat[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                cout << "Enter value(0/1) at " << i << "," << j << " : ";
                cin >> mat[i][j];
            }
        }
    }
    void displayMatrix()
    {
        cout << "\nEntered matrix is: \n";
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << mat[i][j] << ", ";
            }
            cout << endl;
        }
    }
    bool isReflexive()
    {
        for (int i = 0; i < size; i++)
        {
            if (mat[i][i] != 1)
            {
                return 0;
            }
        }
        return 1;
    }
    bool isSymmetric()
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (mat[i][j] != mat[j][i])
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    bool isAntiSymmetric()
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (mat[i][j] == 1 && mat[j][i] == 1 && i != j)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    bool isTransitive()
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (mat[i][j] == 1)
                {
                    for (int k = 0; k < size; ++k)
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
    bool isEquivalence(){
        return isReflexive()&&isSymmetric()&&isTransitive();
    }
    bool isPartialOrder(){
        return isReflexive()&&isAntiSymmetric()&&isTransitive();
    }
};
int main()
{
    Relation R;
    return 0;
}