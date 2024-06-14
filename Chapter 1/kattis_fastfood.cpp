#include <bits/stdc++.h>
using namespace std;
int cnt[31];
vector<int> prizes[11];
int value[11];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, m, k, s, minc, total;
    cin >> t;
    while (t--){
        total = 0;
        cin >> n >> m;
        for (int i=0; i<n; i++){
            cin >> k;
            prizes[i] = {};
            for (int j=0; j<k; j++){
                cin >> s;
                prizes[i].push_back(s);
            }
            cin >> value[i];
        }
        for (int i=1; i<=m; i++) cin >> cnt[i];
        for (int i=0; i<n; i++){
            minc = 101;
            for (int j=0; j<prizes[i].size(); j++){
                minc = min(cnt[prizes[i][j]], minc);
            }
            total += minc * value[i];
            
        }
        cout << total << '\n';
    }
    
    
    return 0;
}