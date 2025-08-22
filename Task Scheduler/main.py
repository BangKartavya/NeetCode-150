from heapq import heapify, heappush, heappop

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freq = [0] * 26

        for t in tasks:
            freq[ord(t)-ord('A')] += 1
        
        pq = []
        heapify(pq)

        for i in freq:
            if(i > 0): heappush(pq,-i)
        
        q = deque()
        time = 0

        while(pq or q):
            time += 1

            if(not pq):
                time = q[0][1]
            else:
                cnt = -heappop(pq)-1
                if(cnt > 0):
                    q.append((cnt,time+n))

            if(q and q[0][1] == time):
                heappush(pq,-q[0][0])
                q.popleft()
        
        return time
