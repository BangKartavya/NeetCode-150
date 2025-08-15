class Solution {
    private:
        vector<int> piles;
        int n;
        int h;

        bool isValid(int eatingSpeed) {
            double time = 0;

            for(int& i : piles) {
                time += ceil((double)i / (double)eatingSpeed);
            }

            return time <= h;
        }

    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            this->piles = piles;
            this->h = h;
            n = piles.size();

            int s = 1;
            int e = 1e9;
            int ans = 0;

            while(s <= e) {
                int mid = s + (e - s) / 2;

                if(isValid(mid)) {
                    e = mid - 1;
                    ans = mid;
                } else s = mid + 1;
            }

            return ans;
        }
};
