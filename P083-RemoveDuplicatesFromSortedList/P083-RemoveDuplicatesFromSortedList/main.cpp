//
//  LeetCode
//  Algorithm 83 Remove Duplicates From Sorted List
//
//  Created by Rick Lan on 4/22/17.
//  See LICENSE
//

#include <iostream>
#include "listnode.h"

using namespace std;



class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if ((head == NULL) || (head->next == NULL))
            return head;
        
        ListNode* prev = head;
        ListNode* now = head->next;
        do {
            //cout << "do "; displayLN(head);
            if (prev->val == now->val) {
                ListNode *t = now;
                now = now->next;
                prev->next = now;
                delete t; // release memory
            } else {
                prev = now;
                now = now->next;
            }
        } while (now != NULL);
        
        return head;
    }
};


int main(int argc, const char * argv[]) {
    
    ListNode *ptr;
    //ptr = constructLN("3 1 1 2");
    ptr = constructLN("5 1 1 2 3 3");
    
    Solution solution;
    ptr = solution.deleteDuplicates(ptr);
    cout << "Solution ";
    displayLN(ptr);
    
    return 0;
}
