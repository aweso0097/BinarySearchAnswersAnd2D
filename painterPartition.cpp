class Solution {
public:
    bool helper( vector<int>& C,int A,int maxTime) {
        int time = C[0];
        int painter = 1;
        for(int i=1;i<C.size();i++) {
            if(time+C[i] <= maxTime) {
                time += C[i];
            }
            else {
                painter++;
                time = C[i];
            }
        }
            return painter <= A;
    }
    int paint(int A, int B, vector<int>& C) {
        // Your code goes here
        int low = *max_element(C.begin(),C.end());
        int high = accumulate(C.begin(),C.end(),0);
        int ans;
        while(low <= high) {
            int mid = low +(high-low)/2;
            if(helper(C,A,mid)==true) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans*B;
    }
};
