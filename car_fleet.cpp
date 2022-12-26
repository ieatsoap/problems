#include <vector>
using namespace std;

class Solution {
public:

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<float> h (target + 1);

        for (int i = 0; i < position.size(); i ++) {
            h[position[i]] = (target - position[i]) / (speed[i] * 1.0f);
        }

        float *s, f = 0;
        s = new float(0.00000000000001);
        for (int i = target; i >= 0; i --) {
            if (h[i] > *s) {
                f ++;
                *s = h[i];
            }
        }
        return f;
    }
};