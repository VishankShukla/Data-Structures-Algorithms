#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
public:

    class Node {
    public:
        string url;
        Node* prev;
        Node* next;

        Node(string u) {
            url = u;
            prev = NULL;
            next = NULL;
        }
    };

    Node* current;

    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }

    void visit(string url) {
        Node* newNode = new Node(url);

        // Forward history remove ho jayegi
        current->next = newNode;
        newNode->prev = current;

        current = newNode;
    }

    string back(int steps) {
        while (steps > 0 && current->prev != NULL) {
            current = current->prev;
            steps--;
        }

        return current->url;
    }

    string forward(int steps) {
        while (steps > 0 && current->next != NULL) {
            current = current->next;
            steps--;
        }

        return current->url;
    }
};

int main() {

    // Homepage
    BrowserHistory* browser = new BrowserHistory("leetcode.com");

    cout << "Current: " << browser->back(0) << endl;

    // Visit google
    browser->visit("google.com");

    // Visit facebook
    browser->visit("facebook.com");

    // Visit youtube
    browser->visit("youtube.com");

    cout << "After visits: "
         << browser->back(0) << endl;

    // Back 1 step
    cout << "Back 1: "
         << browser->back(1) << endl;

    // Back 1 step
    cout << "Back 1: "
         << browser->back(1) << endl;

    // Forward 1 step
    cout << "Forward 1: "
         << browser->forward(1) << endl;

    // Visit new page
    browser->visit("linkedin.com");

    cout << "After visiting linkedin: "
         << browser->back(0) << endl;

    // Forward won't go to old youtube
    cout << "Forward 2: "
         << browser->forward(2) << endl;

    return 0;
}