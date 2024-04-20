#include <iostream>
#include "BinaryTree.h"
using namespace std;

/**
 * solution global value
*/
void Solution::dfs_find_2(TreeNode *currentNode, vector<int> &sideView, int layer)
{
    if (!currentNode) return;
    // fill up value if the current layer still has a vacancy
    if (sideView.size() == layer) sideView.push_back(currentNode->val);
    // traverse on right first
    if (currentNode->right) {
        dfs_find_2(currentNode->right, sideView, layer + 1);
    }
    // go on left on second
    if (currentNode->left) {
        dfs_find_2(currentNode->left, sideView, layer + 1);
    }

}

/**
 * the public method for dfs second solution
 * with global reference
*/
vector<int> Solution::rightSideView_dfs_2(TreeNode *root)
{
    vector<int> ans;
    dfs_find_2(root, ans, 0);
    return ans;
}

/**
 * depth first search solution
 * no global variable
*/
vector<int> Solution::dfs_find(TreeNode *currentNode, int layer)
{
    if (!currentNode) return {};
    vector<int> result;
    // Step 0: pickup value of target node
    result.push_back(currentNode->val);
    vector<int> nextLayer;
    vector<int> nextLayer_l;

    // Step 1: check right branch first
    if (currentNode->right) {
        nextLayer = dfs_find(currentNode->right, layer + 1);
    }
    // Step 2: pickup result from right
    for(int i = 0; i < nextLayer.size(); i++) {
        result.push_back(nextLayer[i]);
    }
    // Step 3: check left branch
    if (currentNode->left) {
        nextLayer_l = dfs_find(currentNode->left, layer + 1);
        if (nextLayer_l.size() <= nextLayer.size()) return result;
    }
    // Step 4: pickup adding nodes from left branch only
    for(int i = nextLayer.size(); i < nextLayer_l.size(); i++) {
        result.push_back(nextLayer_l[i]);
    }
    return result;
}

/**
 * the deapth first search solution
*/
vector<int> Solution::rightSideView_dfs(TreeNode *root)
{
    return dfs_find(root, 0);
}

/**
 * breadth first search solution
*/
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

