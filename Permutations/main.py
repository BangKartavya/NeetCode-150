class Solution:
    def dfs(self, i, nums):
        if i == len(nums):
            self.result.append(nums[:])
            return

        for j in range(i, self.n):
            nums[i], nums[j] = nums[j], nums[i]
            self.dfs(i + 1, nums)
            nums[i], nums[j] = nums[j], nums[i]

    def permute(self, nums: List[int]) -> List[List[int]]:
        self.n = len(nums)
        self.result = []

        self.dfs(0, nums)

        return self.result
