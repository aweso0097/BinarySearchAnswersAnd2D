class Solution {
public:
  int NthRoot(int N, int M) {
       int low =1;
       int high = M;
       if(M == 0 || M == 1) return M; //edge case
       while (low <= high) {
        int mid = low +(high-low)/2;
        int value = pow(mid,N);
        if(value == M) {
            return mid;
        }
        else if (value < M) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
       }
       return -1;
    }
};
