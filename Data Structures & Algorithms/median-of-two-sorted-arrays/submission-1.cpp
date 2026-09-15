class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        int n = (n1+n2);
        int idx2 = n/2, idx1 = n/2-1;
        int count = 0;
        int idx1el = -1, idx2el = -1;
        while(i < n1 && j < n2){
          if(nums1[i] < nums2[j]){
            if(count == idx1) idx1el = nums1[i];
            if(count == idx2) idx2el = nums1[i];
            count++;
            i++;
          }
          else{
            if(count == idx1) idx1el = nums2[j];
            if(count == idx2) idx2el = nums2[j];
            count++;
            j++;
          }
        }
        while(i < n1){
            if(count == idx1) idx1el = nums1[i];
            if(count == idx2) idx2el = nums1[i];
            count++;
            i++;
        }
        while(j < n2){
            if(count == idx1) idx1el = nums2[j];
            if(count == idx2) idx2el = nums2[j];
            count++;
            j++;
        }
        if(n%2 == 1){
            return idx2el;
        }
        return (double)((double)(idx1el + idx2el))/ 2.0;
    }
};
