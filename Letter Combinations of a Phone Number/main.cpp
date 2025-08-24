class Solution {
    private:
        vector<string> result;
        string digits;
        int n;

        unordered_map<int, string> mp;

        void dfs(int i, string curr) {
            if(i >= n) {
                result.push_back(curr);
                return;
            }

            for(char& ch : mp[digits[i] - '0']) {
                curr.push_back(ch);
                dfs(i + 1, curr);
                curr.pop_back();
            }
        }

    public:
        Solution() {
            mp[2] = "abc";
            mp[3] = "def";
            mp[4] = "ghi";
            mp[5] = "jkl";
            mp[6] = "mno";
            mp[7] = "pqrs";
            mp[8] = "tuv";
            mp[9] = "wxyz";
        }

        vector<string> letterCombinations(string digits) {
            if(digits.size() == 0) return result;

            this->digits = digits;
            n = digits.size();

            dfs(0, "");

            return result;
        }
};
