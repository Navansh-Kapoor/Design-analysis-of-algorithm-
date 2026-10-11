
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

struct Node* createNode(char ch, int freq) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void printCodes(struct Node* root, int code[], int top) {
    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->ch);

        for (int i = 0; i < top; i++)
            printf("%d", code[i]);

        printf("\n");
    }
}

int main() {
    char ch[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int n = 6;

    struct Node* nodes[20];
    int size = n;

    for (int i = 0; i < n; i++)
        nodes[i] = createNode(ch[i], freq[i]);

    while (size > 1) {
        int min1 = 0, min2 = 1;

        if (nodes[min1]->freq > nodes[min2]->freq) {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }

        for (int i = 2; i < size; i++) {
            if (nodes[i]->freq < nodes[min1]->freq) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->freq < nodes[min2]->freq) {
                min2 = i;
            }
        }

        struct Node* left = nodes[min1];
        struct Node* right = nodes[min2];

        struct Node* parent =
            createNode('$', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        if (min1 > min2) {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }

        nodes[min1] = parent;
        nodes[min2] = nodes[size - 1];
        size--;
    }

    int code[100];

    printf("Huffman Codes:\n");
    printCodes(nodes[0], code, 0);

    return 0;
}
