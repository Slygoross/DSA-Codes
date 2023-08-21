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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        unordered_set<ListNode*> hashTable;
        while(head != NULL){
            if(hashTable.find(head) != hashTable.end()){
                return head;
            }
            hashTable.insert(head);
            head = head -> next;
        }
        return NULL;
    }
};

// Two Pointers Approach: O(N)

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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
               while(entry != slow){
                   slow = slow->next;
                   entry = entry->next;
               }
               return slow; 
            }
        } 
        return NULL;       
    }
};