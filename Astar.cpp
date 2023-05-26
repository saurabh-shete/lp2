#include <bits/stdc++.h>
using namespace std;
int n, m;

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

int heuristic(int x, int y, int destX, int destY)
{
    return abs(destX - x) + abs(destY - y);
}

void astar(vector<vector<int>> &grid, int srcX, int srcY, int destX, int destY)
{
    // manhatten , normal distance , src,dest
    priority_queue<pair<int, pair<int, pair<int, int>>>,
                   vector<pair<int, pair<int, pair<int, int>>>>,
                   greater<pair<int, pair<int, pair<int, int>>>>>
        pq;
    pq.push({0, {0, {srcX, srcY}}});
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vis[srcX][srcY] = 1;

    int manHatten = 0, distance = 0;
    bool flag = 0;

    int rows[] = {1, -1, 0, 0, 1, 1, -1, -1};
    int cols[] = {0, 0, -1, 1, 1, -1, -1, 1};

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int mdist = it.first;
        int dist = it.second.first;
        int x = it.second.second.first;
        int y = it.second.second.second;

        if (x == destX && y == destY)
        {
            manHatten = mdist;
            distance = dist;
            flag = 1;
            break;
        }

        for (int i = 0; i < 8; i++)
        {
            int nrow = rows[i] + x;
            int ncol = cols[i] + y;

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                int tempd = heuristic(nrow, ncol, destX, destY);
                pq.push({mdist + tempd, {dist + 1, {nrow, ncol}}});
                parent[nrow][ncol] = {x, y};
            }
        }
    }

    if (flag)
    {
        cout << "\nDistance = " << distance << "\n";
        cout << "\nManhatten Distance = " << manHatten << "\n";
        cout << "Path is:-\n";

        vector<pair<int, int>> path;
        int currX = destX;
        int currY = destY;

        while (currX != srcX || currY != srcY)
        {
            path.push_back({currX, currY});
            pair<int, int> temp = parent[currX][currY];
            currX = temp.first;
            currY = temp.second;
        }
        path.push_back({srcX, srcY});

        reverse(path.begin(), path.end());

        for (auto i : path)
        {
            cout << "(" << i.first << "," << i.second << ")\n";
        }
    }
    else
    {
        cout << "Path not found\n";
    }
}

int main()
{
    cout << "\nEnter rows and colums of grid:- ";
    n = readInteger();
    m = readInteger();

    vector<vector<int>> grid(n, vector<int>(m, 0));

    int blocked;

    cout << "\nEnter no of blocked cells:- ";
    blocked = readInteger();

    for (int i = 0; i < blocked; i++)
    {
        cout << "\nEnter co-ordinates of blocked cell " << i + 1 << ":- ";
        int src, dest;
        src = readInteger();
        dest = readInteger();
        grid[src][dest] = 1;
    }

    int srcX, srcY, destX, destY;

    cout << "\nEnter source:- ";
    srcX = readInteger();
    srcY = readInteger();

    cout << "\nEnter destination:- ";
    destX = readInteger();
    destY = readInteger();

    if (grid[srcX][srcY] == 1 || grid[destX][destY] == 1)
    {
        cout << "\nYou are entered blocked cell as src or dest";
    }

    astar(grid, srcX, srcY, destX, destY);
}

// Enter rows and columns of grid: 5 6
// Enter the number of blocked cells: 3

// Enter coordinates of blocked cell 1: 1 1
// Enter coordinates of blocked cell 2: 2 3
// Enter coordinates of blocked cell 3: 3 4

// Enter source: 0 0
// Enter destination: 4 5