#include<bits/stdc++.h>
using namespace std;

void LCS(vector<vector<int>>& cost, vector<vector<char>>& dir, string &X, string &Y) {
    int x = X.length();
    int y = Y.length();

    for (int i = 0; i <= x; i++) {
        cost[i][0] = 0;
        dir[i][0] = 'H';
    }
    for (int j = 0; j <= y; j++) {
        cost[0][j] = 0;
        dir[0][j] = 'H';
    }

    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            if (X[i-1] != Y[j-1]) {
                if (cost[i-1][j] >= cost[i][j-1]) {
                    cost[i][j] = cost[i-1][j];
                    dir[i][j] = 'U';
                } else {
                    cost[i][j] = cost[i][j-1];
                    dir[i][j] = 'S';
                }
            } else {
                cost[i][j] = cost[i-1][j-1] + 1;
                dir[i][j] = 'D';
            }
        }
    }
}

void Print_LCS(int i, int j, vector<vector<int>> &cost, vector<vector<char>> &dir, string &X) {
    if (i == 0 || j == 0) return;

    if (dir[i][j] == 'D') {
        Print_LCS(i-1, j-1, cost, dir, X);
        cout << X[i-1];
    } else if (dir[i][j] == 'U') {
        Print_LCS(i-1, j, cost, dir, X);
    } else {
        Print_LCS(i, j-1, cost, dir, X);
    }
}

int main() {
    string X = "AGCCCTAAGGGCTACCTAGCTT";
    string Y = "GACAGCCTACAAGCGTTAGCTTG";
    int x = X.length();
    int y = Y.length();

    vector<vector<int>> cost(x+1, vector<int>(y+1));
    vector<vector<char>> dir(x+1, vector<char>(y+1));

    LCS(cost, dir, X, Y);

    cout << "LCS: ";
    Print_LCS(x, y, cost, dir, X);
    cout << "\nLength of LCS: " << cost[x][y] << endl;
}
