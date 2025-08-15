class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
            int m = nums2.size();

            if(n > m) return findMedianSortedArrays(nums2, nums1);

            int s = 0;
            int e = n;
            int total = n + m;
            int half = (total + 1) / 2;

            while(s <= e) {
                int mid1 = s + (e - s) / 2;
                int mid2 = half - mid1;

                int l1 = mid1 > 0 ? nums1[mid1 - 1] : INT_MIN;
                int r1 = mid1 < n ? nums1[mid1] : INT_MAX;
                int l2 = mid2 > 0 ? nums2[mid2 - 1] : INT_MIN;
                int r2 = mid2 < m ? nums2[mid2] : INT_MAX;

                if(l1 <= r2 && l2 <= r1) {
                    if(total % 2) return max(l1, l2);

                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else if(l1 >= r2) {
                    e = mid1 - 1;
                } else s = mid1 + 1;
            }

            return -1;
        }
};
