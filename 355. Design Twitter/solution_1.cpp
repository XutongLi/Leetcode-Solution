class Twitter {
private:
    unordered_map<int, unordered_set<int>> mp;  //follower - followee
    vector<pair<int, int>> tweet;
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {   //O(1)
        tweet.push_back(make_pair(userId, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {   //O(n)
        int cnt = 0;
        vector<int> res;
        for (int i = tweet.size() - 1; i >= 0; -- i) {
            if (userId == tweet[i].first || mp[userId].find(tweet[i].first) != mp[userId].end()) {
                res.push_back(tweet[i].second);
                ++ cnt;
            }
            if (cnt == 10)
                break;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {   //O(1)
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