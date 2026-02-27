#include <stdio.h>
#include "knapsack.h"
extern int count;
struct Product {
    int id;
    int price;
    int quantity;
};
extern struct Product products[50];

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
