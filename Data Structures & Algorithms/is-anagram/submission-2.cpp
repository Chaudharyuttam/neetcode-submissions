class Solution {
public:
    bool isAnagram(string s, string t) {
       if(s.length() != t.length()) return false;

       int freq[26] = {0};

       for(int i = 0; i < t.length(); i++){
         freq[s[i] - 'a']++;
         freq[t[i] - 'a']--;
       }
       //check if both the strings is zero
       for(int i = 0; i < 26; i++){
         if(freq[i] != 0) return false;
       }
       return true;
    }
    
};
//tc - nlogn
