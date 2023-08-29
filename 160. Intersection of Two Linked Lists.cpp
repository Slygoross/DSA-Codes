// Brute Force:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headB != NULL){
            ListNode* temp = headA;
            while(temp != NULL){
                if(temp == headB){
                    return headB;
                }
                temp = temp -> next;
            }
            headB = headB -> next;
        }
        return NULL;
    }
};

// Better:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> hashset;
        while(headA != NULL){
            hashset.insert(headA);
            headA = headA->next;
        }

        while(headB != NULL){
            if(hashset.find(headB) != hashset.end()){
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};