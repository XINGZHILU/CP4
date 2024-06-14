#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> is;

bool isroman(string str)
{
    for (char i : "IVXLCDM")
    {
        if (str[0] == i)
            return true;
    }
    return false;
}

int level(char c)
{
    if (c == 'M')
        return 3;
    else if (c == 'D' or c == 'C')
        return 2;
    else if (c == 'X' or c == 'L')
        return 1;
    else
        return 0;
}

int value(char letter)
{
    switch (letter)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    }
    return 0;
}

void RtoA(string R)
{ // Roman to Arabic
    int ans = 0;
    for (int i = 0; R[i]; ++i)
        if (R[i + 1] && (value(R[i]) < value(R[i + 1])))
        {                                         // check next char first
            ans += value(R[i + 1]) - value(R[i]); // by definition
            ++i;                                  // skip this char
        }
        else
            ans += value(R[i]);
    cout << ans << "\n";
}

int main()
{
    string x;
    int digits, d, len, lvl, arabic;
    string output;
    unordered_map<char, string> atr[4];
    unordered_map<char, int> val;
    atr[3]['3'] = "MMM";
    atr[3]['2'] = "MM";
    atr[3]['1'] = "M";

    atr[2]['9'] = "CM";
    atr[2]['8'] = "DCCC";
    atr[2]['7'] = "DCC";
    atr[2]['6'] = "DC";
    atr[2]['5'] = "D";
    atr[2]['4'] = "CD";
    atr[2]['3'] = "CCC";
    atr[2]['2'] = "CC";
    atr[2]['1'] = "C";
    atr[2]['0'] = "";

    atr[1]['9'] = "XC";
    atr[1]['8'] = "LXXX";
    atr[1]['7'] = "LXX";
    atr[1]['6'] = "LX";
    atr[1]['5'] = "X";
    atr[1]['4'] = "XL";
    atr[1]['3'] = "XXX";
    atr[1]['2'] = "XX";
    atr[1]['1'] = "X";
    atr[1]['0'] = "";

    atr[0]['9'] = "IX";
    atr[0]['8'] = "VIII";
    atr[0]['7'] = "VII";
    atr[0]['6'] = "VI";
    atr[0]['5'] = "V";
    atr[0]['4'] = "IV";
    atr[0]['3'] = "III";
    atr[0]['2'] = "II";
    atr[0]['1'] = "I";
    atr[0]['0'] = "";

    val['M'] = 1000;
    val['D'] = 500;
    val['C'] = 100;
    val['L'] = 50;
    val['X'] = 10;
    val['V'] = 5;
    val['I'] = 1;

    while (cin >> x)
    {
        if (isroman(x))
        {
            arabic = 0;
            lvl = level(x[0]);
            for (int i = 0; i < x.length(); i++)
            {
                if (level(x[i]) > lvl)
                {
                    arabic += val[x[i]];
                    arabic -= 2 * val[x[i - 1]];
                }
                else if (level(x[i]) < lvl)
                {
                    lvl = level(x[i]);
                    arabic += val[x[i]];
                }
                else
                    arabic += val[x[i]];
            }
            cout << arabic << '\n';
        }
        else
        {
            len = x.length();
            digits = len - 1;

            output = "";
            while (digits >= 0)
            {
                output += atr[digits][x[len - digits - 1]];
                // cout << digits << ' ' << x[digits] << ' ';
                digits--;
            }
            cout << output << '\n';
        }
    }

    return 0;
}