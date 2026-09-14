class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
          int ans = 1e9;
        for(int i = 0; i < n; i++){
             ans = nums[0];
        }
        return ans;
    }
};
