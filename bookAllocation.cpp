class Solution {
public:
    bool helper(vector<int> &nums, int m, int maxPage) {
        int student = 1;
        int currentPos = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if(currentPos + nums[i] <= maxPage) {
                currentPos += nums[i];
            }
            else {
                student++;
                currentPos = nums[i]; 
            }
        }
        
        // Return true ONLY if we used 'm' or fewer students
        return student <= m; 
    }

    int findPages(vector<int> &nums, int m)  {
        
        if (m > nums.size()) return -1; 
        
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(helper(nums, m, mid) == true) {
                ans = mid;
                high = mid - 1; 
            }
            else {
                low = mid + 1;  
            }
        }
        return ans;
    }
};
