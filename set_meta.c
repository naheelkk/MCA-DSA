#include <stdio.h>
#include <ctype.h>

// Function to convert a set to its bit vector representation
void bitVector(char set[], int bitVector[], char Universal_set[]) {
    for (int i = 0; i < 26; i++) {
        bitVector[i] = 0;
    }
    for (int i = 0; set[i] != '\0'; i++) {
        for (int j = 0; j < 26; j++) {
            if (set[i] == Universal_set[j]) {
                bitVector[j] = 1;
                break;
            }
        }
    }
}

// Function to print a bit vector
void printBitVector(int bitVector[]) {
    for (int i = 0; i < 26; i++) {
        printf("%d ", bitVector[i]);
    }
    printf("\n");
}

// Function to perform union operation on two bit vectors
void unionOperation(int set1_bit[], int set2_bit[], int result[]) {
    for (int i = 0; i < 26; i++) {
        result[i] = set1_bit[i] | set2_bit[i];
    }
}

// Function to perform complement operation on a bit vector
void complementOperation(int set1_bit[], int result[]) {
    for (int i = 0; i < 26; i++) {
        result[i] = ~set1_bit[i] & 1;
    }
}

// Function to perform difference operation on two bit vectors
void differenceOperation(int set1_bit[], int set2_bit[], int result[]) {
    int complement[26];
    complementOperation(set2_bit, complement);
    for (int i = 0; i < 26; i++) {
        result[i] = set1_bit[i] & complement[i];
    }
}

int main() {
    char Universal_set[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char set1[26], set2[26];
    int set1_bit[26], set2_bit[26], result[26];

    int set1_size, set2_size;

    printf("Enter size of Set 1: ");
    scanf("%d", &set1_size);
    printf("Enter elements for Set 1: ");
    for (int i = 0; i < set1_size; i++) {
        scanf(" %c", &set1[i]);
        set1[i] = tolower(set1[i]);
    }

    printf("Enter size of Set 2: ");
    scanf("%d", &set2_size);
    printf("Enter elements for Set 2: ");
    for (int i = 0; i < set2_size; i++) {
        scanf(" %c", &set2[i]);
        set2[i] = tolower(set2[i]);
    }

    bitVector(set1, set1_bit, Universal_set);
    bitVector(set2, set2_bit, Universal_set);

    printf("Bit Vector Representation of Set 1: ");
    printBitVector(set1_bit);

    printf("Bit Vector Representation of Set 2: ");
    printBitVector(set2_bit);

    int choice;
    printf("Enter your choice:\n1. Union\n2. Complement\n3. Difference\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            unionOperation(set1_bit, set2_bit, result);
            printf("Union of Set 1 and Set 2: ");
            printBitVector(result);
            break;
        case 2:
            complementOperation(set1_bit, result);
            printf("Complement of Set 1: ");
            printBitVector(result);
            break;
        case 3:
            differenceOperation(set1_bit, set2_bit, result);
            printf("Difference of Set 1 and Set 2: ");
            printBitVector(result);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
