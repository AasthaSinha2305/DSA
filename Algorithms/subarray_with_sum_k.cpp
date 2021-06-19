#include <bits/stdc++.h>
using namespace std;

    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int currSum = 0;
        unordered_map<int, int> prevSum;
        for(int i=0; i<n; i++){
            currSum+=nums[i];
            if(currSum == k){
                res++;
            }
            if(prevSum.find(currSum - k) != prevSum.end()){
                res+=prevSum[currSum - k];
            }
            prevSum[currSum]++;
        }
        return res;   
    }

int main(){
    vector <int> nums;
    nums.push_back(-1);
    nums.push_back(-1);
    nums.push_back(1);
    int k = 0;
    cout << subarraySum(nums, k) << endl;


}