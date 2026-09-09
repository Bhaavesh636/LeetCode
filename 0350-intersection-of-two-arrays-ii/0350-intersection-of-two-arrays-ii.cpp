class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;

        for(int i : nums1) mp1[i]++;
        for(int j : nums2) mp2[j]++;

        for(auto x : mp1 ){
            if(mp2.find(x.first) != mp2.end()){
                int freq =min(x.second,mp2[x.first]);
                for(int i=0;i<freq;i++)
                    res.push_back(x.first);
            }
        }

        return res;
    }
};