#include "CAVLTree.h"
#include "easylogging++.h"

using namespace tr;


int tr::AVLtest()
{
    int arr[]= {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};

    CAVLTree *tree = new CAVLTree();
    LOG(INFO) << "the height of the tree is: " <<tree->height() ;

    for(int i=0; i<12; i++)
    {
        tree->insert(arr[i]);
        LOG(INFO) << "the height of the tree is: " <<tree->height() ;
    }
    tree->preorder();

    tree->deleteKey(4);
    tree->deleteKey(3);
    tree->deleteKey(1);
    tree->deleteKey(12);
    tree->deleteKey(14);
    tree->preorder();
}







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
//    LOG(INFO) << "HEIGHT: "<< tree->height;

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
//查找最小值
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
//查找最大值
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
            if(key < tree->left->key) //左子节点的左子树
            {
                tree = llRotation(tree);
            }
            else //左子节点的右子树
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
            if(key > tree->right->key) //右子节点的右子树
            {
                tree = rrRotation(tree);
            }
            else //右子节点的左子树
            {
                tree = rlRotation(tree);
            }
        }
    }
    else
    {
        LOG(INFO) << "failed: there is exist the same node of the key!";
    }
    //这句很重要
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
        tree->left = deleteNode(tree->left, node);
        if(height(tree->right) - height(tree->left) == 2)
        {
            if(height(tree->right->left) > height(tree->right->right))//右子节点左子树
            {
                tree = rlRotation(tree);
            }
            else
            {
                tree = rrRotation(tree);
            }
        }
    }
    else if(node->key > tree->key)
    {
        tree->right = deleteNode(tree->right, node);
        if(height(tree->left) - height(tree->right) == 2)
        {
            if(height(tree->left->left) > height(tree->left->right))
            {
                tree = llRotation(tree);
            }
            else
            {
                tree = lrRotation(tree);
            }
        }
    }
    else //tree是要删除的节点
    {
        if(tree->left && tree->right) //左右孩子都非空
        {
            if(height(tree->left) > height(tree->right))
            {
                //这类似于用"tree的左子树中最大节点"做"tree"的替身；
                //采用这种方式的好处是：删除"tree的左子树中最大节点"之后，AVL树仍然是平衡的
                TAVLNode *max = maximum(tree->left);
                tree->key = max->key;
                tree->left = deleteNode(tree->left, max);
            }
            else
            {
                TAVLNode *min = minimum(tree->right);
                tree->key = min->key;
                tree->right = deleteNode(tree->right, min);
            }
        }
        else
        {
            TAVLNode *n = tree;
            tree = n->left? n->left:n->right;
            free(n);
        }
    }
    //这一句很重要,一定要有判断，因为当tree左右都为空时，删除之后tree就为空了，再操作就会出现内存错误。
    if(NULL != tree)
    {
        tree->height = MAX(height(tree->left), height(tree->right)) + 1;
    }

    return tree;
}

TAVLNode* CAVLTree::deleteKey(AVLTree tree, Type key)
{
    TAVLNode *node;
    if((node = search(tree, key)) != NULL)
    {
        tree = deleteNode(tree, node);
    }

    return tree;
}
