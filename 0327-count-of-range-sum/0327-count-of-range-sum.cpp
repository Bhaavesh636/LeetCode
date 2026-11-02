
class Solution {
public:
    int mergeSort(vector<long long>& prefix, int low, int high, int lower, int upper) {
        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        int count = mergeSort(prefix, low, mid, lower, upper);
        count += mergeSort(prefix, mid + 1, high, lower, upper);

        int j = mid + 1, k = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (k <= high && prefix[k] - prefix[i] < lower)
                k++;

            while (j <= high && prefix[j] - prefix[i] <= upper)
                j++;

            count += j - k;
        }

        vector<long long> temp;
        int i = low;
        j = mid + 1;

        while (i <= mid && j <= high) {
            if (prefix[i] <= prefix[j])
                temp.push_back(prefix[i++]);
            else
                temp.push_back(prefix[j++]);
        }

        while (i <= mid)
            temp.push_back(prefix[i++]);

        while (j <= high)
            temp.push_back(prefix[j++]);

        for (int p = low; p <= high; p++)
            prefix[p] = temp[p - low];

        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> prefix(nums.size() + 1, 0);

        for (int i = 0; i < nums.size(); i++)
            prefix[i + 1] = prefix[i] + nums[i];

        return mergeSort(prefix, 0, prefix.size() - 1, lower, upper);
    }
};
