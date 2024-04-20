#include <iostream>
#include "BinaryTree.h"
using namespace std;

vector<int> Solution::rightSideView(TreeNode *root)
{
    if (!root) return {};
    TreeNode* currentNode = root;
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(currentNode);
    while (!q.empty())
    {
        int size = q.size();
        for (int i=0; i < size; i++) {
            // pick up value from right side
            TreeNode* current = q.front();
            // remove current item
            q.pop();
            if (i == (size -1)) {
                ans.push_back(current->val);
            }
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }
    
    return ans;
}