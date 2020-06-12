/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/


//写的又臭又长
//相比于第一版，这个二叉树不再是完全二叉树。因此主要难点是如何以常数空间，找到每层的最后一个节点和第一个节点。
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)return NULL;
        connect(root->left);
        connect(root->right);
        Node* l=root->left;
        Node* r=root->right;
        while(1)//遍历每一层
        {
            Node* next_l=NULL,*last_l=NULL,*next_r=NULL,*first_r=r;
            while(l)//找到左子树的最后一个节点，且记录左子树下一层的第一个节点
            {
                if(l->left&&next_l==NULL)
                    next_l=l->left;
                if(l->right&&next_l==NULL)
                    next_l=l->right;
                last_l=l;
                l=l->next;
            }
            while(r)//找到右子树下一层的第一个节点
            {
                if(r->left&&next_r==NULL)
                    next_r=r->left;
                if(r->right&&next_r==NULL)
                    next_r=r->right;
                r=r->next;
            }
            if(last_l&&first_r)//连接左右子树
            {
                last_l->next=first_r;
                l=next_l;
                r=next_r;
            }
            if(first_r==NULL||last_l==NULL)//下一层有一个为空，结束处理
                break;
        }
        return root;
    }
};