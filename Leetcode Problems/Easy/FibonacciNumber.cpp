#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        int cur = 1, prev = 0;

        for (int i = 2; i <= n; i++) {
            int temp = cur + prev;
            prev = cur;
            cur = temp;
        }

        return cur;
    }
};

int main() {
    Solution obj;
    
    int n;
    cin >> n;

    cout << obj.fib(n) << endl;

    return 0;
}