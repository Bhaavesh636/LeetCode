
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        function<void(int, int)> mergeSort = [&](int l, int r) {
            if (l >= r) return;

            int mid = l + (r - l) / 2;

            mergeSort(l, mid);
            mergeSort(mid + 1, r);

            vector<pair<int, int>> temp;
            int i = l, j = mid + 1;
            int rightCount = 0;

            while (i <= mid && j <= r) {
                if (arr[j].first < arr[i].first) {
                    temp.push_back(arr[j++]);
                    rightCount++;
                } else {
                    ans[arr[i].second] += rightCount;
                    temp.push_back(arr[i++]);
                }
            }

            while (i <= mid) {
                ans[arr[i].second] += rightCount;
                temp.push_back(arr[i++]);
            }

            while (j <= r)
                temp.push_back(arr[j++]);

            for (int k = l; k <= r; k++)
                arr[k] = temp[k - l];
        };

        mergeSort(0, n - 1);
        return ans;
    }
};
