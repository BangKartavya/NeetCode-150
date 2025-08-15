class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        stk = []
        maxi = 0
        
        for i in range(n):
            start = i

            while(stk and stk[-1][1] > heights[i]):
                height = stk[-1][1]
                idx = stk[-1][0]
                stk.pop()

                maxi = max(maxi,height * (i-idx))
                start = idx
            
            stk.append((start,heights[i]))

        while(stk):
            height = stk[-1][1]
            idx = stk[-1][0]
            stk.pop()

            maxi = max(maxi,height * (n-idx))
        
        return maxi