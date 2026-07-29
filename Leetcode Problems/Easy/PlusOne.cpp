#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;

        while (i >= 0) {

            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
            i--;
        }

        // All digits were 9
        digits[0] = 1;
        digits.push_back(0);

        return digits;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter number of digits: ";
    cin >> n;

    vector<int> digits(n);

    cout << "Enter digits: ";
    for (int i = 0; i < n; i++) {
        cin >> digits[i];
    }

    vector<int> ans = obj.plusOne(digits);

    cout << "Result: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}