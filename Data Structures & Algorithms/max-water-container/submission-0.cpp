class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0, right = n - 1;

        int maxWater = 0;
        while(left < right){
             int height = min(heights[left], heights[right]);
             int width = right - left;

             int area = height * width;

             maxWater = max(maxWater, area);

             if(heights[left] > heights[right]){
                right--;
             }
             else{
                left++;
             }
        }
        return maxWater;
    }
};
