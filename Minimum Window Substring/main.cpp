#include <cstring>

class Solution {
    public:
        string minWindow(string s, string t) {
            int freq1[256];
            int freq2[256];

            int n = s.size();
            int m = t.size();

            memset(freq1, 0, sizeof(freq1));
            memset(freq2, 0, sizeof(freq2));

            for(char& ch : t)
                freq2[ch]++;

            int i = 0;
            int j = m - 1;

            for(int k = i; k <= j; k++)
                freq1[s[k]]++;

            string res;
            int len = INT_MAX;

            while(j < n) {
                int found = true;
                for(int k = 0; k < 256; k++) {
                    if(freq1[k] < freq2[k]) {
                        found = false;
                        break;
                    }
                }

                while(i <= j && found) {
                    if(len > j - i + 1) {
                        len = j - i + 1;
                        res = s.substr(i, j - i + 1);
                    }
                    freq1[s[i]]--;
                    i++;

                    for(int k = 0; k < 256; k++) {
                        if(freq1[k] < freq2[k]) {
                            found = false;
                            break;
                        }
                    }
                }

                j++;
                freq1[s[j]]++;
            }

            return res;
        }
};
