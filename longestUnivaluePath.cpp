# include <stddef.h>

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

/**
给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。

注意：两个节点之间的路径长度由它们之间的边数表示。

示例 1:

输入:

              5
             / \
            4   5
           / \   \
          1   1   5
输出:

2
示例 2:

输入:

              1
             / \
            4   5
           / \   \
          4   4   5
输出:

2
注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。
**/  

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        int maxVal = 0;
        cal(root, &maxVal);
        return maxVal;
    }

    int cal(TreeNode *r1, int* maxVal) {
        if (NULL == r1 ){
            return 0;
        }

        int left = cal(r1->left, maxVal);
        int right = cal(r1->right, maxVal);

        left = (r1->left && r1->left->val == r1->val) ? left + 1: 0;
        right = (r1->right && r1->right->val == r1->val) ? right + 1 : 0;
        *maxVal = (*maxVal > left + right) ? *maxVal : left + right;

        return  left > right ? left : right;
    }
};