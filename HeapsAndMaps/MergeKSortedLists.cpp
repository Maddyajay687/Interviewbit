/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode *insert(ListNode *head, int val) {
    if(head == NULL) {
        return new ListNode(val);
    } else{
        ListNode *temp = new ListNode(val);
        temp->next = head;
        head = temp;
    }
    return head;
} 


ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   int size = A.size();
    priority_queue<int> pq;
    for(int i = 0; i < size; i++) {
        ListNode *temp = A[i];
        while(temp != NULL) {
            pq.push(temp->val);
            temp = temp->next;
        }
    }
    ListNode *ans = NULL;
    while(!pq.empty()) {
        ans = insert(ans, pq.top());
        pq.pop();
    }
    return ans;
        
    
}
