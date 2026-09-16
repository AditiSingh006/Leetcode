class Twitter {
public:
    // user -> list of {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    // user -> set of users they follow
    unordered_map<int, unordered_set<int>> following;

    int time;

    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        // max heap: {time, tweetId}
        priority_queue<pair<int, int>> pq;

        // Include user's own tweets
        for (auto tweet : tweets[userId]) {
            pq.push(tweet);
        }

        // Include tweets of followed users
        for (int followee : following[userId]) {
            for (auto tweet : tweets[followee]) {
                pq.push(tweet);
            }
        }

        vector<int> ans;

        // Get 10 most recent tweets
        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
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