class Solution {
    private:
        vector<vector<int>> result;
        int target;
        vector<int> nums;
        int n;

        void dfs(int i, vector<int> curr, int currSum) {
            if(i >= n) return;

            if(currSum == target) {
                result.push_back(curr);
                return;
            }

            if(currSum > target) return;

            // take

            currSum += nums[i];
            curr.push_back(nums[i]);

            dfs(i, curr, currSum);

            currSum -= nums[i];
            curr.pop_back();

            // notake

            dfs(i + 1, curr, currSum);
        }

    public:
        vector<vector<int>> combinationSum(vector<int>& nums, int target) {
            this->nums = nums;
            n = nums.size();
            this->target = target;

            dfs(0, {}, 0);

            return result;
        }
};
