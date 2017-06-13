#ifndef CAVLTREE_H
#define CAVLTREE_H


namespace tr {


#define MAX(a, b)    ( (a) > (b) ? (a) : (b) )


typedef int Type;

typedef struct TAVLNode{

    Type key;
    int height;
    TAVLNode *left;
    TAVLNode *right;
} *AVLTree;


class CAVLTree
{
public:
    CAVLTree();

    int height(AVLTree tree);
    //遍历
    void preorder(AVLTree tree);
    void inorder(AVLTree tree);
    void postorder(AVLTree tree);

    TAVLNode* search(AVLTree x, Type key);
    TAVLNode* search1(AVLTree x, Type key);
    TAVLNode* minimum(AVLTree tree);
    TAVLNode* maximum(AVLTree tree);

    TAVLNode* insert(AVLTree tree, Type key);
    TAVLNode* del(AVLTree tree, Type key);

    void destroy(AVLTree tree);

private:
    TAVLNode* llRotation(AVLTree k2);
    TAVLNode* rrRotation(AVLTree k1);
    TAVLNode* lrRotation(AVLTree k3);
    TAVLNode* rlRotation(AVLTree k1);

    TAVLNode* createNode(Type key, AVLTree left, AVLTree right);
    TAVLNode* deleteNode(AVLTree node);

private:
    AVLTree m_tTree;
};





}



#endif // CAVLTREE_H
