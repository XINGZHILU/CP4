#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> is;

string AtoR(int A)
{ // Arabic to Roman
    string output = "";
    vector<is> convert({{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}});
    for (auto &[value, roman] : convert) // from large to small
        while (A >= value)
        {
            output += roman;
            A -= value;
        }
    return output;
}
int main()
{
    unordered_map<char, int> match;
    int n, cnt;
    string roman;
    match['I'] = 1;
    match['V'] = 2;
    match['X'] = 2;
    match['L'] = 2;
    match['C'] = 2;
    match['D'] = 3;
    match['M'] = 4;
    while (cin >> n){
        cnt = 0;
        roman = AtoR(n);
        for (auto i : roman){
            cnt += match[i];
        }
        cout << cnt << '\n';
    }

    return 0;
}