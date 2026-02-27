#include <stdio.h>
#include "bst.h"
#include "knapsack.h"
#define MAX 100

int main() {
    extern int count;
struct Product {
    int id;
    int price;
    int sold;
};
extern struct Product products[50];

    struct Node* root = NULL;
    int prices[MAX];
    int n = 0;
    int choice, price, budget;

    struct Node* root = NULL;
    int choice, id, price, sold, budget;

    while (1) {
        printf("\n--- AlgoVision Simple Menu ---\n");
        printf("1 Add Product\n");
        printf("2 Show Prices\n");
        printf("3 Add Order\n");
        printf("4 Process Order\n");
        printf("5 Search Product\n");
        printf("6 Revenue\n");
        printf("7 Budget Optimization\n");
        printf("8 BFS Demo\n");
        printf("0 Exit\n");
        printf("Enter process you want to continue with:");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter ID,Price & Quantity Sold:");
                scanf("%d,%d,%d", &id, &price, &sold);
                products[count].id = id;
                products[count].price = price;
                products[count].sold = sold;
                root = insert(root, price);
                count++;
                break;

            case 2:
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter Product ID:");
                scanf("%d", &id);
                enqueue(id);
                break;

            case 4:
                dequeue();
                break;

            case 5:
                printf("Enter Product ID:");
                scanf("%d", &id);
                int index = searchHash(id);
                if (index != -1)
                    printf("Found Price: %d\n", products[index].price);
                else
                    printf("Not Found");
                break;

            case 6:
                greedySort();
                break;

            case 7:
                printf("Enter Budget:");
                scanf("%d", &budget);
                knapsack(budget);
                break;

            case 8:
                bfs(0);
                break;

            case 0:
                exit(0);
        }
    }
}