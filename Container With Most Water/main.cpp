class Solution {
        public:
            int maxArea(vector<int>& heights) {
                int n = heights.size();
                int i = 0;
                int j   = n - 1;

                int ans = 0;

                while(i <= j) {
                    ans = max( ans, min(height s[i], heigh t s[ j ]) * (j - i));

                    if(heights[i] < heights[j]) {
                        i++;
                  }
    
            return ans;
            }
};    
