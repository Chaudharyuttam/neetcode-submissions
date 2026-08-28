class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if (n1 > n2) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        int l = 0;
        for (int i = 0; i < n1; i++) {
            freq1[s1[i] - 'a']++;
        }

        for (int r = 0; r < n2; r++) {

            freq2[s2[r] - 'a']++;

            if (r - l + 1 > n1) {
                freq2[s2[l] - 'a']--;
                l++;
            }
            
            if (freq1 == freq2) {
                return true;
            }
        }

        return false;
    }
};