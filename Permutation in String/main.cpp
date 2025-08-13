#include <cstring>

class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            int n = s1.size();
            int m = s2.size();

            unordered_map<char, int> mp;
            unordered_map<char, int> mp2;

            for(char& ch : s1)
                mp[ch]++;

            int i = 0;
            int j = n - 1;

            for(int k = i; k <= j; k++) {
                mp2[s2[k]]++;
            }

            while(j < m) {
                if(mp == mp2) return true;

                j++;
                mp2[s2[j]]++;

                mp2[s2[i]]--;
                if(mp2[s2[i]] == 0) mp2.erase(s2[i]);
                i++;
            }

            return false;
        }
};
