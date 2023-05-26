#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair<long long, pair<int, int>> p[MAX];
vector<pair<long long, pair<int, int>>> result;

int readInteger()
{
  while (true)
  {
    string input;
    getline(cin, input);

    try
    {
      size_t pos;
      int value = stoi(input, &pos);

      if (pos == input.size())
      {
        return value;
      }
    }
    catch (const exception &)
    {
      // Invalid input, try again
    }

    cout << "Invalid input. Please enter an integer: ";
  }
}

void initialize()
{
  for (int i = 0; i < MAX; ++i)
    id[i] = i;
}
int root(int x)
{
  while (id[x] != x)
  {
    id[x] = id[id[x]];
    x = id[x];
  }
  return x;
}

void union1(int x, int y)
{
  int p = root(x);
  int q = root(y);
  id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int>> p[])
{
  int start, end;
  long long cost, minimumCost = 0;
  for (int i = 0; i < edges; ++i)
  {
    // Selecting edges one by one in increasing order from the beginning
    start = p[i].second.first;
    end = p[i].second.second;
    cost = p[i].first;
    // Check if the selected edge is creating a cycle or not
    if (root(start) != root(end))
    {
      result.emplace_back(cost, make_pair(start, end));
      minimumCost += cost;
      union1(start, end);
    }
  }
  return minimumCost;
}

int main()
{
  int x, y;
  long long weight, cost, minimumCost;

  initialize();
  cout << "Enter number of vertices: ";
  nodes = readInteger();
  cout << "\nEnter number of edges: ";
  edges = readInteger();
  for (int i = 0; i < edges; ++i)
  {
    cout << "\nEnter src dest and weight for edge " << i + 1 << ": ";
    x = readInteger();
    y = readInteger();
    weight = readInteger();
    p[i] = make_pair(weight, make_pair(x, y));
  }
  // Sort the edges in the ascending order
  sort(p, p + edges);
  minimumCost = kruskal(p);
  cout << "\nKruskal's Algorithm \n";
  cout << "src\tdest\tweight:\n";
  for (auto edge : result)
  {
    cout << edge.second.first << " <--->  " << edge.second.second << " \t  " << edge.first << endl;
  }
  cout << "Minimum weight of spanning tree is = " << minimumCost << "\n";

  for (int i = 0; i < 6; i++)
  {
    cout << id[i] << endl;
  }

  return 0;
}

// Enter number of vertices: 5
// Enter number of edges: 7
// Enter src dest and weight for edge 1: 0 1 1
// Enter src dest and weight for edge 2: 0 2 7
// Enter src dest and weight for edge 3: 1 2 5
// Enter src dest and weight for edge 4: 1 3 4
// Enter src dest and weight for edge 5: 1 4 3
// Enter src dest and weight for edge 6: 2 4 6
// Enter src dest and weight for edge 7: 3 4 2

// Enter number of vertices: 5
// Enter number of edges: 7
// Enter src dest and weight for edge 1: 0 1 1
// Enter src dest and weight for edge 2: 0 2 7
// Enter src dest and weight for edge 3: 1 2 5
// Enter src dest and weight for edge 4: 1 3 4
// Enter src dest and weight for edge 5: 1 4 3
// Enter src dest and weight for edge 6: 2 4 6
// Enter src dest and weight for edge 7: 3 4 2
