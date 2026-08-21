class Solution {
public:
    bool isAlphanumeric(char ch){
        if((ch >= '0' && ch <= '9')|| tolower(ch) >= 'a' && tolower(ch) <= 'z'){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int n = s.length();
        int start = 0, end = n - 1;

        while(start < end){
            if(!isAlphanumeric(s[start])){
                start++;
                continue;
            }
            if(!isAlphanumeric(s[end])){
                end--;
                continue;
            }
            if(tolower(s[start]) != tolower(s[end])){
               return false;
            }
            else{
                start++;
                end--;
            }
        }
        return true;
    }
};
