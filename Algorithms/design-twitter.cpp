// 355. Design Twitter
// https://leetcode.com/problems/design-twitter/

/*
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.
Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
*/

class Twitter {
public:
	/** Initialize your data structure here. */
	Twitter() {
		time = 0;
		h1.clear();
		h2.clear();
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		while (h2.count(userId) and h2.at(userId).size() >= 10) {
			h2.at(userId).pop_back();
		}
		Tweet * tweet = new Tweet(time, userId, tweetId);
		++time;
		h2[userId].push_front(tweet);
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		vector<int> result;
		priority_queue<array<list<Tweet*>::iterator, 2>, vector<array<list<Tweet*>::iterator, 2>>, Comp> pq;
		if (h2.count(userId) and !h2.at(userId).empty()) {
			pq.push({begin(h2.at(userId)), end(h2.at(userId))});
		}
		if (h1.count(userId)) {
			for (const auto & i : h1.at(userId)) {
				if (i != userId and h2.count(i) and !h2.at(i).empty()) {
					pq.push({begin(h2.at(i)), end(h2.at(i))});
				}
			}
		}
		while (result.size() < 10 and !pq.empty()) {
			array<list<Tweet*>::iterator, 2> top = pq.top();
			pq.pop();
			result.push_back((*(top[0]))->tweetId);
			++top[0];
			if (top[0] != top[1]) {
				pq.push(top);
			}
		}
		return result;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		h1[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (h1.count(followerId) and h1.at(followerId).count(followeeId)) {
			h1.at(followerId).erase(followeeId);
			if (h1.at(followerId).empty()) {
				h1.erase(followerId);
			}
		}
	}
private:
	struct Tweet {
		int time, userId, tweetId;
		Tweet(int time, int userId, int tweetId) {
			this->time = time;
			this->userId = userId;
			this->tweetId = tweetId;
		}
	};
	struct Comp {
		bool operator() (const array<list<Tweet*>::iterator, 2> & a, const array<list<Tweet*>::iterator, 2> & b) {
			return (*(a[0]))->time < (*(b[0]))->time;
		}
	};
	int time;
	unordered_map<int, unordered_set<int>> h1;
	unordered_map<int, list<Tweet*>> h2;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */