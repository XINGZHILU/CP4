#include <bits/stdc++.h>
using namespace std;

char encoded[100][100];

int main () {
    string str;
    cin >> str;
    int row = 1, n=str.length();
    for (int r=2; r*r<=n; r++) if (n%r==0) row = r;
    int col = n/row, ind = 0;
    for (int c=0; c<col; c++){
        for (int r=0; r<row; r++){
            encoded[r][c] = str[ind];
            ind++;
        }
    }
    for (int r=0; r<row; r++){
        for (int c=0; c<col; c++){
            cout << encoded[r][c];
        }
    }
    return 0;
}