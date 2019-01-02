#include<iostream>
#include <list>
#include <stack>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Stubs for all functions
void Merge(int *a, int *b, int first, int middle, int last);
void MergeSort(int *a, int *b, int first, int last);
void previsit(int v);
void postvisit(int v);

//Variable declarations
int visStor[31][3];
int postVis[];
int preVis[];
int j = 0;
int clock1 = 1;
int classArray[31];
int switchCaseSort;

// Class to represent a graph
class Graph
{
	int V;
	list<int> *adj;
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);

public:
	Graph(int V);
	void addEdge(int v, int w);
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}

void Graph::topologicalSortUtil(int v, bool visited[],
	stack<int> &Stack)
{

	visStor[j][0] = j;
	j++;

	visited[v] = true;
	previsit(v);

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
		{
			topologicalSortUtil(*i, visited, Stack);

		}
	postvisit(v);

	Stack.push(v);

}

void Graph::topologicalSort()
{
	stack<int> Stack;

	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack);

	while (Stack.empty() == false)
	{
		int switchCase;
		switchCase = Stack.top();

		switch (switchCase)
		{
		case 0:
			cout << "Node = 0 : " << "M1390" << endl;
			break;
		case 1:
			cout << "Node = 1 : " << "M1591" << endl;
			break;
		case 2:
			cout << "Node = 2 : " << "C1470" << endl;
			break;
		case 3:
			cout << "Node = 3 : " << "M2330" << endl;
			break;
		case 4:
			cout << "Node = 4 : " << "C1480" << endl;
			break;
		case 5:
			cout << "Node = 5 : " << "M3320" << endl;
			break;
		case 6:
			cout << "Node = 6 : " << "C4350" << endl;
			break;
		case 7:
			cout << "Node = 7 : " << "C4390" << endl;
			break;
		case 8:
			cout << "Node = 8 : " << "C2440" << endl;
			break;
		case 9:
			cout << "Node = 9 : " << "C3380" << endl;
			break;
		case 10:
			cout << "Node = 10 : " << "C2320" << endl;
			break;
		case 11:
			cout << "Node = 11 : " << "C3330" << endl;
			break;
		case 12:
			cout << "Node = 12 : " << "C4300" << endl;
			break;
		case 13:
			cout << "Node = 13 : " << "C4345" << endl;
			break;
		case 14:
			cout << "Node = 14 : " << "C4365" << endl;
			break;
		case 15:
			cout << "Node = 15 : " << "C4353" << endl;
			break;
		case 16:
			cout << "Node = 16 : " << "C4310" << endl;
			break;
		case 17:
			cout << "Node = 17 : " << "C4340" << endl;
			break;
		case 18:
			cout << "Node = 18 : " << "C4315" << endl;
			break;
		case 19:
			cout << "Node = 19 : " << "C3190" << endl;
			break;
		case 20:
			cout << "Node = 20 : " << "C3335" << endl;
			break;
		case 21:
			cout << "Node = 21 : " << "C3345" << endl;
			break;
		case 22:
			cout << "Node = 22 : " << "C3381" << endl;
			break;
		case 23:
			cout << "Node = 23 : " << "C4490" << endl;
			break;
		case 24:
			cout << "Node = 24 : " << "C3370" << endl;
			break;
		case 25:
			cout << "Node = 25 : " << "C4320" << endl;
			break;
		case 26:
			cout << "Node = 26 : " << "C3350" << endl;
			break;
		case 27:
			cout << "Node = 27 : " << "C3385" << endl;
			break;
		case 28:
			cout << "Node = 28 : " << "C3360" << endl;
			break;
		case 29:
			cout << "Node = 29 : " << "C4370" << endl;
			break;
		case 30:
			cout << "Node = 30 : " << "C4355" << endl;
			break;
		}
		Stack.pop();
	}
}

void Merge(int *a, int *b, int firstElement, int middle, int lastElement)
{
	int Inc = 0;
	int comp1 = firstElement;
	int comp2 = firstElement;
	int comp3 = middle + 1;

	while ((comp1 <= middle) && (comp3 <= lastElement))
	{
		if (a[comp1] <= a[comp3])
		{
			b[comp2] = a[comp1];
			comp1++;
		}
		else
		{
			b[comp2] = a[comp3];
			comp3++;
		}
		comp2++;
	}
	if (comp1 > middle)
	{
		for (Inc = comp3; Inc <= lastElement; Inc++)
		{
			b[comp2] = a[Inc];
			comp2++;
		}
	}
	else
	{
		for (Inc = comp1; Inc <= middle; Inc++)
		{
			b[comp2] = a[Inc];
			comp2++;
		}
	}
	for (Inc = firstElement; Inc <= lastElement; Inc++)
	{
		a[Inc] = b[Inc];
	}
}
void MergeSort(int *a, int*b, int start, int end)
{
	int middle;
	if (start < end)
	{
		middle = (start + end) / 2;
		MergeSort(a, b, start, middle);
		MergeSort(a, b, middle + 1, end);
		Merge(a, b, start, middle, end);
	}
}

void previsit(int v)
{
	visStor[v][1] = clock1++;
}

void postvisit(int v)
{
	visStor[v][2] = clock1++;
}

