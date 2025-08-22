class Solution {
    private:
        vector<vector<int>> result;
        vector<int> nums;
        int n;

        void dfs(int i, vector<int> curr) {
            if(i >= n) {
                result.push_back(curr);
                return;
            }

            // no take
            dfs(i + 1, curr);

            // take
            curr.push_back(nums[i]);
            dfs(i + 1, curr);
        }

    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            this->nums = nums;
            n = nums.size();

            dfs(0, {});

            return result;
        }
};
