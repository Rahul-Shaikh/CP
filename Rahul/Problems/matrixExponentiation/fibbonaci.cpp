#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void multiply(vector<vector<int> > &mat, vector<vector<int> > &m) {
    int n = mat.size();

    vector<vector<int> > v(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += mat[i][k] * m[k][j];
            }
            v[i][j] = sum;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = v[i][j];
        }
    }
}

void power(vector<vector<int> > &mat, int n) {
    if (n == 0 || n == 1) return;

    vector<vector<int> > m{{1,1},
                            {1, 0}};

    power(mat, n/2);
    multiply(mat, mat);

    if (n%2) multiply(mat, m);
}

int fibb(int n) {
    if (n <= 2) return 1;

    vector<vector<int> > v{{1, 1},
                        {1, 0}};

    power(v, n-1);

    return v[0][0];
}

int main(void) {
    int n;
    cin >> n;

    cout << fibb(n);
}