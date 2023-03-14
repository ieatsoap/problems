#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        int jumps = 1, dist = nums[0]+1, max_dist = 0;

        for (int i = 0, il = nums.size()-1; i <= il; i ++) {
            if ((nums[i] + i) >= il) {
                return (!i) ? 1 : ++jumps;
            }
            if (nums[i] > max_dist) max_dist = nums[i];
            if (!--dist) {
                ++jumps;
                dist = max_dist;
                max_dist = 0;
            } else --max_dist;
        }

        return jumps;
    }
};
