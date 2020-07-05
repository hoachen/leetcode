/**
NO 105. 从前序与中序遍历序列构造二叉树
根据一棵树的前序遍历与中序遍历构造二叉树。
注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
 */


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
private:
    unordered_map<int, int> index;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }
        return buildTreeEx(preorder, inorder, 0, n-1, 0, n-1);
    }

    TreeNode* buildTreeEx(vector<int>& preorder, vector<int>& inorder, int pStartPos, int pEndPos, int inStartPos, int inEndPos) {
        if (pStartPos > pEndPos)
            return nullptr;
        int rootVal = preorder[pStartPos]; // 找到根节点
        int inorder_root = index[rootVal]; // 根节点在中序中的位置
        int sub_left_size = inorder_root - inStartPos;
        TreeNode *root = new TreeNode(rootVal);
        root->left = buildTreeEx(preorder, inorder, pStartPos + 1, pStartPos + sub_left_size, inStartPos, inorder_root -1 );
        root->right = buildTreeEx(preorder, inorder, pStartPos + sub_left_size + 1, pEndPos, inorder_root + 1, inEndPos);
        return root;
    }
};

// 后序遍历打印
void PrintTree(const TreeNode *root) {
    if (root == nullptr)
        return;
    PrintTree(root->left);
    PrintTree(root->right);
    cout << root->val << endl;
}


int main(int argc, char *args[]) {
    vector<int> preorder;
    preorder.push_back(3);
    preorder.push_back(9);
    preorder.push_back(20);
    preorder.push_back(15);
    preorder.push_back(7);
    vector<int> inorder;
    inorder.push_back(9);
    inorder.push_back(3);
    inorder.push_back(15);
    inorder.push_back(20);
    inorder.push_back(7);
    Solution *s = new Solution();
    TreeNode *root = s->buildTree(preorder, inorder);
    PrintTree(root);
    return 0;
}