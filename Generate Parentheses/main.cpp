class Solution {
    private:
        vector<string> result;
        int n;

        void solve(int openParen, int closeParen, string curr) {
            if(openParen == n && closeParen == n) {
                result.push_back(curr);
                return;
            }

            if(openParen < n) {
                solve(openParen + 1, closeParen, curr + "(");
            }

            if(closeParen < openParen) {
                solve(openParen, closeParen + 1, curr + ")");
            }
        }

    public:
        vector<string> generateParenthesis(int n) {
            this->n = n;
            solve(0, 0, "");

            return result;
        }
};
