#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st; // {price, span}

    StockSpanner() {
    }

    int next(int price) {
        int span = 1;

        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});
        return span;
    }
};

int main() {
    StockSpanner obj;

    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    cout << "Prices: ";
    for (int p : prices)
        cout << p << " ";
    cout << "\n\nSpans:\n";

    for (int p : prices) {
        cout << "Price = " << p
             << ", Span = " << obj.next(p) << endl;
    }

    return 0;
}