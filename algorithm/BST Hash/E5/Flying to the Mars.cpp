/*
 * @Author: your name
 * @Date: 2021-10-13 19:53:43
 * @LastEditTime: 2021-10-13 20:29:04
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \code\algorithm\BST Hash\E5\Flying to the Mars.cpp
 */
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left = NULL;
    Node *right = NULL;
    Node(int val) : val(val){};
    ~Node()
    {
        delete left;
        delete right;
    }
};
bool insert(Node *root, int val)
{
    Node *temp = root;
    while (true)
    {
        if (val == temp->val)
        {
            return false;
        }
        else if (val > temp->val)
        {
            if (temp->right != NULL)
            {
                temp = temp->right;
            }
            else
            {
                Node *newnode = new Node(val);
                temp->right = newnode;
                return true;
            }
        }
        else
        {
            if (temp->left != NULL)
            {
                temp = temp->left;
            }
            else
            {
                Node *newnode = new Node(val);
                temp->left = newnode;
                return true;
            }
        }
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            continue;
        }
        if (n < 0 || n > 3000)
        {
            break;
        }

        string num;
        cin >> num;
        int nu = atoi(num.c_str());
        Node *r = new Node(nu);
        vector<Node *> lr;
        lr.push_back(r);
        for (int i = 1; i < n; i++)
        {
            cin >> num;
            nu = atoi(num.c_str());
            bool flag = false;
            for (auto it = lr.begin(); it != lr.end(); it++)
            {
                if (insert((*it), nu))
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                Node *newn = new Node(nu);
                lr.push_back(newn);
            }
        }
        cout << lr.size() << endl;
    }
    system("pause");
}