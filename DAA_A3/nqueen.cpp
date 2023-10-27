#include <iostream>
using namespace std;

const int MAX_N = 10; // Maximum board size
int N;
int board[MAX_N][MAX_N];

bool isSafe(int row, int col)
{
    // Check column on the left
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    // Check lower-left diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

bool solveNQueens(int col)
{
    if (col == N)
    {
        // All queens are placed successfully
        return true;
    }
    /* Consider this column and try placing this queen in all row one by one*/
    for (int row = 0; row < N; row++)
    {
        /* Check if queen can be placed on board[row][col] */
        if (isSafe(row, col))
        {
            // place this queen in board[row][col]
            board[row][col] = 1;

            // recur to place rest of the queens
            if (solveNQueens(col + 1))
            {
                return true;
            }

            /* If placing queen in board[row][col] does't lead to a 
            solution, then remove queen from board[row][col] */
            board[row][col] = 0; // Backtrack
        }
    }
    /* If queen can not be place in any row in this column col then return false*/
    return false;
}

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << (board[i][j] ? "1" : "0") << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Enter the value of N: ";
    cin >> N;

    if (N <= 0 || N > MAX_N)
    {
        cout << "Invalid board size." << endl;
        return 1;
    }

    // Initialize the board
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    if (solveNQueens(0))
    {
        cout << "Solution found:" << endl;
        printBoard();
    }
    else
    {
        cout << "No solution exists." << endl;
    }

    return 0;
}
/* OUTPUT
Enter the value of N: 4

Solution found:
0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0
*/
/*
#include<iostream>
using namespace std;
# define N 4

void solution(int board[N][N]){
        for(int  i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }

}
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[N][N], int col)
{
    // base case: If all queens are placed
    // then return true
    if (col >= N)
        return true;

    // Consider this column and try placing
    // this queen in all rows one by one
    for (int i = 0; i < N; i++) {

        // Check if the queen can be placed on
        // board[i][col]
        if (isSafe(board, i, col)) {

            // Place this queen in board[i][col]
            board[i][col] = 1;

            // recur to place rest of the queens
            if (solveNQUtil(board, col + 1))
                return true;

            // If placing queen in board[i][col]
            // doesn't lead to a solution, then
            // remove queen from board[i][col]
            board[i][col] = 0; // BACKTRACK
        }
    }

    // If the queen cannot be placed in any row in
    // this column col  then return false
    return false;
}

bool solveNQ(){
    int board[N][N]={0};
    if(solveNQUtil(board,0)==false){
        cout << "solution doesn't exist";
        return false;
    }
    solution(board);
    return true;
}
int main(){

    solveNQ();

    return 0;
}
*/
