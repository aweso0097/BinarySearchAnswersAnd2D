class Solution {
public:
    bool isPossible(vector<int> &nums, int day, int k, int m) {
        int count = 0;
        int bouquet = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= day) {
                count++;
            }
            else {
                bouquet += count / k;
                count = 0;
            }
        }
        bouquet += count / k; 
        
        return bouquet >= m;
    }

    int roseGarden(int n, vector<int> nums, int k, int m) {
        // Overflow protection: total flowers needed can exceed integer limits
        if ((long long)m * k > n) {
            return -1;
        }

        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isPossible(nums, mid, k, m)) {
                ans = mid;         // Record the potential minimum day
                high = mid - 1;    // Look left for a smaller valid day
            }
            else {
                low = mid + 1;     // Look right because 'mid' days aren't enough
            }
        }
        return ans;
    }
};
