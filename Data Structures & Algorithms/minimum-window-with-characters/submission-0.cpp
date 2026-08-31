class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.length();
        int m = t.length();

        if (m > n) return "";

        unordered_map<char, int> mp;

        int i = 0;
        int countReq = m;

        int windowSize = INT_MAX;
        int start_i = 0;

        // Store required characters
        for (char &ch : t) {
            mp[ch]++;
        }

        // Sliding window
        for (int j = 0; j < n; j++) {

            // Include s[j]
            if (mp[s[j]] > 0) {
                countReq--;
            }

            mp[s[j]]--;

            // Shrink window
            while (countReq == 0) {

                int currWindowSize = j - i + 1;

                // Store minimum window
                if (currWindowSize < windowSize) {
                    windowSize = currWindowSize;
                    start_i = i;
                }

                // Remove s[i]
                mp[s[i]]++;

                if (mp[s[i]] > 0) {
                    countReq++;
                }

                i++;
            }
        }

        return windowSize == INT_MAX
                   ? ""
                   : s.substr(start_i, windowSize);
    }
};