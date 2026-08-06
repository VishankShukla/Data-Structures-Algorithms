#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;

        // Count frequency
        for (char ch : tasks) {
            freq[ch]++;
        }

        // Max Heap (only frequencies)
        priority_queue<int> pq;

        for (auto &it : freq) {
            pq.push(it.second);
        }

        // {remaining frequency, available time}
        queue<pair<int, int>> q;

        int time = 0;

        while (!pq.empty() || !q.empty()) {
            time++;

            // Task available ho gaya
            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }

            // Execute task
            if (!pq.empty()) {
                int count = pq.top();
                pq.pop();

                count--;

                // Task abhi bhi bacha hai
                if (count > 0) {
                    q.push({count, time + n + 1});
                }
            }
        }

        return time;
    }
};

int main() {
    Solution obj;

    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;

    cout << "Minimum intervals: ";
    cout << obj.leastInterval(tasks, n) << endl;

    return 0;
}