#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include "BinaryTree.h"

using namespace std;

/**
 * helper for printout
*/
static void printOutput(vector<vector<int>>& allLayers) {
    cout<<"Depth: "<< allLayers.size() << endl;
    cout<<"[";
    for (auto layer : allLayers) {
        cout<<"[";
        for (int idex = 0; idex < layer.size(); idex++) {
            cout<< layer.at(idex);
            if (idex != (layer.size() -1)) cout << ",";
        }
        cout<<"]";
    }
    cout<<"]\n";
}

/**
 * compare 2-d vectors
*/
static bool compareVectorOfVector(vector<vector<int>>& vector1, vector<vector<int>>& vector2) {
    if (vector1.size() != vector2.size()) return false;
    for (int layer = 0; layer < vector1.size(); layer++) {
        for (int nodeIdx; nodeIdx < vector1.at(layer).size(); nodeIdx++) {
            if (vector1.at(layer).at(nodeIdx) != vector2.at(layer).at(nodeIdx)) return false;
        }
    }
    return true;
}

/**
 * comapre two one dimension vector
*/
static bool compareVector(vector<int> vec1, vector<int> vec2){
  if (vec1.size() != vec2.size()) return false;

  for (int i=0; i< vec1.size(); i++) {
    if (vec1.at(i) != vec2.at(i)) return false;
  }
  return true;
}
static void test() {
  /**
   * test case 1
  */
  {
      cout<<"===============TEST 1 START================="<<endl;
      cout<<"Tree:root = [1,2,3,null,5,null,4]\n";
      cout<<"Expected: [1, 3 ,4]\n";
      vector<int> expected = {1, 3, 4};
      TreeNode *root = new TreeNode(1);
      TreeNode *l10 = new TreeNode(2);
      TreeNode *l11 = new TreeNode(3);
      TreeNode *l21 = new TreeNode(5);
      TreeNode *l23 = new TreeNode(4);
      root->left = l10;
      root->right = l11;
      l10->left = l21;
      l11->right = l23;

      // confirm solution
      Solution solution;
      auto result = solution.rightSideView(root);
      cout<< (compareVector(result, expected)? "PASS": "FAIL") << endl;
      delete root;
      delete l10;
      delete l11;
      delete l21;
      delete l23;
  }

/**
   * test case 2
  */
  {
      cout<<"===============TEST 2 START================="<<endl;
      cout<<"Tree:root = [1,null,3]\n";
      cout<<"Expected: [1, 3]\n";
      vector<int> expected = {1, 3};
      TreeNode *root = new TreeNode(1);
      TreeNode *l11 = new TreeNode(3);
      root->right = l11;

      // confirm solution
      Solution solution;
      auto result = solution.rightSideView(root);
      cout<< (compareVector(result, expected)? "PASS": "FAIL") << endl;
      delete root;
      delete l11;
  }

  /**
   * test case 3
  */
  {
      cout<<"===============TEST 3 START================="<<endl;
      cout<<"Tree:root = []\n";
      cout<<"Expected: []\n";
      vector<int> expected = {};
      TreeNode *root = nullptr;
      // confirm solution
       Solution solution;
      auto result = solution.rightSideView(root);
      cout<< (compareVector(result, expected)? "PASS": "FAIL") << endl;
  }

  /**
   * test case 4
  */
  {
      cout<<"===============TEST 4 START================="<<endl;
      cout<<"Tree:root = [1,2]\n";
      cout<<"Expected: [1,2]\n";
      vector<int> expected = {1,2};
      TreeNode *root = new TreeNode(1);
      TreeNode *l10 = new TreeNode(2);
      root->right = l10;
      // confirm solution
       Solution solution;
      auto result = solution.rightSideView(root);
      cout<< (compareVector(result, expected)? "PASS": "FAIL") << endl;
      delete root;
      delete l10;
  }

  /**
   * test case 5
  */
  {
      cout<<"===============TEST 5 START================="<<endl;
      cout<<"Tree:root = [1,4,5, null, null, 7, null, null, 8]\n";
      cout<<"Expected: [1,5, 7, 8]\n";
      vector<int> expected = {1,5, 7,8};
      TreeNode *root = new TreeNode(1);
      TreeNode *l10 = new TreeNode(4);
      TreeNode *l11 = new TreeNode(5);
      TreeNode *l22 = new TreeNode(7);
      TreeNode *l37 = new TreeNode(8);
      root->left = l10;
      root->right = l11;
      l11->left = l22;
      l22->right = l37;
      // confirm solution
       Solution solution;
      auto result = solution.rightSideView(root);
      cout<< (compareVector(result, expected)? "PASS": "FAIL") << endl;
      delete root;
      delete l10;
      delete l11;
      delete l22;
      delete l37;
  }

  /**
   * test case 6
  */
  {
      cout<<"===============TEST 6 START================="<<endl;
      cout<<"Tree:root = [1,2,3,4]\n";
      cout<<"Expected: [1,3,4]\n";
      vector<int> expected = {1,3,4};
      TreeNode *root = new TreeNode(1);
      TreeNode *l10 = new TreeNode(2);
      TreeNode *l11 = new TreeNode(3);
      TreeNode *l20 = new TreeNode(4);
      root->left = l10;
      root->right = l11;
      l11->left = l20;
      // confirm solution
       Solution solution;
      auto result = solution.rightSideView(root);
      cout<< (compareVector(result, expected)? "PASS": "FAIL") << endl;
      delete root;
      delete l10;
      delete l11;
      delete l20;
  }
}
/**
 * main function
*/
int main(int argc, const char** argv) {
  test();
  return 0;
}


