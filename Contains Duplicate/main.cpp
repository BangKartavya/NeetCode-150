class Solution {
    public:
        bool hasDuplicate(vector<int>& nums) {
            unordered_set<int> s;

            for(int& i : nums) {
                if(s.find(i) != s.end()) return true;
                s.insert(i);
            }

            return false;
        }
};