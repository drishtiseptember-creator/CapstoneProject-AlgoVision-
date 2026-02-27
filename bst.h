#ifndef BST_H
#define BST_H
struct Node {
    int price;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int price);
struct Node* insert(struct Node* root, int price);
void inorder(struct Node* root);
struct Node* search(struct Node* root, int price);
#endif