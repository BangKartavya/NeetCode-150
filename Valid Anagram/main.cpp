#include <cstring>

class Solution {
    public:
        bool isAnagram(string s, string t) {
            int freq[26];
            memset(freq, 0, sizeof(freq));

            for(char& ch : s)
                freq[ch - 'a']++;
            for(char& ch : t)
                freq[ch - 'a']--;

            for(int i = 0; i < 26; i++)
                if(freq[i] != 0) return false;

            return true;
        }
};
