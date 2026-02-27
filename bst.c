#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
struct Node* createNode(int price) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->price = price;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int price) {
    if (root == NULL)
        return createNode(price);

    if (price < root->price)
        root->left = insert(root->left, price);
    else if (price > root->price)
        root->right = insert(root->right, price);
    return root;
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->price);
        inorder(root->right);
    }
}
struct Node* search(struct Node* root, int price) {
    if (root == NULL || root->price == price)
        return root;
    if (price < root->price)
        return search(root->left, price);
    return search(root->right, price);
}