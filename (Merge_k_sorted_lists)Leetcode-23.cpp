class Solution {
public:
    
    ListNode* merge2lists(ListNode* list1, ListNode* list2){
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* head = list1;
        if(list1->val <= list2->val){ head = list1;}
        else {head = list2;}
        
        if(list1->val <= list2->val)
        {
            head->next = merge2lists(list1->next,list2);
        }
        else
        {
            head->next = merge2lists(list1,list2->next);
        }
        return head;
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size() == 0) return NULL;
        ListNode* head = lists[0];
        for(int i=1;i<lists.size();i++)
            head = merge2lists(head,lists[i]);
        
        return head;
        
    }
};
