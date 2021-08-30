#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

void spiral2(vector<vi> &matrix) {
    int r1 = 0, r2 = matrix.size() - 1;
    int c1 = 0, c2 = matrix[0].size() - 1;
    vector<int> ans;
    while (r1 <= r2 && c1 <= c2) {
        for (int c = c1; c <= c2; c++) ans.push_back(matrix[r1][c]);
        for (int r = r1 + 1; r <= r2; r++) ans.push_back(matrix[r][c2]);
        if (r1 < r2 && c1 < c2) {
            for (int c = c2 - 1; c > c1; c--) ans.push_back(matrix[r2][c]);
            for (int r = r2; r > r1; r--) ans.push_back(matrix[r][c1]);
        }
        r1++;
        r2--;
        c1++;
        c2--;
    }
    for (int i: ans) cout << i << " ";
    cout << endl;
} 

void spiralPrint(vector<vi> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    int rs = 0, cs = 0;
    int re = n-1, ce = m-1;
    while (rs < n || re >= 0 || ce >=0 || cs < m || cs <= ce || rs <= re) {
        for (int i = cs; i <= ce; i++) {
            cout << mat[rs][i] << " ";
        }
        rs++;
        // cout << rs << " " << re << " " << cs << " " <<ce << endl;
        if (rs > re) break;
        for (int i = rs; i <= re; i++) {
            cout << mat[i][ce] << " ";
        }
        ce--;
        if (cs>ce) break;
        // cout << rs << " " << re << " " << cs << " " <<ce << endl;

        for (int i = ce; i >= cs; i--) {
            cout << mat[re][i] << " ";
        }
        re--;
        if (rs > re) break;
        // cout << rs << " " << re << " " << cs << " " <<ce << endl;

        for (int i = re; i >= rs; i--) {
            cout << mat[i][cs] << " ";
        }
        cs++;
        if (cs > ce) break;
        // cout << rs << " " << re << " " << cs << " " <<ce << endl;
    }
    cout << endl;
}

int main(void) {

    vector<vi> mat;
    for (int i = 0; i < 4; i++) {
        vi temp;
        for (int j = 0; j < 4; j++) {
            temp.push_back(4*i  +j + 1);
        }
        mat.push_back(temp);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    spiralPrint(mat);
    spiral2(mat);

}