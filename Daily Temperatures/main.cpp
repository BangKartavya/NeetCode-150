class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temps) {
            stack<int> stk;
            int n = temps.size();
            vector<int> result(n, 0);

            for(int i = n - 1; i >= 0; i--) {
                if(stk.empty()) {
                    result[i] = 0;
                    stk.push(i);
                }

                else {
                    while(!stk.empty() && temps[stk.top()] <= temps[i]) {
                        stk.pop();
                    }

                    result[i] = (stk.empty()) ? 0 : stk.top() - i;

                    stk.push(i);
                }
            }

            return result;
        }
};
