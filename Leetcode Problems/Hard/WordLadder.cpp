
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if(st.find(endWord) == st.end()) return 0;

        queue<pair<string, int>> que;

        que.push({beginWord, 1});
        st.erase(beginWord);

        while(!que.empty()) {

            string w = que.front().first;
            int steps = que.front().second;
            que.pop();

            if(w == endWord) return steps;

            for(int i = 0; i < beginWord.size(); i++) {

                string original = w;

                for(char ch = 'a'; ch <= 'z'; ch++) {

                    w[i] = ch;

                    if(st.find(w) != st.end()) {

                        st.erase(w);
                        que.push({w, steps + 1});
                    }
                }

                w = original;
            }
        }

        return 0;
    }
};

int main() {

    Solution sol;

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {
        "hot", "dot", "dog", "lot", "log", "cog"
    };

    int ans = sol.ladderLength(beginWord, endWord, wordList);

    cout << "Minimum transformation sequence length: " << ans << endl;

    return 0;
}
