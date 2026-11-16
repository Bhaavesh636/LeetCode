class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>pasTri(rowIndex+1);

        for(int i=0;i<rowIndex+1;i++){
            pasTri[i].resize(i+1);

            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    pasTri[i][j]=1;
                }

                else{
                    pasTri[i][j]= pasTri[i-1][j-1] + pasTri[i-1][j];
                }
            }
        }

        return pasTri[rowIndex];
    }
};