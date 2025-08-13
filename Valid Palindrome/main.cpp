class Solution {
    public:
        bool isPalindrome(string s) {
            int n = s.size();
            int i = 0;
            int j = n - 1;

            while(i <= j) {
                if(!isalpha(s[i]) && !isdigit(s[i])) {
                    i++;
                    continue;
                }

                if(!isalpha(s[j]) && !isdigit(s[j])) {
                    j--;
                    continue;
                }

                if(tolower(s[i++]) != tolower(s[j--])) return false;
            }

            return true;
        }
};
