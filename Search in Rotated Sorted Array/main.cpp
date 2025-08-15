class Solution {
    private:
        vector<int> nums;
        int n;
        int minIdx() {
            int s = 0;
            int e = n - 1;

            while(s <= e) {
                int mid = s + (e - s) / 2;
                int next = (mid + 1) % n;
                int prev = (mid - 1 + n) % n;

                if(nums[mid] < nums[prev] && nums[mid] < nums[next]) return mid;

                else if(nums[mid] > nums[n - 1]) {
                    s = mid + 1;
                } else e = mid - 1;
            }

            return -1;
        }

    public:
        int search(vector<int>& nums, int target) {
            this->nums = nums;
            n = nums.size();

            int piv = minIdx();
            int s = 0;
            int e = piv - 1;

            while(s <= e) {
                int mid = s + (e - s) / 2;

                if(nums[mid] == target) return mid;
                else if(nums[mid] < target) s = mid + 1;
                else e = mid - 1;
            }

            s = piv;
            e = n - 1;

            while(s <= e) {
                int mid = s + (e - s) / 2;

                if(nums[mid] == target) return mid;
                else if(nums[mid] < target) s = mid + 1;
                else e = mid - 1;
            }

            return -1;
        }
};
