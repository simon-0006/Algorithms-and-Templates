#include <stdc++.h/bits>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  map<TreeNode*, int> dep;

  // returns new root of the subtree
  TreeNode* leftrightRotation(TreeNode* par, TreeNode* leftChild, TreeNode* leftrightChild) {
    TreeNode* templrl = leftrightChild->left;
    leftrightChild->left = leftChild;
    leftChild->right = templrl;

    templrl = leftrightChild->right;
    leftrightChild->right = par;
    par->left = templrl;

    dep[leftChild]      = getMax(leftChild) + 1;
    dep[par]            = getMax(par) + 1;
    dep[leftrightChild] = getMax(leftrightChild) + 1;
    return leftrightChild;
  }

  // returns new root of the subtree
  TreeNode* leftRotation(TreeNode* par, TreeNode* rightChild) {
    par->right = rightChild->left;
    rightChild->left = par;

    dep[par]        = getMax(par) + 1;
    dep[rightChild] = getMax(rightChild) + 1;
    return rightChild;
  }

  // returns new root of the subtree
  TreeNode* rightleftRotation(TreeNode* par, TreeNode* rightChild, TreeNode* rightleftChild) {
    TreeNode* temprlr = rightleftChild->right;
    rightleftChild->right = rightChild;
    rightChild->left = temprlr;

    temprlr = rightleftChild->left;
    rightleftChild->left = par;
    par->right = temprlr;

    dep[rightChild]     = getMax(rightChild) + 1;
    dep[par]            = getMax(par) + 1;
    dep[rightleftChild] = getMax(rightleftChild) + 1;
    return rightleftChild;
  }

  // returns new root of the subtree
  TreeNode* rightRotation(TreeNode* par, TreeNode* leftChild) {
    par->left = leftChild->right;
    leftChild->right = par;

    dep[par]       = getMax(par) + 1;
    dep[leftChild] = getMax(leftChild) + 1;
    return leftChild;
  }

  TreeNode* repairTree(TreeNode* node) {
    int depl = (node->left != NULL) ? dep[node->left] : 0;
    int depr = (node->right != NULL) ? dep[node->right] : 0;
    if (abs(depl - depr) <= 1) return node;
    int depll = 0;
    int deplr = 0;
    if (depl != 0) {
      depll = (node->left->left  != NULL) ? dep[node->left->left] : 0;
      deplr = (node->left->right != NULL) ? dep[node->left->right] : 0;
    }

    int deprr = 0;
    int deprl = 0;
    if (depr != 0) {
      deprr = (node->right->right != NULL) ? dep[node->right->right] : 0;
      deprl = (node->right->left  != NULL) ? dep[node->right->left] : 0;
    }

    if (depl > depr) {
      if (depll >= deplr) {
        return rightRotation(node, node->left);
      } else {
        return leftrightRotation(node, node->left, node->left->right);
      }
    } else {
      if (deprr >= deprl) {
        return leftRotation(node, node->right);
      } else {
        return rightleftRotation(node, node->right, node->right->left);
      }
    }
  }

  int getMax(TreeNode* node) {
    int maxdep = 0;
    if (node->left != NULL) maxdep = dep[node->left];
    if (node->right != NULL) maxdep = max(maxdep, dep[node->right]);
    return maxdep;
  }

  TreeNode* dfs(TreeNode* node) {
    if (node == NULL) return 0;

    node->left  = dfs(node->left); 
    node->right = dfs(node->right);

    int maxdep = getMax(node);
    dep[node] = maxdep + 1;

    TreeNode* newNode = repairTree(node);
    if (newNode != node) return dfs(newNode);
    return node;
  }

public:
    TreeNode* balanceBST(TreeNode* root) {
      return dfs(root);
    }
};