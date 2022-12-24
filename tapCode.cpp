#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

string conv(char c, string s = "") {
    if (c != '\0') {
        int n = (int)c;
        if (n > 96) n -= 96;
        else n -= 64;
        if (n > 10) n --;
        int d1 = (int)ceil((double)n/5), d2 = ((n-1)%5) + 1;
        string f (d1 + d2, '.');
        f.insert(d1, 1, ' ');
        return f;
    } else {
        int j = 0, k = 0;
        for (int i = 0, l = 0; i < s.length(); i ++) {
            if (s[i] == '.') {
                if (l == 0) j ++;
                else k ++;
            } else l ++;
        }
        return "" + (char)(j*5 + k + 91);
    }
}

string tapCode(string text) {
    string f;
    if (text[0] == '.') {
        for (int i = 0, j = 0, k = 0; k < 1; i ++) {
            string p;
            if (text[i] != '.') {
                if (!j) {
                    j = 1;
                    p += ' ';
                } else {
                    j = 0;
                    f += conv('\0', p);
                    p = "";
                }
            } else p += '.';
        }
    } else {
        for (int i = 0; i < text.length(); i ++) {
            string n = conv(text[i]);
            if (text[i] == 'k' || text[i] == 'K') n = ". ...";
            f += n + ' ';
        }
        f.erase(f.length()-1);
    }
    return f;
}

int main() {
    string u = tapCode("ankle");
    string g = ". . ... ... . ... ... . . .....";
    cout << u << endl;
    if (!u.compare(g)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0; 
}