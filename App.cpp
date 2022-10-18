#include <iostream>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
  class Solution {
  public:
      bool hasPathSum(TreeNode* root, int targetSum) {

          // if there is no root, return false
          if (root == nullptr)
          {
              return false;
          }

          // if there is a root with no children and this value matches our target value
          else if (root->val == targetSum && root->left == nullptr && root->right == nullptr)
          {
              return true;
          }

          // there are children nodes to be checked
          else
          {
              // subtract the value at this node from the target value
              int new_target = targetSum - root->val;

              // use recursion to see if either the left subtree or right subtree is a valid path
              return hasPathSum(root->left, new_target) || hasPathSum(root->right, new_target);
          }
      }
  };

int main()
{
    Solution solution;

    TreeNode two(2);
    TreeNode seven(7);
    TreeNode eleven(11, &seven, &two);
    TreeNode four_left(4, &eleven, nullptr);


    TreeNode one(1);
    TreeNode four_right(4, nullptr, &one);
    TreeNode thirteen(13);
    TreeNode eight (8, &thirteen, &four_right);

    TreeNode root(5, &four_left, &eight);

    cout << "Example One : " << solution.hasPathSum(&root, 22) << endl;
  
	return 0;
}
