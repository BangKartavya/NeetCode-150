class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> mp;
            int n = nums.size();

            for(int& i : nums)
                mp[i]++;

            vector<int> result;
            vector<vector<int>> freq(n + 1);

            for(auto& it : mp) {
                freq[it.second].push_back(it.first);
            }

            for(int i = n; i >= 0; i--) {
                if(!freq[i].empty()) {
                    if(k > 0) {
                        for(int& it : freq[i]) {
                            result.push_back(it);
                            k--;
                        }
                    }
                }
            }

            return result;
        }
};
