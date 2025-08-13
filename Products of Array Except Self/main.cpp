class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            vector<int> result(n);

            int prod = 1;
            int zeros = -1;

            for(int i = 0; i < n; i++) {
                if(nums[i] == 0) {
                    if(zeros != -1) return result;

                    zeros = i;
                }

                else {
                    prod *= nums[i];
                }
            }

            if(zeros != -1) {
                result[zeros] = prod;
                return result;
            }

            for(int i = 0; i < n; i++) {
                result[i] = prod / nums[i];
            }

            return result;
        }
};
