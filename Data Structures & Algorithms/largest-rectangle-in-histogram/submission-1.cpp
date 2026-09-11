class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n, 0);//smaller right
        vector<int> left(n, 0);//smaller left
        stack<int> st;
        
        //calculating right smaller 
        for(int i = n-1; i >= 0; i--){
            while(st.size() > 0 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            right[i] = st.empty() ? n: st.top();
            st.push(i);
        }
        //pop the elements until stack is empty
        while(!st.empty()){
            st.pop();
        }

        //calculating left smaller 
        for(int i = 0; i < n; i++){
            while(st.size() > 0 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            left[i] = st.empty() ? -1: st.top();
            st.push(i);
        }
        
        int area = 0;
        for(int i=0; i<n; i++){
            int width = right[i] - left[i] - 1;
            int currarea = heights[i] * width;

            area = max(area, currarea);
        }
        return area;
    }
};
