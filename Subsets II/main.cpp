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

            // take
            curr.push_back(nums[i]);
            dfs(i + 1, curr);
            curr.pop_back();

            // no take

            while(i + 1 < n && nums[i] == nums[i + 1])
                i++;

            dfs(i + 1, curr);
        }

    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(begin(nums), end(nums));
            this->nums = nums;
            n = nums.size();

            dfs(0, {});

            return result;
        }
};
