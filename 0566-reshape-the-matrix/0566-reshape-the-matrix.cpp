class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m= mat.size();
        int n= mat[0].size();

        if(m*n != r*c){
            return mat;
        }

        vector<vector<int>> res(r,vector<int>(c));
        
        vector<int>temp(m*n);
        int ind=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp[ind++]=mat[i][j];
            }
        }
        ind=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                res[i][j]=temp[ind++];
            }
        }

        return res;
        
    }
};