#include <iostream>

using namespace std;

char mod(char x, int y) {
    int finLoc, c = ( toupper(x) == x ), n = (int)x + (y % 26);
    switch (c) {
        case 0:
            if (n > 122) return (char)(n - 26);
            return (char)n;
        case 1:
            if (n > 90) return (char)(n - 26);
            return (char)n;
    }
    return ' ';
}

string caesarCipher(string s, int k) {
    int stringLength = s.length();
    string fin;
    for (int i = 0; i < stringLength; i ++) {
        char n = mod(s[i], k);
        if (s[i] != ' ' && s[i] != '.' && s[i] != '-' && s[i] != ',' && s[i] != ':') fin += n;
        else fin += s[i];
    }
    return fin;
}

int main() {
    string bruh = caesarCipher("middle-Outz", 2);
    string real = "okffng-Qwvb";
    if (!bruh.compare(real)) cout << "real" << endl;
    else cout << "fake. yours: " << bruh << " ---------- real: " << bruh << endl;
    return 0;
}