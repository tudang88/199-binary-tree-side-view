#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * solution class
*/
class Solution {
private:
    void dfs_find_2(TreeNode* currentNode, vector<int>& sideView, int layer);
    vector<int> dfs_find(TreeNode* currentNode, int layer);
public:
    vector<int> rightSideView(TreeNode* root);
    vector<int> rightSideView_dfs(TreeNode* root);
    vector<int> rightSideView_dfs_2(TreeNode* root);

};
#endif