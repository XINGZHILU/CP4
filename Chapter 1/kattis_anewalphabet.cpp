#include <bits/stdc++.h>
using namespace std;

string lower(string str){
    string output = "";
    int ascii;
    for (auto i : str){
        ascii = (int) i;
        if (65 <= ascii <= 90){
            output += (char) tolower(ascii);
        }
        else output += i;
    }
    return output;
    
}

int main () {
    unordered_map<char, string> na;
    na['a'] = "@";
    na['b'] = "8";
    na['c'] = "(";
    na['d'] = "|)";
    na['e'] = "3";
    na['f'] = "#";
    na['g'] = "6";
    na['h'] = "[-]";
    na['i'] = "|";
    na['j'] = "_|";
    na['k'] = "|<";
    na['l'] = "1";
    na['m'] = "[]\\/[]";
    na['n'] = "[]\\[]";
    na['o'] = "0";
    na['p'] = "|D";
    na['q'] = "(,)";
    na['r'] = "|Z";
    na['s'] = "$";
    na['t'] = "']['";
    na['u'] = "|_|";
    na['v'] = "\\/";
    na['w'] = "\\/\\/";
    na['x'] = "}{";
    na['y'] = "`/";
    na['z'] = "2";
    string str;
    getline(cin, str);
    str = lower(str);
    string output = "";
    for (auto i : str){
        if ((int) i < 97 || (int) i > 122) output += i;
        else output += na[i];
    }
    cout << output;
    
    return 0;
}