/**
 * 思路：分情况分析
 * 1）如果有右子节点：下一个节点就是右子节点的最左边的节点。例如a的下个节点就是c的左子节点f
 * 2）如果没有右子节点，且是父节点的左子节点：它的父节点就是下一个节点。例如 h，f
 * 3）既没有右子节点，也不是父节点的左子节点：源着该节点的父节点，一直找到某个节点是父节点的子节点，如果存在该节点，它的父节点就是下一个节点。
 * 例如j一直往上父节点找，找到b,b的父节点就是j的下一个节点。
 * 
 *  a
   /  \
  b     c
 /  \   /  \
d   e  f    g 
   /  \
  h    j
* 
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode *parent;
      TreeNode(int x) : val(x), left(NULL), right(NULL),parent(NULL) {}
 };


TreeNode* findNextNode(TreeNode *node) {
      if (node == nullptr) {
            return nullptr;
      }
      TreeNode *pNext = nullptr;
      if (node->right != nullptr) {
          TreeNode *pRight = node->right;
          while(pRight->left != nullptr) {
              pRight = pRight->left;
          }
          pNext = pRight;
      } else if (node->parent != nullptr) {
          TreeNode *parentNode = node->parent;
          TreeNode *currentNode = node;
          // 如果节点本身是左节点，直接不进入循环，父节点就是下个节点
          while(parentNode != nullptr && currentNode == parentNode->right) {
                // 如果当前节点是父节点的右子树，接着往上找
                currentNode = parentNode;
                parentNode = parentNode->parent;
          }
          pNext = parentNode;
      }
      return pNext;
}
