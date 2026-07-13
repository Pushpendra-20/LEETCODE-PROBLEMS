/*
====================================================
LeetCode Problem: N-Queens
Problem Number: 51

Approach:
- Create an empty chessboard of
  size n × n filled with '.'.

- Use Backtracking to place one
  queen in each row.

- Maintain three arrays to quickly
  determine whether a position is
  safe:
    - col[]   : occupied columns.
    - diag1[] : occupied main
                diagonals
                (row + col).
    - diag2[] : occupied secondary
                diagonals
                (row - col + n - 1).

- For each row:
    - Try placing a queen in every
      column.
    - If the column or either
      diagonal is already occupied,
      skip that position.

- When a safe position is found:
    - Place the queen.
    - Mark its column and diagonals
      as occupied.
    - Recurse for the next row.

- After recursion:
    - Remove the queen.
    - Unmark the column and
      diagonals (Backtracking).

- When all rows are processed:
    - Store the current board as
      one valid solution.

Why this approach?
- Backtracking systematically
  explores all possible queen
  placements.
- Using separate arrays for columns
  and diagonals allows safety checks
  in O(1) time.
- Invalid configurations are pruned
  early, making the search much
  faster than checking the entire
  board repeatedly.

Example:

Input:
n = 4

Output:
[
 [".Q..",
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",
  "Q...",
  "...Q",
  ".Q.."]
]

Time Complexity: O(N!)

Space Complexity: O(N)

Where:
N = size of the chessboard

Key Concepts:
- Backtracking
- Recursion
- DFS
- Matrix
- Constraint Satisfaction

Note:
Although the worst-case complexity
is O(N!), the use of column and
diagonal arrays enables constant-
time validity checks, making this
the standard optimal backtracking
solution for the N-Queens problem.

====================================================
*/



class Solution {
public:
    vector<vector<string>> ans;
    void solve(int row, vector<string>& board, vector<int>& col,
               vector<int>& diag1, vector<int>& diag2, int n) {
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int c = 0; c < n; c++){
            if(col[c] || diag1[row+c] || diag2[row-c+n-1]) continue;
            board[row][c] = 'Q';
            col[c] = diag1[row+c] = diag2[row-c+n-1] = 1;
            solve(row+1, board, col, diag1, diag2, n);
            board[row][c] = '.';
            col[c] = diag1[row+c] = diag2[row-c+n-1] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        vector<int> col(n), diag1(2*n), diag2(2*n);
        solve(0, board, col, diag1, diag2, n);
        return ans;
    }
};
