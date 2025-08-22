class Solution {
private:
    int getDist(vector<int> point) {
        return point[0]*point[0] + point[1]*point[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        int n = points.size();

        for(int i = 0;i<min(n,k);i++) {
            pq.push({getDist(points[i]),i});
        }

        for(int i = k;i<n;i++) {
            if(pq.top().first > getDist(points[i])) {
                pq.pop();
                pq.push({getDist(points[i]),i});
            }
        }

        vector<vector<int>> result;

        while(!pq.empty()) {
            result.push_back(points[pq.top().second]);
            pq.pop();
        }

        return result;
        

    }
};
