#include <cstring>

class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            int freq[26];
            memset(freq, 0, sizeof(freq));

            for(char& task : tasks)
                freq[task - 'A']++;

            priority_queue<int> pq;

            for(int i = 0; i < 26; i++)
                if(freq[i] > 0) pq.push(freq[i]);

            queue<pair<int, int>> q; // [freq,time to execute]

            int time = 0;

            while(!pq.empty() || !q.empty()) {
                time++;
                if(pq.empty()) {
                    time = q.front().second;
                } else {
                    int cnt = pq.top() - 1;
                    pq.pop();
                    if(cnt > 0) {
                        q.push({cnt, time + n});
                    }
                }

                if(!q.empty() && q.front().second == time) {
                    pq.push(q.front().first);
                    q.pop();
                }
            }

            return time;
        }
};
