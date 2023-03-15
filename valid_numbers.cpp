using namespace std;

class Solution {
public:
    bool seen_dot = false;
    bool seen_e = false;

    bool is_onetonine(char c) { return ('0' <= c && c <= '9'); }
    bool is_sign(char c) { return (c == '+' || c == '-'); }
    bool is_dot(char c) { return (c == '.') && (!seen_dot) && (seen_dot = true); }
    bool is_e(char c) { return (c == 'e' || c == 'E') && (!seen_e) && (seen_e = true); }

    bool after_num(char c) {
        return is_onetonine(c) || !is_sign(c) && (is_dot(c) || is_e(c));
    }
    bool after_e(char c) {
        return is_onetonine(c) || is_sign(c);
    }
    bool after_sign(char c) {
        return is_onetonine(c) || is_dot(c);
    }
    bool after_dot(char c) {
        return is_onetonine(c) || is_e(c);
    }

    bool isNumber(string s, bool dot = false) {
        seen_dot = dot;
        if (s.length() == 1) return ("0" <= s && s <= "9");
        switch (s[0]) {
            case '+':
            case '-':
                return isNumber(s.substr(1));
            case '.':
                return (seen_dot || !after_dot(s[1])) ? false : isNumber(s.substr(1), true);
            case 'e':
            case 'E':
                return false;
        }
        int i;
        for (i = 0; i < s.length()-1; i ++) {
            if ('0' <= s[i] && s[i] <= '9' && after_num(s[i+1])) continue;
            else switch (s[i]) {
                case '+':
                case '-':
                    if (after_sign(s[i+1])) continue;
                    else break;
                case '.':
                    if (!seen_e && after_dot(s[i+1])) continue;
                    else break;
                case 'e':
                case 'E':
                    if (after_e(s[i+1])) continue;
            }
            return false;
        }
        return (s[i] == '.') ? !seen_e : is_onetonine(s[i]);
    }
};
