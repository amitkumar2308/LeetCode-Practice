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
    // 2nd step
    bool isCritical(ListNode* prev, ListNode* curr, ListNode* next) {
        if (curr->val > prev->val && curr->val > next->val)
            return true; // local maxima
        if (curr->val < prev->val && curr->val < next->val)
            return true; // local minima

        return false;
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        // ist step
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = head->next->next;

        int pos = 2; // 3rd step

        // 4thstep

        int firstCritical = -1;
        int prevCritical = -1;
        int minDistance = INT_MAX;

        while (next != nullptr) {

            if (isCritical(prev, curr, next)) {
                if (firstCritical == -1) {
                    firstCritical = pos;
                    prevCritical = pos;
                } else {
                    int distance = pos - prevCritical; // 5th step
                    minDistance = min(minDistance, distance);
                    prevCritical = pos;
                }
            }

            prev = curr;
            curr = next;
            next = next->next;

            pos++; // 6th step
        }

        // 7th step
        if (firstCritical == -1 || firstCritical == prevCritical) {
            return {-1, -1};
        }

        // 8th step

        int maxDistance = prevCritical - firstCritical;

        return {minDistance, maxDistance};
    }
};