#include <stdio.h>

struct node {
    unsigned dist[20];
    unsigned from[20];
} rt[10];

int main() {
    int costmat[20][20];
    int nodes, i, j, k, count = 0;

    printf("\nDistance Vector Routing\n\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes); // Enter the number of nodes

    if (nodes <= 0 || nodes > 10) {
        printf("Error: Number of nodes must be between 1 and 10.\n");
        return 1; // Exit with error code
    }

    printf("\nEnter the cost matrix:\n");
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            scanf("%d", &costmat[i][j]);
            costmat[i][i] = 0;
            rt[i].dist[j] = costmat[i][j]; // Initialize the distance equal to the cost matrix
            rt[i].from[j] = j;
        }
    }

    // Distance Vector Routing Algorithm
    do {
        count = 0;
        for (i = 0; i < nodes; i++) {
            for (j = 0; j < nodes; j++) {
                for (k = 0; k < nodes; k++) {
                    if (rt[i].dist[j] > costmat[i][k] + rt[k].dist[j]) {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
    } while (count != 0);

    // Output the routing table
    for (i = 0; i < nodes; i++) {
        printf("\n\nFor router %d:\n", i + 1);
        for (j = 0; j < nodes; j++) {
            printf("\t\nNode %d via %d distance %d ", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
        }
    }

    return 0;
}

