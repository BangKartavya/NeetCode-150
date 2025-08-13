#include <cstring>

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> result;
            unordered_map<string, vector<string>> mp;

            for(string& str : strs) {
                int freq[26];
                memset(freq, 0, sizeof(freq));

                for(char& ch : str)
                    freq[ch - 'a']++;
                string temp;

                for(int i = 0; i < 26; i++) {
                    while(freq[i]) {
                        temp += (i + 'a');
                        freq[i]--;
                    }
                }

                mp[temp].push_back(str);
            }

            for(auto& it : mp) {
                result.push_back(it.second);
            }

            return result;
        }
};
