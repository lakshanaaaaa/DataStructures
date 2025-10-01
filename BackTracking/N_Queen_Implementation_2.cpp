#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int n, int row, int col, vector<bool> column, vector<bool> left_diagonal, vector<bool> right_diagonal)
{
    if (column[col] == true)
        return false;
    if (left_diagonal[col + row] == true)
        return false;
    if (right_diagonal[row - col + n - 1] == true)
        return false;
    return true;
}

void Solve_N_Queen(vector<string> board, int n, int row, vector<bool> &column, vector<bool> &left_diagonal, vector<bool> &right_diagonal, vector<vector<string>> &ans)
{
    if (n == row)
    {
        ans.push_back(board);
    }
    else
    {
        for (int col = 0; col < n; col++)
        {
            if (isSafe(n, row, col, column, left_diagonal, right_diagonal))
            {
                board[row][col] = 'Q';
                column[col] = true;
                left_diagonal[row + col] = true;
                right_diagonal[row - col + n - 1] = true;
                Solve_N_Queen(board, n, row + 1, column, left_diagonal, right_diagonal, ans);
                board[row][col] = '-';
                column[col] = false;
                left_diagonal[row + col] = false;
                right_diagonal[row - col + n - 1] = false;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<string> board(n);
    vector<vector<string>> ans;
    vector<bool> column(n, false);
    vector<bool> left_diagonal(2 * n - 1, false);
    vector<bool> right_diagonal(2 * n - 1, false);
    string s(n, '-');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    Solve_N_Queen(board, n, 0, column, left_diagonal, right_diagonal, ans);
    for (auto row : ans)
    {
        for (auto col : row)
        {
            cout << "[" << col << "]";
            cout << "\n";
        }
        cout << "\n";
    }
}