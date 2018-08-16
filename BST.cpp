#include<bits/stdc++.h>

using namespace std;

struct bst
{

    int data;
    bst *left;
    bst *right;

};

bst* getnewnode(int data)
{
    bst *newnode = new bst();
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;

}

bst* ins(bst *root,int data)
{
    if(root==NULL)
        root = getnewnode(data);
    else if(data <= root->data)
        root->left = ins(root->left,data);
    else
        root->right = ins(root->right,data);
    return root;
}
bst* srch(bst *root,int data)
{
    if(root == NULL)
        return NULL;
    else if(root->data == data)
        return root;
    else if(data <= root->data)
        return  srch(root->left,data);
    else
        return srch(root->right,data);
}

int findmax(bst *root)
{
    if(root==NULL)
        return -1;

    if(root->right == NULL) return root->data;
    else
        return findmax(root->right);

}
int findmin(bst *root)
{
    if(root==NULL)
        return -1; ///tree is empty
    else{

        while(root->left!=NULL)
        {
            root = root->left;

        }
        return root->data;
    }


}
int findheight(bst *root)
{
    if(root == NULL)
        return -1;
    return max(findheight(root->left),findheight(root->right))+1;


}

int find_depth(bst *root,int data,int val)
{
    if(root==NULL) return -1;
    else if(root->data == data)
        return val;
    else if(data <= root->data)
        find_depth(root->left,data,val+1);
    else
        find_depth(root->right,data,val+1);



}

void preorder(bst *root)
{

    if(root == NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);


}

void levelorder(bst *root)
{

    if(root==NULL) return;
    queue<bst*>q;
    q.push(root);
    while(!q.empty())
    {
        bst *current =  q.front();
        q.pop();
        printf("%d ",current->data);
        if(current->left!=NULL) q.push(current->left);
         if(current->right!=NULL) q.push(current->right);

    }
     puts("");
}

bool islesser(bst* root,int data)
{
     if(root == NULL) return true;
     else if(root->data<=data && islesser(root->left,data)&&islesser(root->right,data))
        return true;
     else
        return false;

}
bool isgreater(bst *root,int data)
{
    if(root == NULL) return true;
     else if(root->data > data && isgreater(root->left,data)&&isgreater(root->right,data))
        return true ;
     else
        return false;
}

bool isbst(bst *root)
{
    if(root == NULL) return true;
    if(islesser(root->left,root->data) && isgreater(root->right,root->data)
       && isbst(root->left) && isbst(root->right))
        return true;
    else
        return false;
}


bool isbstcool(bst*root,int mn,int mx)
{
    if(root == NULL) return true;
    if(root->data >= mn && root->data < mx &&
       isbstcool(root->left,mn,root->data) && isbstcool(root->right,root->data,mx))
        return true;
    else
        return false;
}


int main()
{

    bst *root= NULL;

    root = ins(root,150);

    root = ins(root,0);

    root = ins(root,20);
    root = ins(root,11);

    root = ins(root,100);

    root = ins(root,280);

    root = ins(root,28);


    preorder(root);
    puts("");
    //printf("%d\n",isbstcool(root,INT_MIN,INT_MAX));

    return 0;
}
