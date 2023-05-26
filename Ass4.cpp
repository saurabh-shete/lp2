#include <bits/stdc++.h>

using namespace std;
int n;
class Solution
{
public:
  bool isSafe1(int row, int col, vector<string> board, int n)
  {
    int duprow = row;
    int dupcol = col;

    while (row >= 0 && col >= 0)
    {
      if (board[row][col] == 'Q')
        return false;
      row--;
      col--;
    }

    col = dupcol;
    row = duprow;
    while (col >= 0)
    {
      if (board[row][col] == 'Q')
        return false;

      col--;
    }

    row = duprow;
    col = dupcol;
    while (row < n && col >= 0)
    {
      if (board[row][col] == 'Q')
        return false;

      row++;
      col--;
    }
    return true;
  }

public:
  void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
  {
    if (col == n)
    {
      ans.push_back(board);
      return;
    }
    for (int row = 0; row < n; row++)
    {
      if (isSafe1(row, col, board, n))
      {
        board[row][col] = 'Q';
        solve(col + 1, board, ans, n);
        board[row][col] = '.';
      }
    }
  }

public:
  vector<vector<string>> solveNQueens(int n)
  {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
      board[i] = s;
    }
    solve(0, board, ans, n);
    return ans;
  }

  // Branch and Bound
public:
  bool safe2(vector<vector<int>> &board, int col, vector<bool> rows, vector<bool> left_digonals, vector<bool> Right_digonals)
  {
    // base Case : If all Queens are placed
    if (col >= n)
    {
      return true;
    }

    for (int i = 0; i < n; i++)
    {
      if (isSafe2(i, col, rows, left_digonals, Right_digonals) == true)
      {
        rows[i] = true;
        left_digonals[i + col] = true;
        Right_digonals[col - i + n - 1] = true;
        board[i][col] = 1; // placing the Queen in board[i][col]

        if (safe2(board, col + 1, rows, left_digonals, Right_digonals) == true)
        {
          return true;
        }

        // Backtracking
        rows[i] = false;
        left_digonals[i + col] = false;
        Right_digonals[col - i + n - 1] = false;
        board[i][col] = 0;
      }
    }

    return false;
  }

public:
  bool isSafe2(int row, int col, vector<bool> rows, vector<bool> left_digonals, vector<bool> Right_digonals)
  {

    if (rows[row] == true || left_digonals[row + col] == true || Right_digonals[col - row + n - 1] == true)
    {
      return false;
    }

    return true;
  }
};

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
  Solution obj;

  cout << "Enter size of grid : ";
  n = readInteger();
  cout << endl;
  if (n > 12)
  {
    cout << "Grid size too large!" << endl
         << endl;
    return 0;
  }

  int choice;
  cout << "Enter your choice: \n";
  cout << "1.Backtrack\n";
  cout << "2.Branch and Bound\n";
  choice = readInteger();
  if (choice == 1)
  {

    vector<vector<string>> ans = obj.solveNQueens(n);
    if (ans.size() == 0)
      cout << "No Arrangements possible!" << endl;
    else
    {
      for (int i = 0; i < ans.size(); i++)
      {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < ans[0].size(); j++)
        {
          cout << ans[i][j];
          cout << endl;
        }
        cout << endl;
        cout << endl;
      }
    }
  }
  else
  {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<bool> rows(n, false);
    vector<bool> left_digonals(2 * n - 1, false);
    vector<bool> Right_digonals(2 * n - 1, false);

    bool ans = obj.safe2(board, 0, rows, left_digonals, Right_digonals);

    if (ans == true)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          if (board[i][j])
            cout << 'Q';
          else
            cout << '.';
        }
        cout << "\n";
      }
    }
    else
    {
      cout << "Solution Does not Exist\n";
    }
  }
  return 0;
}