from heapq import heapify,heappush,heappop

class MedianFinder:

    def __init__(self):
        self.maxHeap = []
        heapify(self.maxHeap)
        self.minHeap = []
        heapify(self.minHeap)


    def addNum(self, num: int) -> None:
        if(len(self.minHeap) and self.minHeap[0] < num):
            heappush(self.minHeap, num)
        else:
            heappush(self.maxHeap,-num)
        
        n = len(self.maxHeap)
        m = len(self.minHeap)

        if(n - m > 1):
            heappush(self.minHeap,-heappop(self.maxHeap))
        elif(m - n > 1):
            heappush(self.maxHeap,-heappop(self.minHeap))


    def findMedian(self) -> float:
        if(len(self.minHeap) == len(self.maxHeap)):
            n1 = self.minHeap[0]
            n2 = -self.maxHeap[0]

            return (n1+n2)/2
        
        if(len(self.minHeap) > len(self.maxHeap)): return self.minHeap[0]

        return -self.maxHeap[0]
        