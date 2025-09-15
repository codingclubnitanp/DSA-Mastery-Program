#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> vs;
        for(int i=0;i<n;i++){
            vs.push_back({nums[i],i});
        }
        sort(vs.begin(),vs.end());
        int i = 0, j = n-1;
        while(i < j){
            int sum = vs[i].first + vs[j].first;
            if(sum == target){
                return {vs[i].second, vs[j].second};
            } else if(sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return {-1,-1};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> ans = sol.twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
