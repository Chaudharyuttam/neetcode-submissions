class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int lmax = 0, rmax = 0;
        int maxWater = 0;

        while(left < right){
            lmax = max(lmax, height[left]);
            rmax = max(rmax, height[right]);

            if(lmax < rmax){
                maxWater += lmax - height[left];
                left++;
            }
            else{
                maxWater += rmax - height[right];
                right--;
            }
            
        }
        return maxWater;
    }
};
