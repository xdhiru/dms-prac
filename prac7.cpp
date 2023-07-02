// Q7. Write a Program to check if a given graph is a complete graph. Represent the graph using the Adjacency List representation.
#include <iostream>
#include <conio.h>
using namespace std;
class Graph
{
public:
	int vertices = 0;
	int **mat;
	Graph()
	{
		cout << "Enter no. of vertices in the undirected graph : ";
		cin >> vertices;
		if (vertices < 1)
		{
			cout << "Vertices in the graph cannot be less than 1." << endl;
			cout << "Press enter key to exit..";
			getch();
			exit(0);
		}
		mat = new int *[vertices];
		for (int i = 0; i < vertices; i++)
		{
			mat[i] = new int[vertices];
			for (int j = 0; j < vertices; j++)
			{
				mat[i][j] = 0;
			}
		}
		for (int i = 0; i < vertices; i++)
		{
			int d = 0;
			cout << "Enter degree of vertex " << i << " : ";
			cin >> d;
			for (int j = 0; j < d;)
			{
				int y;
				cout << "Enter index of adjacent vertex " << j + 1 << "(out of " << d << ") for vertex " << i << " : ";
				cin >> y;
				if (y > vertices - 1)
				{
					cout << "Vertex index cannot be greater than total vertices!" << endl;
					cout << "Press enter key to exit..";
					getch();
					exit(0);
				}
				mat[i][y] += 1;
                if (i == y) 
                {
                    j += 2;        //self loop counts as degree 2
                }
                else
                {
                    j++;
                }
			}
		}
		if (checkGraph())
		{
			cout << "\nGraph was entered successfully!" << endl;
		}
		else
		{
			cout << "\nGraph has irregularity in the degrees of entered vertices. Please recheck and try entering again! " << endl;
			cout << "Press enter key to exit..";
			getch();
			exit(0);
		}
		if (checkComplete())
		{
			cout << "\nEntered graph is a complete graph." << endl;
		}
		else
		{
			cout << "\nEntered graph is not a complete graph." << endl;
		}
		displayAdjList();
	}
	bool checkGraph()
	{

		for (int i = 0; i < vertices; i++)
		{
			int x_sum = 0, y_sum = 0;
			for (int j = 0; j < vertices; j++)
			{
				x_sum += mat[i][j];
				y_sum += mat[j][i];
			}
			if (x_sum != y_sum)
			{
				return 0;
			}
		}
		return 1;
	}
	bool checkComplete()
	{
		for (int i = 0; i < vertices; i++)
		{
			for (int j = 0; j < vertices; j++)
			{
				if (i == j && mat[i][j] != 0)
				{
					cout << "Self loop found!" << endl;
					return 0;
				}
				if (mat[i][j] > 1)
				{
					cout << "Multiple edges found between same vertices!" << endl;
					return 0;
				}
				if (i != j && mat[i][j] != 1)
				{
					cout << "Some vertices are not connected to the others!" << endl;
					return 0;
				}
			}
		}
		return 1;
	}
	void displayMatrix()
	{
		cout << "\nThe Adjacency Matrix is :\n";
		cout << "|    |";
		for (int i = 0; i < vertices; i++)
		{
			cout << " V" << i << "|";
		}
		cout << endl;
		for (int i = 0; i < vertices; i++)
		{
			cout << "| V" << i;
			for (int j = 0; j < vertices; j++)
			{
				cout << " | " << mat[i][j];
			}
			cout << " | " << endl;
		}
	}
	void displayAdjList()
	{
		cout << "\nThe adjacency list is : " << endl;
		cout << "_______________________________________________________" << endl;
		cout << "|    Vertex   |            Adjacent Vertices           |" << endl;
		cout << "_______________________________________________________" << endl;
		for (int i = 0; i < vertices; i++)
		{
			cout << "|     V" << i << "     |     ";
			for (int j = 0; j < vertices; j++)
			{
				while (mat[i][j] != 0)
				{

					cout << "V" << j << ", ";
					mat[i][j] -= 1;
				}
			}
			cout << endl;
		}
		cout << "_______________________________________________________" << endl;
	}
};
int main()
{
	Graph G;
	return 0;
}