class TimeMap {
    private:
        unordered_map<string, vector<pair<int, string>>> mp;

    public:
        TimeMap() {
        }

        void set(string key, string value, int timestamp) {
            mp[key].push_back({timestamp, value});
        }

        string get(string key, int timestamp) {
            if(mp.find(key) == mp.end()) return "";

            vector<pair<int, string>> vp = mp[key];

            int s = 0;
            int e = vp.size() - 1;
            string res;

            while(s <= e) {
                int mid = s + (e - s) / 2;

                if(vp[mid].first <= timestamp) {
                    res = vp[mid].second;
                    s = mid + 1;
                } else e = mid - 1;
            }

            return res;
        }
};
