#include<bits/stdc++.h>
using namespace std;

vector<int> UnionArray(vector<int> v1, vector<int> v2){
    int n1 = v1.size();
    int n2 = v2.size();
    int i = 0, j = 0;
    vector<int> Union;

    while(i < n1 && j < n2){
        if(v1[i] <= v2[j]){
            if(Union.empty() || Union.back() != v1[i]){
                Union.push_back(v1[i]);
            }
            i++;
        } else {
            if(Union.empty() || Union.back() != v2[j]){
                Union.push_back(v2[j]);
            }
            j++;
        }
    }

    while(i < n1){
        if(Union.empty() || Union.back() != v1[i]){
            Union.push_back(v1[i]);
        }
        i++;
    }

    while(j < n2){
        if(Union.empty() || Union.back() != v2[j]){
            Union.push_back(v2[j]);
        }
        j++;
    }

    return Union;
}

int main(){
   vector<int> v1 ={1,2,3,4,5};
   vector<int> v2 ={2,2,3,4,5,6};

   vector<int> result = UnionArray(v1,v2);

   for(auto it : result){
       cout << it << " ";
   }
}