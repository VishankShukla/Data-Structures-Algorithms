#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Count frequency of each character
        for (char ch : s) {
            freq[ch]++;
        }

        // Max Heap -> {frequency, character}
        priority_queue<pair<int, char>> pq;

        for (auto &it : freq) {
            pq.push({it.second, it.first});
        }

        string ans = "";

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int count = top.first;
            char ch = top.second;

            while (count--) {
                ans += ch;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Output: " << obj.frequencySort(s) << endl;

    return 0;
}