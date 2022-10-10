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
class BST_Inorder {
public:
    TreeNode *root;
    stack<TreeNode*> s;
    BST_Inorder(TreeNode* root) {
        this -> root = root;
    }

    void next() {
        if(root != NULL or s.size() > 0){
            while(root != NULL){
                s.push(root);
                root = root -> left;
            }
            TreeNode* elem = s.top();
            s.pop();
            root = elem -> right;
        }
        else assert(0); // never happens
    }
    
   	TreeNode* getNext() {
        if(root != NULL or s.size() > 0){
            while(root != NULL){
                s.push(root);
                root = root -> left;
            }
            TreeNode* elem = s.top();
            return elem;
        }
        else{
        	return NULL;
        }
    }
};


class BST_Inorder_Reversed {
public:
    TreeNode *root;
    stack<TreeNode*> s;
    BST_Inorder_Reversed(TreeNode* root) {
        this -> root = root;
    }

    void next() {
        if(root != NULL or s.size() > 0){
            while(root != NULL){
                s.push(root);
                root = root -> right;
            }
            TreeNode* elem = s.top();
            s.pop();
            root = elem -> left;
        }
        else assert(0); // never happens
    }
    
   	TreeNode* getNext() {
        if(root != NULL or s.size() > 0){
            while(root != NULL){
                s.push(root);
                root = root -> right;
            }
            TreeNode* elem = s.top();
            return elem;
        }
        else{
        	return NULL;
        }
    }
};

class Solution {
public:
  Solution() { ios_base::sync_with_stdio(false); cin.tie(NULL); }
  ~Solution(){}
    bool findTarget(TreeNode* root, int k) {
        BST_Inorder bstIn(root);
        BST_Inorder_Reversed bstInRev(root);
        while(bstIn.getNext() != NULL and bstInRev.getNext() != NULL){
            TreeNode* left = bstIn.getNext();
            TreeNode* right = bstInRev.getNext();
            if(left == right){
                break;
            }
            else if(left -> val + right -> val == k){
                return 1;
            }
            else if(left -> val + right -> val < k){
                bstIn.next();
            }
            else{
                bstInRev.next();
            }
        }
        return 0;
    }
};