
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> pre(n);
        int minSum = INT_MAX;
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        for (int win = l; win <= r; win++) {
            for (int j = win - 1; j < n; j++) {
                int winSum = pre[j];
                if (j - win >= 0) {
                    winSum -= pre[j - win];
                }
                if (winSum > 0) {
                    minSum = min(minSum, winSum);
                }
            }
        }
        return minSum == INT_MAX ? -1 : minSum;
    }
};