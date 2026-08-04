#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {

        this->k = k;

        for (int num : nums) {

            pq.push(num);

            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {

        pq.push(val);

        if (pq.size() > k) {
            pq.pop();
        }

        return pq.top();
    }
};

int main() {

    int k;
    cout << "Enter k: ";
    cin >> k;

    int n;
    cout << "Enter size of nums: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter nums: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    KthLargest obj(k, nums);

    int q;
    cout << "Enter number of add operations: ";
    cin >> q;

    while (q--) {

        int val;
        cout << "Enter value to add: ";
        cin >> val;

        cout << "Kth Largest = " << obj.add(val) << endl;
    }

    return 0;
}