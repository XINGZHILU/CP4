#include <bits/stdc++.h>
using namespace std;

int index(string s, char c){
    for (int i=0; i<s.length(); i++) if (s[i] == c) return i;
    return -1;
}

int solvexor(int known, int result, int n){
    for (int i=0; i<n; i++){
        if (i^known == result) return i;
    }
    return -1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, d, n, dp, j1, pp;
    string S, P, C;
    char M[65];
    while (true){
        cin >> x;
        if (x==0) return 0;
        cin >> S;
        cin >> P;
        cin >> C;
        n = C.length();
        d = ((int)((pow(n, 1.5)+x)));
        d %= n;
        
        dp = index(S, C[d]);
        M[d] = P[dp];
        cout << n << '\t' << d << '\t' << M[d] << '\t';
        for (int j=d-1; j>=0; j--){
            dp = index(S, C[j]);
            j1 = index(S, M[(j+1)%n]);
            pp = solvexor(j1, dp, n);
            M[j] = P[pp];
        }
        for (int j=d+1; j<n; j++){
            
        }
        for (int j=0; j<=d; j++) cout << M[j];
        cout << '\n';
    }
    
    
    return 0;
}