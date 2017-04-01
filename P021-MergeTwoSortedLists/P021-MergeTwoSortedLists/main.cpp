//
//  LeetCode
//  Algorithm 21 Merge Two Sorted Lists
//
//  Created by Rick Lan on 3/31/17.
//  See LICENSE
//

#include <iostream>
#include <sstream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

void display(ListNode *ptr) {
    if (ptr == NULL) {
        cout << "Empty" << endl;
        return;
    }
    
    do {
        cout << ptr->val << " ";
        ptr = ptr->next;
    } while (ptr != NULL);
    cout << endl;
}


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // assuming asending lists
        
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        
        ListNode *head = l1;
        ListNode *t;
        
        while (l2 != NULL) {
            //cout << "l1_val " << l1->val << endl;
            if (l2->val < l1->val) {
                // insert new head
                //cout << "new ";
                t = l2->next;
                l2->next = l1;
                head = l1 = l2;
                l2 = t;
            } else if (l1->next == NULL) {
                // insert new end
                //cout << "end ";
                l1->next = l2;
                l2 = NULL;
            } else if (l2->val < l1->next->val) {
                // insert middle
                //cout << "mid ";
                t = l2->next;
                l2->next = l1->next;
                l1->next = l2;
                l1 = l2;
                l2 = t;
            } else {
                //cout << "next ";
                l1 = l1->next;
            }
            
            //display(head);
        }
        
        return head;
    }
};


ListNode* construct(string data) {
    if (data.size()==0) {
        return NULL;
    }
    stringstream ss(data);
    unsigned int N;
    ss >> N;
    
    ListNode *head = NULL;
    ListNode *ptr = NULL;
    for (unsigned int ii = 0; ii < N; ii++) {
        int val;
        ss >> val;
        if (ptr == NULL) {
            ptr = new ListNode(val);
            head = ptr;
        } else {
            ptr->next = new ListNode(val);
            ptr = ptr->next;
        }
    }
    
    display(head);
    
    return head;
}


int main(int argc, const char * argv[]) {
    
    string s1, s2;
    //s1 = "2 20 30";
    //s2 = "1 1";
    //s2 = "1 21";
    //s2 = "1 31";
    //s2 = "2 31 32";
    //s2 = "4 1 5 31 32";
    //s2 = "4 1 5 25 31 32";
    
    s1 = "1 3";
    s2 = "";
    ListNode *l1 = construct(s1);
    ListNode *l2 = construct(s2);

    Solution solution;
    ListNode *merged = solution.mergeTwoLists(l1, l2);
    cout << "merged "; display(merged);
    
    return 0;
}
