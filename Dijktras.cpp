#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges" << endl;
    V = readInteger();
    E = readInteger();

    vector<pair<int, int>> adj[V + 1];

    while (E--)
    {
        int source, destination, weight;
        cout << "Enter source, destination  and weight of edge" << endl;
        source = readInteger();
        destination = readInteger();
        weight = readInteger();
        adj[source].push_back({destination, weight});
        adj[destination].push_back({source, weight});
    }

    vector<int> distance(V + 1, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int start;
    cout << "Enter the starting node to calculate distance" << endl;
    start = readInteger();

    distance[start] = 0;

    pq.push({0, start});

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        for (auto it : adj[node])
        {

            int nextnode = it.first;
            int wght = it.second;

            if (dist + wght < distance[nextnode])
            {
                distance[nextnode] = dist + wght;
                pq.push({dist + wght, nextnode});
            }
        }
    }

    cout << "Printing distance :" << endl;

    for (int i = 0; i < V; i++)
    {
        cout << "Distance from " << start << " to " << i << " is " << distance[i] << endl;
    }

    return 0;
}

// Enter number of vertices and edges
// 5 7

// Enter source, destination, and weight of edge
// 0 1 4
// Enter source, destination, and weight of edge
// 0 2 1
// Enter source, destination, and weight of edge
// 1 2 2
// Enter source, destination, and weight of edge
// 1 3 5
// Enter source, destination, and weight of edge
// 2 3 1
// Enter source, destination, and weight of edge
// 2 4 8
// Enter source, destination, and weight of edge
// 3 4 3

// Enter the starting node to calculate distance
// 0