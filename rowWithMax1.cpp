class Solution {
  public:   
  int rowWithMax1s(vector < vector < int >> & mat) {
    int max_count = 0;
    int n = mat.size();
    int m = mat[0].size();
    int index = -1;
    for(int i =0;i<n;i++) {
        int low =0;
        int high = m-1; //tracking in a row 
        int count = 0;
        while(low <= high) {
            int mid = low+(high-low)/2;
            if(mat[i][mid] == 1) {
                count = m-mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
            if (count > max_count) {
                max_count = count;
                index = i;
            }
            
        }
        return index;
  }
  
};
