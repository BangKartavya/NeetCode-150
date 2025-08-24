class Solution {
    private:
        vector<vector<string>> result;

        string s;
        int n;

        bool isPal(const string& s) {
            int i = 0;
            int j = s.size() - 1;

            while(i < j)
                if(s[i++] != s[j--]) return false;

            return true;
        }

        void dfs(int i, vector<string> curr) {
            if(i >= n) {
                result.push_back(curr);
                return;
            }

            for(int k = i + 1; k <= n; k++) {
                string temp = s.substr(i, k - i);
                if(isPal(temp)) {
                    curr.push_back(temp);
                    dfs(k, curr);
                    curr.pop_back();
                }
            }
        }

    public:
        vector<vector<string>> partition(string s) {
            if(s.size() == 1) return {{s}};

            this->s = s;
            n = s.size();

            dfs(0, {});

            return result;
        }
};
