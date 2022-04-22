// using dp O(n2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for(int i = 0; i < n; i++) {
            int mx = 0;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    mx = max(mx, dp[j]);
                }
            }
            dp[i] = 1 + mx;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// using binary search O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                len++;
            } else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }
};