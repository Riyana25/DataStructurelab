#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct BST;

typedef struct BST {
  int data;
  struct BST* left;
  struct BST* right;
} Node;

Node* new_Node(int data, Node* left, Node* right) {
  Node* ret = (Node*)malloc(sizeof(Node));
  ret->data = data;
  ret->left = left;

  ret->right = right;
  return ret;
}

Node* insert(Node* root, Node* n) {
  if (root == NULL) {
    root = n;
  } else if (n->data < root->data) {
    root->left = insert(root->left, n);
  } else if (n->data > root->data) {
    root->right = insert(root->right, n);
  }
  return root;
}

Node* search(Node* root, int data) {
  if (root == NULL) {
    printf("%d doesnt exist in Tree\n", data);
    return NULL;
  } else if (data < root->data) {
    return search(root->left, data);
  } else if (data > root->data) {
    return search(root->right, data);
  }
  return root;
}

Node* delete (Node* root, int x) {
  Node* t;
  if (root == NULL) {
    return NULL;
  } else if (x < root->data) {
    root->left = delete (root->left, x);
  } else if (x > root->data) {
    root->right = delete (root->right, x);
  } else if (root->left && root->right) {
    t = root;
    while (t->left != NULL) {  // find min element
      t = t->left;
    }
    root->data = t->data;
    root->right = delete (root->right, root->data);
  } else {
    t = root;
    if (root->left == NULL) {
      root = root->right;
    } else if (root->right == NULL) {
      root = root->left;
    }
    free(t);
  }
  return root;
}

void inorder(Node* root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

void preorder(Node* root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void postorder(Node* root) {
  if (root == NULL) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

int main(int argc, char const* argv[]) {
  Node* root = NULL;
  int choice, val;

  puts("1. Insertion");
  puts("2. Searching");
  puts("3. Deletetion");
  puts("4. In-Order Traversal");
  puts("5. Pre-Order Traversal");
  puts("6. Post-Order Traversal");
  puts("7. Exit");
  

  while (true) {
    printf("Enter a choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        printf("Enter value: ");
        scanf("%d", &val);
        root = insert(root, new_Node(val, NULL, NULL));
        break;
      case 2:
        printf("Enter data: ");
        scanf("%d", &val);
        printf("Found %d in tree at %#p\n", val, search(root, val));
        break;

      case 3:
        printf("Enter data: ");
        scanf("%d", &val);
        root = delete (root, val);
        break;

      case 4:
        inorder(root);
        putchar('\n');
        break;

      case 5:
        preorder(root);
        putchar('\n');
        break;

      case 6:
        postorder(root);
        putchar('\n');
        break;

      case 7:
        return 0;

      default:
        break;
    }
  }

  return 0;
}