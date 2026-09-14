class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
  
        int m = matrix.size();
        int n = matrix[0].size();

        int startRow = 0;
        int lastRow = m-1;
        
        while(startRow<=lastRow){
            int midRow = startRow+(lastRow-startRow)/2;

            if(matrix[midRow][0]<=target && matrix[midRow][n-1]>=target){
                return searchIndex(matrix,midRow,target);
            }

            if(matrix[midRow][0]>target)  lastRow=midRow-1;

            if(matrix[midRow][n-1]<target) startRow=midRow+1;
        }

        return false;
    }


    bool searchIndex(vector<vector<int>>&matrix,int Row,int target){
        int n=matrix[0].size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid = low+(high-low)/2;

            if(matrix[Row][mid]==target) return true;

            if(matrix[Row][mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return false;
    }
};