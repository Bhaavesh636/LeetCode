class Solution {
public:
    void merge(vector<int>&nums, int low ,int mid,int high){

        int n1= mid-low+1;
        int n2= high-mid;

        vector <int> L(n1);
        vector <int> R(n2);

        for(int i=0;i<n1;i++){
            L[i]=nums[low+i];
        }

        for(int j=0;j<n2;j++){
            R[j]=nums[mid+j+1];
        }

        int i=0 ,j=0, k= low;
        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                nums[k++]=L[i++];
            }

            else{
                nums[k++]=R[j++];
            }

        }

        while(i<n1){
            nums[k++]=L[i++];
        }

        while(j<n2){
            nums[k++]=R[j++];
        }
    }
    void mergeSort(vector<int> &nums ,int low,int high){
        if(low<high){
            int mid=low+(high-low)/2;

            mergeSort(nums,low,mid);
            mergeSort(nums,mid+1,high);

            merge(nums,low,mid,high);
        }
    }

    vector<int> sortArray(vector<int>& nums) { 
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};