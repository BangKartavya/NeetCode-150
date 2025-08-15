class Solution {
    public:
        int findMin(vector<int>& nums) {
            int n = nums.size();

            if(n == 1) return nums[0];

            int s = 0;
            int e = n - 1;

            while(s < e) {
                int mid = s + (e - s) / 2;
                int next = (mid + 1) % n;
                int prev = (mid - 1 + n) % n;

                if(nums[mid] < nums[next] && nums[mid] < nums[prev]) return nums[mid];

                else if(nums[mid] > nums[n - 1]) {
                    s = mid + 1;
                } else e = mid - 1;
            }

            return nums[s];
        }
};
