class Solution:
    def solve(self,openParen,closeParen,curr):
        if(openParen == self.n and closeParen == self.n):
            self.result.append(curr)
        
        if(openParen < self.n):
            self.solve(openParen+1,closeParen,curr+"(")
        
        if(closeParen < openParen):
            self.solve(openParen,closeParen+1,curr+")")


    def generateParenthesis(self, n: int) -> List[str]:
        self.n = n
        self.result = []

        self.solve(0,0,"")

        return self.result