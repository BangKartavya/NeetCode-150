class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n = s.size();
            int i = 0;
            int j = 0;

            int len = 0;

            unordered_map<char, int> mp;

            while(j < n) {
                cout << "i : " << i << endl;
                cout << "j : " << j << endl;
                mp[s[j]]++;

                while(i < j && mp.size() < (j - i + 1)) {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
                if(mp.size() == (j - i + 1)) {
                    len = max(len, (j - i + 1));
                }
                j++;
            }

            return len;
        }
};
