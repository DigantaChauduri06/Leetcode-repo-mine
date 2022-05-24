// Refference : https://leetcode.com/problems/design-twitter/discuss/82847/Simple-11-lines-C%2B%2B-O(n)-solution

class Twitter {
    vector<pair<int,int>> posts;
    unordered_map<int, unordered_set<int>> track;
public:
    Twitter() { }
    
    void postTweet(int UID, int TID) {
        posts.push_back({UID, TID});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int n = posts.size();
        int cnt = 0;
        for (int i = n - 1;i >= 0 && cnt < 10;i--) {
            if (posts[i].first == userId || (track.find(userId) != track.end() && track[userId].find(posts[i].first) != track[userId].end())) {
                feed.push_back(posts[i].second);
                cnt++;
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        track[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (track.find(followerId) == track.end()) return;
        track[followerId].erase(followeeId);
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