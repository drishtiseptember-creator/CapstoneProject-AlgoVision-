#include <stdio.h>
#include <stdlib.h>
#define MAX 20

//defining structure
struct Product {
    int id;
    int price;
    int sold;
};
struct Product products[MAX];
int count = 0;

//defininf queue
int queue[MAX];
int start = -1, end = -1;
void enqueue(int id) {
    if (end == MAX - 1) {
        printf("Queue Full\n");
        return;
    }
    if (start == -1) start = 0;
    queue[++end] = id;
    printf("Order Added\n");
}
void dequeue() {
    if (start == -1 || start > end) {
        printf("Queue Empty\n");
        return;
    }
    printf("Processing Order ID: %d\n", queue[start]);
    start++;
}

//hash search
int searchHash(int id) {
    for (int i = 0; i < count; i++) {
        if (products[i].id == id)
            return i;
    }
    return -1;
}

//binary search tree
struct Node {
    int price;
    struct Node *left, *right;
};

struct Node* createNode(int price) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->price = price;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int price) {
    if (root == NULL)
        return createNode(price);

    if (price < root->price)
        root->left = insert(root->left, price);
    else
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

//sorting revenue using greedy
void greedySort() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int r1 = products[j].price * products[j].sold;
            int r2 = products[j+1].price * products[j+1].sold;
            if (r1 < r2) {
                struct Product temp = products[j];
                products[j] = products[j+1];
                products[j+1] = temp;
            }
        }
    }

    printf("Sorted by Revenue:\n");
    for (int i = 0; i < count; i++)
        printf("ID:%d Revenue:%d\n", products[i].id,
               products[i].price * products[i].sold);
}

//knapsack algorithm(calculating best possibility to spend a budget)
void knapsack(int budget) {
    int MaxSpend[50][50] = {0};

    for (int i = 1; i <= count; i++) {
        for (int w = 0; w <= budget; w++) {
            if (products[i-1].price <= w) {
                int include = products[i-1].price +
                              MaxSpend[i-1][w - products[i-1].price];
                int exclude = MaxSpend[i-1][w];
                MaxSpend[i][w] = (include > exclude) ? include : exclude;
            } else {
                MaxSpend[i][w] = MaxSpend[i-1][w];
            }
        }
    }

    printf("Max Value in Budget %d: %d\n", budget, MaxSpend[count][budget]);
}

//graph
int graph[5][5] = {
    {0,1,0,0,0},
    {1,0,1,0,0},
    {0,1,0,1,0},
    {0,0,1,0,1},
    {0,0,0,1,0}
};

void bfs(int start) {
    int visited[5] = {0};
    int q[5], f = 0, r = 0;

    visited[start] = 1;
    q[r++] = start;

    printf("BFS: ");

    while (f < r) {
        int node = q[f++];
        printf("%d ", node);

        for (int i = 0; i < 5; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                q[r++] = i;
            }
        }
    }
    printf("\n");
}

//main output
int main() {

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