class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> s;
            int ans = 0;

            for(int& i : nums)
                s.insert(i);

            for(int& i : nums) {
                if(s.find(i - 1) == s.end()) {
                    int key = i;
                    int len = 1;

                    while(s.find(key + 1) != s.end()) {
                        key++;
                        len++;
                    }
                    ans = max(ans, len);
                }
            }

            return ans;
        }
};
