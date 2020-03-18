class Twitter {
private:
    unordered_map<int, unordered_set<int>> mp;  //follower - followee
    unordered_map<int, vector<pair<int, int>>> tw;
    long time;
public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {   //O(1)
        tw[userId].push_back(make_pair(time ++, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {   //pq
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        for (auto it = tw[userId].begin(); it != tw[userId].end(); ++ it)
            pq.push(*it);
        for (auto it = mp[userId].begin(); it != mp[userId].end(); ++ it) {
            for (auto it2 = tw[*it].begin(); it2 != tw[*it].end(); ++ it2)
                pq.push(*it2);
        }
        int cnt = 0;
        vector<int> res;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            res.push_back(p.second);
            ++ cnt;
            if (cnt == 10)
                break;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {   //O(1)
        if (followerId != followeeId)
            mp[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) { //O(1)
        mp[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */