class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n = len(nums1)
        m = len(nums2)

        if(n > m):
            return self.findMedianSortedArrays(nums2,nums1)
        
        s = 0
        e = n
        total = n+m
        half = (total+1)//2

        while(s <= e):
            mid1 = s + (e-s)//2
            mid2 = half - mid1

            l1 = float('-inf')
            r1 = float('inf')
            l2 = float('-inf')
            r2 = float('inf')

            if(mid1 > 0):
                l1 = nums1[mid1-1]
            if(mid1 < n):
                r1 = nums1[mid1]
            if(mid2 > 0):
                l2 = nums2[mid2-1]
            if(mid2 < m):
                r2 = nums2[mid2]
            
            if(l1 <= r2 and l2 <= r1):
                if(total%2): return max(l1,l2)

                return (max(l1,l2) + min(r1,r2))/2
            elif(l1 >= r2):
                e = mid1-1
            else:
                s = mid1+1
        
        return -1