int main()
{
	Graph g(31);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 16);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 5);
	g.addEdge(3, 7);
	g.addEdge(3, 11);
	g.addEdge(4, 8);
	g.addEdge(4, 10);
	g.addEdge(5, 6);
	g.addEdge(5, 16);
	g.addEdge(8, 9);
	g.addEdge(8, 12);
	g.addEdge(8, 17);
	g.addEdge(10, 16);
	g.addEdge(10, 19);
	g.addEdge(10, 22);
	g.addEdge(10, 21);
	g.addEdge(10, 20);
	g.addEdge(10, 26);
	g.addEdge(10, 27);
	g.addEdge(10, 28);
	g.addEdge(10, 11);
	g.addEdge(10, 6);
	g.addEdge(10, 7);
	g.addEdge(10, 24);
	g.addEdge(11, 17);
	g.addEdge(11, 15);
	g.addEdge(11, 14);
	g.addEdge(11, 12);
	g.addEdge(11, 18);
	g.addEdge(12, 16);
	g.addEdge(12, 13);
	g.addEdge(20, 30);
	g.addEdge(22, 23);
	g.addEdge(24, 25);
	g.addEdge(28, 29);

	cout << "Topological Sort Below \n";
	g.topologicalSort();
	int *y = new int[62];
	int *x = new int[62];
	int start = 0;
	int end = 62;
	int newArray[31];

	cout << "Node\tPre Visit\tPost Visit" << endl;
	for (int i = 0; i < 31; i++)
	{
		cout << visStor[i][0] << "\t\t" << visStor[i][1] << "\t\t" << visStor[i][2] << endl;
	};
	for (int l = 0; l < 31; l++)
	{
		y[l] = visStor[l][2];
	}

	MergeSort(y, x, start, end);
	int count = 0;
	for (int k = 62; k > 31; k--)
	{
		newArray[count] = y[k];
		count++;
	}

	for (int f = 0; f < 31; f++)
	{
		for (int g = 0; g < 31; g++)
		{
			if (newArray[f] == visStor[g][2])
			{
				classArray[f] = visStor[g][0];
				break;
			}
			else if (newArray[f] != visStor[g][0])
			{

			};
		}
	}
	cout << "Post Visit Order" << endl;
	for (int c = 0; c < 31; c++)
	{
		switchCaseSort = classArray[c];
		switch (switchCaseSort)
		{
		case 0:
			cout << "Node = 0 : " << "\t" << "M1390" << endl;
			break;
		case 1:
			cout << "Node = 1 : " << "\t" << "M1591" << endl;
			break;
		case 2:
			cout << "Node = 2 : " << "\t" << "C1470" << endl;
			break;
		case 3:
			cout << "Node = 3 : " << "\t" << "M2330" << endl;
			break;
		case 4:
			cout << "Node = 4 : " << "\t" << "C1480" << endl;
			break;
		case 5:
			cout << "Node = 5 : " << "\t" << "M3320" << endl;
			break;
		case 6:
			cout << "Node = 6 : " << "\t" << "C4350" << endl;
			break;
		case 7:
			cout << "Node = 7 : " << "\t" << "C4390" << endl;
			break;
		case 8:
			cout << "Node = 8 : " << "\t" << "C2440" << endl;
			break;
		case 9:
			cout << "Node = 9 : " << "\t" << "C3380" << endl;
			break;
		case 10:
			cout << "Node = 10 : " << "\t" << "C2320" << endl;
			break;
		case 11:
			cout << "Node = 11 : " << "\t" << "C3330" << endl;
			break;
		case 12:
			cout << "Node = 12 : " << "\t" << "C4300" << endl;
			break;
		case 13:
			cout << "Node = 13 : " << "\t" << "C4345" << endl;
			break;
		case 14:
			cout << "Node = 14 : " << "\t" << "C4365" << endl;
			break;
		case 15:
			cout << "Node = 15 : " << "\t" << "C4353" << endl;
			break;
		case 16:
			cout << "Node = 16 : " << "\t" << "C4310" << endl;
			break;
		case 17:
			cout << "Node = 17 : " << "\t" << "C4340" << endl;
			break;
		case 18:
			cout << "Node = 18 : " << "\t" << "C4315" << endl;
			break;
		case 19:
			cout << "Node = 19 : " << "\t" << "C3190" << endl;
			break;
		case 20:
			cout << "Node = 20 : " << "\t" << "C3335" << endl;
			break;
		case 21:
			cout << "Node = 21 : " << "\t" << "C3345" << endl;
			break;
		case 22:
			cout << "Node = 22 : " << "\t" << "C3381" << endl;
			break;
		case 23:
			cout << "Node = 23 : " << "\t" << "C4490" << endl;
			break;
		case 24:
			cout << "Node = 24 : " << "\t" << "C3370" << endl;
			break;
		case 25:
			cout << "Node = 25 : " << "\t" << "C4320" << endl;
			break;
		case 26:
			cout << "Node = 26 : " << "\t" << "C3350" << endl;
			break;
		case 27:
			cout << "Node = 27 : " << "\t" << "C3385" << endl;
			break;
		case 28:
			cout << "Node = 28 : " << "\t" << "C3360" << endl;
			break;
		case 29:
			cout << "Node = 29 : " << "\t" << "C4370" << endl;
			break;
		case 30:
			cout << "Node = 30 : " << "\t" << "C4355" << endl;
			break;
		}
	}


	return 0;
}