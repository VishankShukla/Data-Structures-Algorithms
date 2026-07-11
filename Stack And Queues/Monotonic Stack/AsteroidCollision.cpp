#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> st;

        for (int i = 0; i < n; i++) {
            if (asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            } else {
                while (!st.empty() && st.back() > 0 &&
                       st.back() < abs(asteroids[i])) {
                    st.pop_back();
                }

                if (!st.empty() && st.back() == abs(asteroids[i])) {
                    st.pop_back();
                }
                else if (st.empty() || st.back() < 0) {
                    st.push_back(asteroids[i]);
                }
            }
        }

        return st;
    }
};

int main() {
    int n;
    cout << "Enter number of asteroids: ";
    cin >> n;

    vector<int> asteroids(n);

    cout << "Enter asteroid values: ";
    for (int i = 0; i < n; i++) {
        cin >> asteroids[i];
    }

    Solution obj;
    vector<int> ans = obj.asteroidCollision(asteroids);

    cout << "Remaining asteroids: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}