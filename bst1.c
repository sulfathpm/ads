#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node and attach to root if NULL
void createNode(struct Node **root, int value) {
    *root = (struct Node*) malloc(sizeof(struct Node));
    (*root)->data = value;
    (*root)->left = (*root)->right = NULL;
}

// Insert node (using pointer-to-pointer)
void insert(struct Node **root, int value) {
    if (*root == NULL) {
        createNode(root, value);
        return;
    }
    if (value < (*root)->data)
        insert(&((*root)->left), value);
    else if (value > (*root)->data)
        insert(&((*root)->right), value);
}

// Find minimum node (used inside delete)
struct Node* findMin(struct Node *root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node (no return type)
void deleteNode(struct Node **root, int value) {
    if (*root == NULL) return;

    if (value < (*root)->data) {
        deleteNode(&((*root)->left), value);
    }
    else if (value > (*root)->data) {
        deleteNode(&((*root)->right), value);
    }
    else {
        // Node found
        if ((*root)->left == NULL && (*root)->right == NULL) {
            free(*root);
            *root = NULL;
        }
        else if ((*root)->left == NULL) {
            struct Node *temp = (*root)->right;
            free(*root);
            *root = temp;
        }
        else if ((*root)->right == NULL) {
            struct Node *temp = (*root)->left;
            free(*root);
            *root = temp;
        }
        else {
            struct Node *temp = findMin((*root)->right);
            (*root)->data = temp->data;
            deleteNode(&((*root)->right), temp->data);
        }
    }
}

// Traversals
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node *root = NULL;
    int choice, value;

    while (1) {
        printf("\n\n--- Binary Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&root, value);
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
