#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treenode{
    int value;
    struct treenode* left;
    struct treenode* right;
} treenode;

treenode* createnode(int value){
    treenode* result = (treenode*)malloc(sizeof(treenode));
    if (result != NULL){
        result->value = value;
        result->left = NULL;
        result->right = NULL;
    }
    return result;
}
void printtabs(int numtabs){
    for (int i=0; i < numtabs; i++){
        printf("\t");
    }
}
void printtree(treenode* root, int level){
    if (root == NULL){
        printtabs(level);
        printf("---<empty>---\n");
        return;
    }
    // pre-order traversal
    printtabs(level);
    printf("value = %d\n", root->value);
    printtabs(level);
    
    printf("left\n");
    printtree(root->left, level + 1);
    printtabs(level);
    
    printf("right\n");
    printtree(root->right, level + 1);
    printtabs(level);
    printf("done\n");
}

bool insertnumber(treenode** rootptr, int value){
    treenode* root = *rootptr;
    if (root == NULL){
        // tree empty
        (*rootptr) = createnode(value);
        return true;
    }
    if (value == root->value){
        // do nothing
        return false;
    }
    if (value < root->value){
        return insertnumber(&(root->left), value);
    }
    else {
        return insertnumber(&(root->right), value);
    }
}

bool findnumber(treenode* root, int value){
    if (root == NULL) return false;
    if (root->value == value) return true;
    if (value < root->value){
        return findnumber(root->left, value);
    }
    else{
        return findnumber(root->right, value);
    }
}

treenode* findmin(treenode* root){
    treenode* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
treenode* Delete(treenode* root, int data){
    if (root == NULL) return root;
    else if (data < root->value) root->left = Delete(root->left, data);
    else if (data > root->value) root->right = Delete(root->right, data);
    else{
        // case 1: No child
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        // case 2: One child
        else if(root->left == NULL){
            treenode* temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){
            treenode* temp = root;
            root = root->left;
            free(temp);
        }
        // case 3: 2 children
        else{
            treenode* temp = findmin(root->right);
            root->value = temp->value;
            // Delete the minimum node in the right subtree
            root->right = Delete(root->right, temp->value);
        }
    }
    return root;
}
int main(){
    treenode* root = NULL;
    
    insertnumber(&root, 40);
    insertnumber(&root, 6);
    insertnumber(&root, 22);
    insertnumber(&root, 150);
    insertnumber(&root, 0);
    insertnumber(&root, 12);
    insertnumber(&root, 1000);
    insertnumber(&root, 140);
    
    printtree(root, 0);
    
    printf("%d (%d)\n", 150, findnumber(root, 150));
    printf("%d (%d)\n", 16, findnumber(root, 16));
    
    root = Delete(root, 40);
    printtree(root, 0);
}