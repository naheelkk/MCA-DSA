#include <stdio.h>

#define MAX 100 // Maximum number of elements

// Structure to represent a disjoint set
struct DisjointSet {
    int parent[MAX];
    int rank[MAX];
    int elements[MAX]; // To store the actual elements
};

// Initialize each element as its own set (MakeSet)
void makeSet(struct DisjointSet* ds, int n) {
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ds->elements[i]); // Read the element
        ds->parent[i] = i;             // Each element is its own parent
        ds->rank[i] = 0;               // Rank is initialized to 0
    }
}

// Find the index of an element in the elements array
int findElementIndex(struct DisjointSet* ds, int n, int element) {
    for (int i = 0; i < n; i++) {
        if (ds->elements[i] == element) {
            return i;
        }
    }
    return -1; // Element not found
}

// Find the representative of the set containing 'x' (FindSet with path compression)
int findSet(struct DisjointSet* ds, int x) {
    if (ds->parent[x] != x) {
        // Path compression: recursively find the root and make it the parent of 'x'
        ds->parent[x] = findSet(ds, ds->parent[x]);
    }
    return ds->parent[x];
}

// Union of two sets by rank
void unionSets(struct DisjointSet* ds, int x, int y) {
    int rootX = findSet(ds, x);
    int rootY = findSet(ds, y);

    if (rootX != rootY) {
        // Union by rank
        if (ds->rank[rootX] > ds->rank[rootY]) {
            ds->parent[rootY] = rootX;
        } else if (ds->rank[rootX] < ds->rank[rootY]) {
            ds->parent[rootX] = rootY;
        } else {
            ds->parent[rootY] = rootX;
            ds->rank[rootX]++;
        }
    }
}

// Main function to demonstrate the operations
int main() {
    struct DisjointSet ds;
    int n, choice, x, y;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    makeSet(&ds, n);

    while (1) {
        printf("\nMenu:\n");
        printf("1. FindSet\n");
        printf("2. Union\n");
        printf("3. Display Parent Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to find its set: ");
                scanf("%d", &x);
                int idx1 = findElementIndex(&ds, n, x);
                if (idx1 == -1) {
                    printf("Element not found!\n");
                } else {
                    printf("Set representative: %d\n", ds.elements[findSet(&ds, idx1)]);
                }
                break;
            case 2:
                printf("Enter two elements to union: ");
                scanf("%d %d", &x, &y);
                int idx2 = findElementIndex(&ds, n, x);
                int idx3 = findElementIndex(&ds, n, y);
                if (idx2 == -1 || idx3 == -1) {
                    printf("One or both elements not found!\n");
                } else {
                    unionSets(&ds, idx2, idx3);
                    printf("Union completed.\n");
                }
                break;
            case 3:
                printf("Parent Array: ");
                for (int i = 0; i < n; i++) {
                    printf("%d:%d ", ds.elements[i], ds.elements[ds. parent[i]]);
                }
                printf("\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
