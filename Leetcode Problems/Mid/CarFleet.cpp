#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = speed.size();

        vector<pair<int, int>> cars;

        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end());

        stack<double> st;

        for (int i = n - 1; i >= 0; i--) {

            double time = (double)(target - cars[i].first) / cars[i].second;

            if (st.empty() || time > st.top()) {
                st.push(time);
            }
        }

        return st.size();
    }
};

int main() {

    int target = 12;

    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};

    Solution obj;

    int ans = obj.carFleet(target, position, speed);

    cout << "Number of Car Fleets = " << ans << endl;

    return 0;
}