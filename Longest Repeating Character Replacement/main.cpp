class Solution {
    public:
        int characterReplacement(string s, int k) {
            int n = s.size();
            unordered_set<char> set(begin(s), end(s));
            int maxi = 0;
            for(const char& ch : set) {
                int count = 0;
                int i = 0;
                int j = 0;

                while(j < n) {
                    count += (s[j] == ch);

                    while((j - i + 1) - count > k) {
                        count -= (s[i] == ch);
                        i++;
                    }

                    maxi = max(maxi, j - i + 1);
                    j++;
                }
            }

            return maxi;
        }
};
