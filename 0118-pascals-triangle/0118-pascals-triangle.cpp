class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pasTri(numRows);
        for(int i=0;i<numRows;i++){

            pasTri[i].resize(i+1);

            for(int j=0;j<=i;j++){
                if(j==0 || j == i){
                    pasTri[i][j]=1;
                }
                else{
                    pasTri[i][j]= pasTri[i-1][j-1] + pasTri[i-1][j];
                }
            }
        }
        return pasTri;
    }
};