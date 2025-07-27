#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// 10 20 30 40 -1 50 60 -1 -1 -1 -1 -1 -1

int level_order(Node *root)
{
    queue<Node *> q;
    q.push(root);
    int count = 0;
    while (!q.empty())
    {
        Node *x = q.front();
        q.pop();
        count++;
        if (x->left != NULL)
        {
            q.push(x->left);
        }
        if (x->right != NULL)
        {
            q.push(x->right);
        }
    }
    return count;
}

int count_nodes(Node* root){
     if(root->left == NULL && root->right == NULL){
        return 1;
     }

     int l = count_nodes(root->left);
     int r = count_nodes(root->right);
     return (l + r);
}

Node *input_tree()
{
    int val;
    cin >> val;
    if (val == -1)
        return NULL;

    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *x = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node *myleft = NULL;
        Node *myright = NULL;

        if (l != -1)
        {
            myleft = new Node(l);
        }
        if (r != -1)
        {
            myright = new Node(r);
        }

        x->left = myleft;
        x->right = myright;

        if (x->left)
        {
            q.push(x->left);
        }
        if (x->right)
        {
            q.push(x->right);
        }
    }
    return root;
}

int main()
{

    Node *root = input_tree();
    int ans = level_order(root);
    cout << ans << "\n";
    int count = count_nodes(root);
    cout << count << "\n";
}