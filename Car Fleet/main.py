class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        vp = []

        for i in range(len(position)):
            vp.append((position[i],speed[i]))
        
        vp.sort()
        vp.reverse()

        prevTime = (target-vp[0][0])/vp[0][1]
        fleets = 1

        for i in range(1,len(vp)):
            time = (target-vp[i][0])/vp[i][1]

            if(time > prevTime):
                prevTime = time
                fleets+=1
        
        return fleets