class Solution {
    public:
        int carFleet(int target, vector<int>& position, vector<int>& speed) {
            vector<int> time;
            int n = position.size();

            vector<pair<double, double>> vp;

            for(int i = 0; i < n; i++)
                vp.push_back({position[i], speed[i]});

            sort(begin(vp), end(vp), greater<pair<double, double>>());

            double prevTime = (target - vp[0].first) / vp[0].second;
            int fleets = 1;

            for(int i = 1; i < n; i++) {
                double time = ((target - vp[i].first) / vp[i].second);

                if(time > prevTime) {
                    fleets++;
                    prevTime = time;
                }
            }

            return fleets;
        }
};
