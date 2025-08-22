class Solution {
    private:
        vector<vector<int>> result;
        int n;

        void dfs(int i, vector<int> nums) {
            if(i == nums.size()) {
                result.push_back(nums);
                return;
            }

            for(int j = i; j < n; j++) {
                swap(nums[i], nums[j]);
                dfs(i + 1, nums);
                swap(nums[i], nums[j]);
            }
        }

    public:
        vector<vector<int>> permute(vector<int>& nums) {
            n = nums.size();

            dfs(0, nums);

            return result;
        }
};
