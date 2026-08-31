class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < k; i++){
           pq.push({nums[i],i});
        }

        vector<int> ans;

        for(int i = k; i < n; i++){
            while(!pq.empty() && pq.top().second < (i-k)){
                pq.pop();
            }
            ans.push_back(pq.top().first);
            pq.push({nums[i], i});
        }
        while(!pq.empty() && pq.top().second < (n-k)){
            pq.pop();
        }
        ans.push_back(pq.top().first);
        return ans;
    }
};
