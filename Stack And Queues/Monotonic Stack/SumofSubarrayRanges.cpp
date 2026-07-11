#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getNSE(vector<int>& arr,int n){
        vector<int> result(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            result[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return result;
    }

    vector<int> getPSE(vector<int>& arr,int n){
        vector<int> result(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            result[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return result;
    }

    vector<int> getNGE(vector<int>& arr,int n){
        vector<int> result(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            result[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return result;
    }

    vector<int> getPGE(vector<int>& arr,int n){
        vector<int> result(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] < arr[i]){
                st.pop();
            }
            result[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return result;
    }

    long long sumSubarrayMin(vector<int>& arr){
        int n = arr.size();
        vector<int> nse = getNSE(arr,n);
        vector<int> pse = getPSE(arr,n);

        long long sum =0;

        for(int i=0;i<n;i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;

            sum += left * right * 1LL * arr[i];
        }
        return sum;
    }

    long long sumSubarrayMax(vector<int>& arr){
        int n = arr.size();
        vector<int> nge = getNGE(arr,n);
        vector<int> pge = getPGE(arr,n);

        long long sum =0;

        for(int i=0;i<n;i++){
            long long left = i - pge[i];
            long long right = nge[i] - i;

            sum += left * right * 1LL * arr[i];
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums){
        return sumSubarrayMax(nums) - sumSubarrayMin(nums);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }

    Solution obj;
    cout << obj.subArrayRanges(nums) << endl;

    return 0;
}