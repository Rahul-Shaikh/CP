#include <iostream>
#include <vector>

using namespace std;

int R, C;

void transpose(vector<vector<int> > &matrix) {
    for (int i = 0; i < R; i++) {
        for (int j = i; j < C; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void reverseRows(vector<vector<int> > &matrix) {
    for (int i = 0; i < R; i++) {
        for (int j = 0, k = C-1; j < k; j++, k--) {
            swap(matrix[i][j], matrix[i][k]);
        }
    }
}

void rotate(vector<vector<int> >& matrix) {
    R = matrix.size();
    C = matrix[0].size();
    transpose(matrix);
    reverseRows(matrix);
}
