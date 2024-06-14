#include <bits/stdc++.h>
using namespace std;

string morse[30] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
"--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..","..--",
".-.-","---.","----"};
string original = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_,.?";
deque<int> pauses;

int main () {
    unordered_map<string, char> mtoc;
    unordered_map<char, string> ctom;
    for (int i=0; i<=29; i++){
        mtoc[morse[i]] = original[i];
        ctom[original[i]] = morse[i];
    }
    string before, m;
    int pos;
    while (cin >> before){
        m = "";
        pauses = {};
        for (auto i : before){
            m += ctom[i];
            pauses.push_front(ctom[i].length());
        }
        pos = 0;
        for (auto i : pauses){
            cout << mtoc[m.substr(pos, i)];
            pos += i;
        }
        cout << '\n';
    }
    return 0;
}