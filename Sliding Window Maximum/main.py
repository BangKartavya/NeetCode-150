from heapq import heapify,heappush,heappop

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        pq = []
        heapify(pq)
        res = []

        i = 0
        j = k-1
        n = len(nums)

        for z in range(i,j+1):
            heappush(pq,(-nums[z],z))

        while j < n:
            top = heappop(pq)
            res.append(-top[0])
            heappush(pq,top)

            j+=1
            if(j < n):
                heappush(pq,(-nums[j],j))
            i+=1
            if(i < n):
                heappush(pq,(-nums[i],i))

            top = heappop(pq)

            while(pq and top[1] < i):
                top = heappop(pq)
            
            heappush(pq,top)
        
        return res