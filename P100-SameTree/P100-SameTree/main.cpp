//
//  LeetCode
//  Algorithm 100 Same Tree
//
//  Created by Rick Lan on 4/22/17.
//  See LICENSE
//

#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p == NULL) && (q == NULL))
            return true;
        if ((p == NULL) && (q != NULL))
            return false;
        if ((p != NULL) && (q == NULL))
            return false;
        if (p->val != q->val)
            return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(int argc, const char * argv[]) {

    std::cout << "Compiles, is correct but does not run any test input!\n";
    return 0;
}
