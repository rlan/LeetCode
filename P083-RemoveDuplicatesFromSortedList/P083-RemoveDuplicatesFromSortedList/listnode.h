//
//  listnode.h
//  Singly-linked list
//
//  Created by Rick Lan on 4/22/17.
//  See LICENSE
//

#ifndef listnode_h
#define listnode_h

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void displayLN(ListNode *ptr) {
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

ListNode* constructLN(string data) {
    // first number in data is number of items
    
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
    
    displayLN(head);
    
    return head;
}

void testLN(void) {
    
    string str;
    str = "3 3 2 1";
    cout << "str (len " << str.size() << ") " << str << endl;
    ListNode *ptr = constructLN(str);
    cout << "result ";
    displayLN(ptr);
}


#endif /* listnode_h */
