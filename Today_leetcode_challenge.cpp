class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
        dummy->next = head;

        int i=0;
        ListNode* leftConnector = dummy,*temp = head;
        while(i<left-1){
            leftConnector = temp;
            temp = temp->next;
            i++;
        }
        ListNode* prev = NULL;
        i=0;
        while(i<right-left+1){
            ListNode* tmp = temp->next;
            temp->next = prev;
            prev = temp;
            temp = tmp;
            i++;
        }
        leftConnector->next->next = temp;
        leftConnector->next = prev;

        return dummy->next;
    }
};
