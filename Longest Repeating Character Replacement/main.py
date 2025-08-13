class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        charSet = set(s)
        n = len(s)
        maxi = 0

        for ch in charSet:
            count = 0
            i = 0
            j = 0

            while(j < n):
                count += (s[j] == ch)

                while((j-i+1) - count > k):
                    count -= (s[i] == ch)
                    i+=1
                
                maxi = max(maxi,j-i+1)
                j+=1
        
        return maxi