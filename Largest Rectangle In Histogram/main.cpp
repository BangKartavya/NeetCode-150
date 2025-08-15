class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            stack<pair<int, int>> stk;
            int n = heights.size();
            int maxi = 0;

            for(int i = 0; i < n; i++) {
                int start = i;

                while(!stk.empty() && stk.top().second > heights[i]) {
                    int idx = stk.top().first;
                    int height = stk.top().second;
                    stk.pop();

                    maxi = max(maxi, height * (i - idx));
                    start = idx;
                }

                stk.push({start, heights[i]});
            }

            while(!stk.empty()) {
                int idx = stk.top().first;
                int height = stk.top().second;
                stk.pop();

                maxi = max(maxi, height * (n - idx));
            }

            return maxi;
        }
};
