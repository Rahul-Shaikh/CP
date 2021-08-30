#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<int> > &board, int col, int row) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }

    for (int i = row, j = col; i < 8 && j >= 0; i++, j--) {
        if (board[i][j] == 1) return false;
    }

    return true;
}

bool solveUtil(vector<vector<int> > &board, int col) {
    if (col == 8) return true;
    
    for (int r = 0; r < 8; r++) {
        if (isValid(board, col, r)) {
            board[r][col] = 1;
            if (solveUtil(board, col+1)) return true;
            board[r][col] = 0;
        }
    }

    return false;
}

void solve(vector<vector<int> > &board) {
    if (solveUtil(board, 0) == true) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "NO SOLUTION\n";
    }
}

int main(void) {
    vector<vector<int> > board(8, vector<int> (8, 0));

    solve(board);
}