class Solution {
public:
    bool helper(vector<int> &nums, int k,int minDist) {
        int cows = 1;
        int lastPos = nums[0];
        for(int i =1;i<nums.size();i++) {
            if(nums[i]-lastPos >= minDist) {
                cows++;
                lastPos = nums[i];
            }
            if(cows >= k) return true;
        }
        return false;
    } 
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 1;
        int low = 1;
        int high = nums[n-1]-nums[0];
        while(low <= high) {
            int mid = low+(high-low)/2;
            if(helper(nums,k,mid) == true) {
                ans = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
    }
};
