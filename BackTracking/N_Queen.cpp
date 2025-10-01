#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int N, bool *column, bool *diagonal_1, bool *diagonal_2, int row, int col)
{
    if (column[col] == true)
        return false;
    if (diagonal_1[row + col] == true)
        return false;
    if (diagonal_2[row - col + (N - 1)] == true)
        return false;
    return true;
}

void solve(int N, char **chess_board, int row, bool *diagonal_1, bool *diagonal_2, bool *column)
{
    if (row == N)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << chess_board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    else
    {
        for (int col = 0; col <N; col++)
        {
            if (isSafe(N, column, diagonal_1, diagonal_2, row, col))
            {
                chess_board[row][col] = 'Q';
                column[col] = true;
                diagonal_1[row + col] = true;
                diagonal_2[row - col + (N - 1)] = true;
                solve(N, chess_board, row + 1, diagonal_1, diagonal_2, column);
                chess_board[row][col] = '-';
                column[col] = false;
                diagonal_1[row + col] = false;
                diagonal_2[row - col + (N - 1)] = false;
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;
    char **chess_board;
    // Allocate chess_board in heap and store the base address in stack
    chess_board = new char *[N];
    // Allocate space for each row in heap
    for (int i = 0; i < N; i++)
    {
        chess_board[i] = new char[N];
        for (int j = 0; j < N; j++)
        {
            chess_board[i][j] = '-';
        }
    }
    bool *column = new bool[N];             // column check
    bool *diagonal_1 = new bool[2 * N - 1]; // Left diagonal check
    bool *diagonal_2 = new bool[2 * N - 1]; // right diagonal check
    for (int i = 0; i < 2 * N - 1; i++)
    {
        diagonal_1[i] = diagonal_2[i] = false;
    }
    for(int i=0;i<N;i++)
    {
        column[i]=false;
    }
    solve(N,chess_board,0,diagonal_1,diagonal_2,column);
}