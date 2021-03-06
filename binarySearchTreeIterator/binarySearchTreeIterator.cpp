// Source : https://leetcode.com/problems/binary-search-tree-iterator/
// Author : weekend27
// Date   : 2015-12-20

/**********************************************************************************

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

**********************************************************************************/

// How to do it:
// first store all left tree into a stack
// when the stack is not empty, pop, and find the left tree of its right tree, push into the stack, the pop


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    std::stack<TreeNode *> stack;
public:
    BSTIterator(TreeNode *root) {
        while (root != NULL){
            stack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!stack.empty());
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* curr = stack.top();
        TreeNode* result = curr;
        stack.pop();
        curr = curr->right;
        while (curr != NULL){
            stack.push(curr);
            curr = curr->left;
        }
        return result->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
