#include <bits/stdc++.h>
using namespace std;

int main () {
    char str[305];
    cin >> str;
    int days = 0;
    unordered_map<int, char> rep;
    rep[0] = 'P';
    rep[1] = 'E';
    rep[2] = 'R';
    for (int i=0; i<strlen(str); i++){
        if (str[i] != rep[i%3]) days++;
    }
    cout << days;
    
    
    return 0;
}