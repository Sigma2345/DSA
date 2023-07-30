#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Node
{
public:
    int sum;
    bool isBST;
    int minVal;
    int maxVal;
    Node(int s, bool m, int p, int q)
    {
        sum = s, isBST = m, minVal = p, maxVal = q;
    }
};
class Solution
{
public:
    map<TreeNode *, Node *> mp;
    Node *f(TreeNode *root, int level)
    {
        // base case
        if (!root)
        {
            return new Node(0, true, INT_MAX, INT_MIN);
        }

        if (mp.count(root) > 0)
            return mp[root];

        // recursive case
        auto l = f(root->left, level + 1);
        auto r = f(root->right, level + 1);

        bool subans = l->isBST && r->isBST;
        if (root->left && root->val <= root->left->val)
            subans = false;
        else if (root->right && root->val >= root->right->val)
            subans = false;
        else if (root->val < l->maxVal || root->val > r->minVal)
            subans = false;

        return mp[root] = new Node(l->sum + r->sum + root->val, subans, min(l->minVal, root->val), max(r->maxVal, root->val));
    }

    int maxSumBST(TreeNode *root)
    {
        if (!root)
            return true;
        auto ans = f(root, 0);
        int final_ans = 0;
        for (auto x : mp)
        {
            // cout<<x.first->val<<' '<<x.second->sum<<' '<<x.second->isBST<<' '<<x.second->minVal<<' '<<x.second->maxVal<<endl ;
            if (x.second->isBST && x.second->sum > final_ans)
            {
                final_ans = x.second->sum;
            }
        }
        return final_ans;
    }
};
