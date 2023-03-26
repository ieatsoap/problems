class Solution {
public:
    int minAddToMakeValid(string s) {
        int valid = 0, f = 0;
        for (char i : s) {
            if (i == '(') ++valid;
            else if (!valid) ++f;
            else --valid;
        }
        return f + valid;
    }
};
