#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

size_t INF = numeric_limits<size_t>::max();

void InitializeMatrix(vector<vector<size_t>>& graph, size_t n);
void PrintMatrix(vector<vector<size_t>> graph);
void ShortestPaths(vector<vector<size_t>>& graph);

int main()
{
	size_t n = 0;
	cout << "Enter the number of nodes: ";
	cin >> n;

	vector<vector<size_t>> graph;

	InitializeMatrix(graph, n);
	PrintMatrix(graph);

	size_t start = 0, end = 0;
	cout << "Enter the start node: ";
	cin >> start;
	cout << "Enter the end node: ";
	cin >> end;

	ShortestPaths(graph);
	cout << "The shortest distance between the nodes is: " << graph[start][end] << endl;

	return 0;
}

void InitializeMatrix(vector<vector<size_t>>& graph, size_t n)
{
	graph.resize(n, vector<size_t>(n, INF));
	srand(time(nullptr));
	for (size_t i = 0; i < graph.size(); i++)
	{
		graph[i][i] = 0;
		for (size_t j = i+1; j < graph.size(); j++)
		{
			if (rand() % 100 < 70)
			{
				size_t dist = rand() % 10 + 1;
				graph[i][j] = dist;
				graph[j][i] = dist;
			}
		}
	}
}

void PrintMatrix(vector<vector<size_t>> graph)
{
	for (size_t i = 0; i < graph.size(); i++) 
	{
		for (size_t j = 0; j < graph.size(); j++)
		{
			if (graph[i][j] == INF) 
			{
				cout << setw(4) << "INF";
			}
			else 
			{
				cout << setw(4) << graph[i][j];
			}
		}
		cout << endl;
	}
}

void ShortestPaths(vector<vector<size_t>>& graph)
{
	for (size_t k = 0; k < graph.size(); k++)
	{
		for (size_t i = 0; i < graph.size(); i++)
		{
			for (size_t j = i+1; j < graph.size(); j++)
			{
				if (graph[i][j] > (graph[i][k] + graph[k][j]) && graph[i][k] != INF && graph[k][j] != INF)
				{
					graph[i][j] = graph[i][k] + graph[k][j];
					graph[j][i] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}

