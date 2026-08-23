class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> st;

        int i = 0;
        int longest = 0;

        for(int j = 0; j < n; j++) {

            // Duplicate found in the set 
            while(st.find(s[j]) != st.end()) {
                st.erase(s[i]);
                i++;
            }

            st.insert(s[j]);

            longest = max(longest, j - i + 1);
        }

        return longest;
    }
};
