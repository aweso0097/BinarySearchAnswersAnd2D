class Solution {
public:
int totalHours(vector<int>nums,int rate) {
    int totalh = 0;
    for(int i =0;i <nums.size();i++) {
        totalh += ceil((double)nums[i]/rate);
    }
    return totalh;
}
int minimumRateToEatBananas(vector<int> nums, int h) {
    int low = 1;
    int high = *max_element(nums.begin(),nums.end());
    int ans =0;
    while(low <= high) {
        int mid = low+(high-low)/2;
        int res = totalHours(nums,mid);
        if(res <= h) {
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return ans;
    }
};
