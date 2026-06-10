#include <bits/stdc++.h>
using namespace std;

int main() {
    int maxlen =0,l=0,r=0;
    unordered_map<char,int> hash;
    string s= "abcabcbb";
    int n=s.size();
    while(r<n){
        if(hash.find(s[r]) != hash.end()) {
            l = max(l, hash[s[r]] + 1);
        }
        int len=r-l+1;
        maxlen=max(len,maxlen);
        hash[s[r]]=r;
        r++;
    }
    cout << maxlen;
    return 0;
}