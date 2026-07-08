class Solution {
public:
    bool helper(vector<int> &a, int k, int maxSum) {
        int sum = a[0];
        int split = 1;
        
        for(int i = 1; i < a.size(); i++) {
            if(a[i] + sum <= maxSum) {
                sum += a[i]; // Add element to the current subarray split
            }
            else {
                split++;     // Start a new subarray split
                sum = a[i];  // The new split starts with this current element
            }
        }
        
        return split <= k;
    }

    int largestSubarraySumMinimized(vector<int> &a, int k) {
        int low = *max_element(a.begin(), a.end());
        int high = accumulate(a.begin(), a.end(), 0);
        int ans = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(helper(a, k, mid) == true) {
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
