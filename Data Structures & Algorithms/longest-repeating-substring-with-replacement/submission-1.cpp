class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.length();
        int ans = 0;

        vector<int> count(26, 0);

        int i = 0;
        int maxCount = 0;

        for (int j = 0; j < n; j++) {

            // Increase frequency of current character
            count[s[j] - 'A']++;

            // Maximum frequency in current window
            maxCount = max(maxCount, count[s[j] - 'A']);

            // Number of characters we need to replace
            if (j - i + 1 - maxCount > k) {
                count[s[i] - 'A']--;
                i++;
            }

            // Update answer
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};