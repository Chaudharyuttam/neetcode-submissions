class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;

        int longest_len = 0;
        for(int i = 0; i < n; i++){
            s.insert(nums[i]);
        }

        for(int i = 0; i < n; i++){
           if(s.find(nums[i] - 1) != s.end()){//if previous one find then move to next
            continue;
           }
           else{//starting th esequence from here 
           int count = 0;
           int current = nums[i];
           while(s.find(current) != s.end()){
            count++;
            current++;
           }
            longest_len = max(longest_len, count);
           }
        }
        return longest_len;
    }
};
