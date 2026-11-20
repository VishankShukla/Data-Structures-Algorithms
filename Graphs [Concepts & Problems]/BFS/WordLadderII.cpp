
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<vector<string>> que;
        que.push({beginWord});

        st.erase(beginWord);

        vector<vector<string>> ans;

        int n = beginWord.size();

        while (!que.empty()) {
            vector<string> temp;
            int size = que.size();
            bool found = false;

            for (int k = 0; k < size; k++) {
                vector<string> list = que.front();
                que.pop();

                int ls = list.size();

                string w = list[ls - 1];

                if (w == endWord) {
                    ans.push_back(list);
                    found = true;
                    continue;
                }

                for (int i = 0; i < n; i++) {
                    string original = w;

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        w[i] = ch;

                        if (st.find(w) != st.end()) {
                            list.push_back(w);
                            que.push(list);
                            list.pop_back();

                            temp.push_back(w);
                        }
                    }

                    w = original;
                }
            }

            for (string s : temp) {
                st.erase(s);
            }

            if (found) break;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {
        "hot", "dot", "dog", "lot", "log", "cog"
    };

    vector<vector<string>> ans =
        obj.findLadders(beginWord, endWord, wordList);

    cout << "Shortest Transformation Sequences:\n";

    for (auto path : ans) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];

            if (i != path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }

    return 0;
}
