
class Solution {
public:
    int majority(vector<int>& nums, int low, int high) {
        if (low == high)
            return nums[low];

        int mid = low + (high - low) / 2;

        int left = majority(nums, low, mid);
        int right = majority(nums, mid + 1, high);

        if (left == right)
            return left;

        int leftCount = 0, rightCount = 0;

        for (int i = low; i <= high; i++) {
            if (nums[i] == left)
                leftCount++;
            else if (nums[i] == right)
                rightCount++;
        }

        return leftCount > rightCount ? left : right;
    }

    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() - 1);
    }
};
