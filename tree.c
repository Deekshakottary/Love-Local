#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new tree node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to construct a height-balanced BST from a sorted array
struct TreeNode* sortedArrayToBST(int nums[], int start, int end) {
    if (start > end) {
        return NULL;
    }

    // Find the middle element of the array
    int mid = (start + end) / 2;

    // Create a new tree node with the middle element as the value
    struct TreeNode* root = newNode(nums[mid]);

    // Recursively construct the left and right subtrees
    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);

    return root;
}

// Function to print the inorder traversal of a binary tree
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

int main() {
    int n;

    // Get user input for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int nums[n];

    // Get user input for the sorted array
    printf("Enter %d sorted elements for the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Construct a height-balanced BST from the sorted array
    struct TreeNode* root = sortedArrayToBST(nums, 0, n - 1);

    // Print the inorder traversal of the constructed BST
    printf("Inorder traversal of the constructed BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}