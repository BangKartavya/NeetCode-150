class KthLargest {
    private:
        priority_queue<int, vector<int>, greater<int>> pq;
        int k;

    public:
        KthLargest(int k, vector<int>& nums) {
            int n = nums.size();
            for(int i = 0; i < min(k, n); i++)
                pq.push(nums[i]);
            this->k = k;

            for(int i = k; i < n; i++) {
                if(pq.top() < nums[i]) {
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }

        int add(int val) {
            if(pq.size() < k) {
                pq.push(val);
                return pq.top();
            }
            if(pq.top() < val) {
                pq.pop();
                pq.push(val);
            }

            return pq.top();
        }
};
