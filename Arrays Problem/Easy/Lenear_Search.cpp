#include<bits/stdc++.h>
using namespace std;
void LinearSearch(const vector<int>& arry, int s) {
    for (int i = 0; i < arry.size(); i++) {
        if (s == arry[i]) {
            cout << "Element index will be: " << i + 1 << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}
  int main(){
       vector<int> arry;
       int s,n;
       cout <<"Enter the number of element:";
       cin >> n;
       cout << "Enter the element:"<< endl;
       for(int i=0;i<n;i++){
           cin >> s;
           arry.push_back(s);
       }
       cout << "Enter the number to be search:";
       cin >> s;
       
       LinearSearch(arry,s);
       return 0;
       
       
  
}


// Best	    O(1)
// Average	O(n)
// Worst	O(n)
// Space	O(1)