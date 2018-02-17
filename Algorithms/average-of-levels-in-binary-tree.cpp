637. Average of Levels in Binary Tree
https://leetcode.com/problems/average-of-levels-in-binary-tree/

Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode * left, * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if (!root) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            long sz = q.size(), sum = 0, k = sz;
            while (sz-- > 0) {
                TreeNode * front = q.front();
                q.pop();
                sum += front->val;
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            result.push_back(double(sum) / k);
        }
        return result;
    }
};

int main(void) {
    Solution solution;
    TreeNode * root = NULL;
    vector<double> result;
    
    root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    result = solution.averageOfLevels(root);
    for (const auto & i : result) {
        cout << i << '\t';
    }
    cout << '\n';

    return 0;
}