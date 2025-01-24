class Solution {
public:
    struct Compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        for(ListNode* list : lists){
            if(list != nullptr){
                minHeap.push(list);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while(!minHeap.empty()){
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            if(smallest->next != nullptr){
                minHeap.push(smallest->next);
            }
        }

        return dummy->next;

    }
};