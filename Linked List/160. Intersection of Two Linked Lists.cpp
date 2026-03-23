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
    ListNode *intersection(ListNode *small, ListNode *big,int count){
        for(int i=0;i<count;i++){
            big = big->next;
        }
        while(small !=NULL && big != NULL){
            if(small == big) return small;
            small = small->next;
            big = big->next;
            
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * tempA = headA;
        ListNode * tempB = headB;
        int countA =0, countB =0;
        while(tempA != NULL){
            tempA = tempA->next;
            countA++;
        }
        while(tempB != NULL){
            tempB = tempB->next;
            countB++;
        }
        if(countA < countB) return intersection(headA, headB, countB-countA);
        else return intersection(headB, headA, countA-countB);

        return NULL;
    }
};