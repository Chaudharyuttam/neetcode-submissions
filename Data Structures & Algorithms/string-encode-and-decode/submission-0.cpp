class Solution {
public:

    string encode(vector<string>& strs) {

        string result = "";

        for(string s : strs) {
            result += to_string(s.length()) + "#" + s;
        }

        return result;
    }

    vector<string> decode(string s) {

        vector<string> result;

        int i = 0;

        while(i < s.length()) {

            int j = i;

            // Find '#'
            while(s[j] != '#') {
                j++;
            }

            // Get length
            int len = stoi(s.substr(i, j - i));

            // Move after '#'
            j++;

            // Extract string
            string word = s.substr(j, len);

            result.push_back(word);

            // Move to next encoded string
            i = j + len;
        }

        return result;
    }
};