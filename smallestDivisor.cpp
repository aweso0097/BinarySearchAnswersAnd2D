class Solution {
public:
  bool divisor(vector<int> &nums,int limit,int num) {
    int res = 0;
    for(int i = 0;i < nums.size();i++) {
        res += ceil(nums[i]/num);
    }
    if(res <= limit) {
        return true;
    }
    else {
        return false;
    }
  } 
  int smallestDivisor(vector<int> &nums, int limit) {
       int low =1;
       int high = *max_element(nums.begin(),nums.end());
       int ans;
       while(low <= high) {
            int mid = low + (high-low)/2;
            if(divisor(nums,limit,mid) == true) {
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
