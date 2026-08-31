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
    bool isCritical(ListNode* prev, ListNode* curr, ListNode* next){
         if(curr->val>prev->val && curr->val>next->val) return true;
         if(curr->val<prev->val && curr->val<next->val) return true;
         return false;

    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
           ListNode* prev = head;
           ListNode* curr = head->next;
           ListNode* next = head->next->next;

           int pos = 2;
             
           int firstCritical = -1;
           int previousCritical = -1;

           int minDistance = INT_MAX;

           while(next!=nullptr){
                if(isCritical(prev,curr,next)){
                   if(firstCritical == -1){
                      firstCritical = pos;
                      previousCritical = pos;
                   }else{
                     int distance = pos-previousCritical;
                     minDistance = min(minDistance,distance);

                     previousCritical = pos;
                   }
                }

                prev = curr;
                curr = next;
                next = next->next;

                pos++;
           }
           if(firstCritical == -1 || firstCritical == previousCritical){
            return {-1,-1};
           }
           int maxDistance = previousCritical - firstCritical;

           return {minDistance,maxDistance};

    }
};