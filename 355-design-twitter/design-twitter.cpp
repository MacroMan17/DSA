class Twitter {
private:
    struct Tweet {
        int tweetId;
        int time;
        Tweet(int id, int t) {
            tweetId = id;
            time = t;
        }
    };
    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> following;

    int timer = 0;
public:
    Twitter() {
    }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(tweetId, timer++));
    }
    vector<int> getNewsFeed(int userId) {
        vector<Tweet> allTweets;
        for (auto it : tweets[userId]) {
            allTweets.push_back(it);
        }
        for (auto it : following[userId]) {
            for (auto jt : tweets[it]) {
                allTweets.push_back(jt);
            }
        }
        sort(allTweets.begin(), allTweets.end(),
             [](const Tweet& a, const Tweet& b) {
                 return a.time < b.time;
             });
        reverse(allTweets.begin(), allTweets.end());
        vector<int> result;
        for (int i = 0; i < min(10, (int)allTweets.size()); i++) {
            result.push_back(allTweets[i].tweetId);
        }
        return result;
    }
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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