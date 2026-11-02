/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (a && b) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }

            tail = tail->next;
        }

        tail->next = a ? a : b;

        return dummy.next;
    }

    ListNode* divide(vector<ListNode*>& lists, int low, int high) {
        if (low > high)
            return nullptr;

        if (low == high)
            return lists[low];

        int mid = low + (high - low) / 2;

        ListNode* left = divide(lists, low, mid);
        ListNode* right = divide(lists, mid + 1, high);

        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return divide(lists, 0, lists.size() - 1);
    }
};
