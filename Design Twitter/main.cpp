class Twitter {
private:
    int time = 0;
    unordered_map<int,unordered_set<int>> followList;
    priority_queue<pair<int,pair<int,int>>> posts;
public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push({time,{userId,tweetId}});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        vector<pair<int,pair<int,int>>> vp;

        if(followList[userId].empty()) {
            while(!posts.empty()) {
                pair<int,pair<int,int>> top = posts.top();
                posts.pop();
                vp.push_back(top);
                
                if(top.second.first == userId) {
                    result.push_back(top.second.second);
                }
                if(result.size() == 10) break;
            }

            for(auto it: vp) posts.push(it);

            return result;
        }

        for(const int& followed: followList[userId]) {
            while(!posts.empty()) {
                pair<int,pair<int,int>> top = posts.top();
                posts.pop();
                if(top.second.first == followed || top.second.first == userId) {
                    vp.push_back(top);
                    result.push_back(top.second.second);
                }
                if(result.size() == 10) break;
            }

            if(result.size() == 10) break;
        }

        for(auto it: vp) posts.push(it);

        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
};
