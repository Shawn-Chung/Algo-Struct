#ifndef CAVLTREE_H
#define CAVLTREE_H


namespace tr {


int AVLtest();


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
    int height(){ return height(m_tTree); }
    //遍历

    void preorder(){ preorder(m_tTree); }
    void inorder(){ inorder(m_tTree); }
    void postorder(){ postorder(m_tTree); }


    Type minimum(){ return minimum(m_tTree)->key; }
    Type maximum(){ return maximum(m_tTree)->key; }




    int insert(Type key){ m_tTree = insert(m_tTree, key); }

    TAVLNode* del(AVLTree tree, Type key);

    void destroy(AVLTree tree);

    void deleteKey(Type key){ deleteKey(m_tTree, key); }

private:
    TAVLNode* llRotation(AVLTree k2);
    TAVLNode* rrRotation(AVLTree k1);
    TAVLNode* lrRotation(AVLTree k3);
    TAVLNode* rlRotation(AVLTree k1);

    void preorder(AVLTree tree);
    void inorder(AVLTree tree);
    void postorder(AVLTree tree);
    TAVLNode* search(AVLTree x, Type key);
    TAVLNode* search1(AVLTree x, Type key);
    TAVLNode* minimum(AVLTree tree);
    TAVLNode* maximum(AVLTree tree);

    TAVLNode* insert(AVLTree tree, Type key);

    TAVLNode* createNode(Type key, TAVLNode* left, TAVLNode* right);
    TAVLNode* deleteNode(AVLTree tree, TAVLNode* node);
    TAVLNode* deleteKey(AVLTree tree, Type key);

private:
    AVLTree m_tTree;
};





}



#endif // CAVLTREE_H
