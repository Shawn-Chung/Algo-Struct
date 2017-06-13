#include "CAVLTree.h"
#include "easylogging++.h"

using namespace tr;

CAVLTree::CAVLTree():
    m_tTree(NULL)
{

}


int CAVLTree::height(AVLTree tree)
{
    if(NULL == tree)
    {
        return -1;
    }
    else
    {
        return tree->height;
    }
}

//前序遍历
void CAVLTree::preorder(AVLTree tree)
{
    if(NULL == tree)
    {
        return ;
    }

    LOG(INFO) << tree->key;

    preorder(tree->left);
    preorder(tree->right);
}

//中序遍历
void CAVLTree::inorder(AVLTree tree)
{
    if(NULL == tree)
    {
        return;
    }

    inorder(tree->left);

    LOG(INFO) << tree->key;

    inorder(tree->right);
}

//后序遍历
void CAVLTree::postorder(AVLTree tree)
{
    if(NULL == tree)
    {
        return;
    }

    postorder(tree->left);
    postorder(tree->right);

    LOG(INFO) << tree->key;
}


//搜索(非递归)
TAVLNode* CAVLTree::search(AVLTree x, Type key)
{
    while(NULL != x)
    {
        if(key == x->key)
        {
            break;
        }
        else if(key > x->key)
        {
            x = x->right;
        }
        else if(key < x->key)
        {
            x = x->left;
        }
    }

    return x;
}

//搜索（递归）
TAVLNode* CAVLTree::search1(AVLTree x, Type key)
{
    if((NULL == x) || (key == x->key))
    {
        return x;
    }

    if(key > x->key)
    {
        search1(x->right, key);
    }
    else if(key < x->key)
    {
        search1(x->left, key);
    }
}

TAVLNode* CAVLTree::minimum(AVLTree tree)
{
    if(NULL == tree)
    {
        return NULL;
    }

    while(tree->left != NULL)
    {
        tree = tree->left;
    }

    return tree;
}

TAVLNode* CAVLTree::maximum(AVLTree tree)
{
    if(NULL == tree)
    {
        return NULL;
    }

    while(tree->right != NULL)
    {
        tree = tree->right;
    }

    return tree;
}

//左左 单旋转
TAVLNode* CAVLTree::llRotation(AVLTree k2)
{
    AVLTree k1 = k2->left;

    k2->left = k1->right;
    k1->right = k2;

    k2->height = MAX(height(k2->left), height(k2->right)) + 1;
    k1->height = MAX(height(k1->left), height(k1->right)) + 1;

    return k1;
}
//右右单旋转
TAVLNode* CAVLTree::rrRotation(AVLTree k1)
{
    AVLTree k2 = k1->right;

    k1->right = k2->left;
    k2->left = k1;

    k1->height = MAX(height(k1->left), height(k1->right)) + 1;
    k2->height = MAX(height(k2->left), height(k2->right)) + 1;

    return k2;
}

//左右 双旋转
TAVLNode* CAVLTree::lrRotation(AVLTree k3)
{
    k3->left = rrRotation(k3->left);

    return llRotation(k3);
}

//右左 双旋转
TAVLNode* CAVLTree::rlRotation(AVLTree k1)
{
    k1->right = llRotation(k1->right);

    return rrRotation(k1);
}


TAVLNode* CAVLTree::createNode(Type key, TAVLNode *left, TAVLNode *right)
{
    TAVLNode *node;

    if(NULL == (node=(TAVLNode*)malloc(sizeof(TAVLNode))))
    {
        return NULL;
    }

    node->key = key;
    node->height = 0;
    node->left = left;
    node->right = right;

    return node;
}

TAVLNode* CAVLTree::insert(AVLTree tree, Type key)
{
    if(NULL == tree)
    {
        tree = createNode(key, NULL, NULL);
        if(NULL == tree)
        {
            LOG(INFO) << "create node failed!";
            return NULL;
        }
    }
    else if(key < tree->key)
    {
        tree->left = insert(tree->left, key);

        if(height(tree->left) - height(tree->right) == 2)
        {
            if(key < tree->left->key)
            {
                tree = llRotation(tree);
            }
            else
            {
                tree = lrRotation(tree);
            }
        }
    }
    else if(key > tree->key)
    {
        tree->right = insert(tree->right,key);

        if(height(tree->right) - height(tree->left) == 2)
        {
            if(key > tree->right->key)
            {
                tree = rrRotation(tree);
            }
            else
            {
                tree = rlRotation(tree);
            }
        }
    }
    else
    {
        LOG(INFO) << "failed: there is exist the same node of the key!";
    }

    tree->height = MAX(height(tree->left), height(tree->right)) + 1;

    return tree;
}

TAVLNode* CAVLTree::deleteNode(AVLTree tree, TAVLNode *node)
{
    if((NULL == tree) || (NULL == node))
    {
        return NULL;
    }

    if(node->key < tree->key)
    {

    }
    else if(node->key > tree->key)
    {

    }
    else //tree是要删除的节点
    {
        if(tree->left && tree->right) //左右孩子都非空
        {

        }
        else
        {
            TAVLNode *n = tree;
            tree = n->left? n->left:n->right;
            free(n);
        }
    }

    return tree;
}
