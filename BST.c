#include <stdio.h>
#include <malloc.h>

typedef int KeyType;

struct Node{
	KeyType key;
	struct Node* left;
	struct Node* right;	
};
typedef struct Node* Tree;


Tree Search(KeyType x, Tree root){
	if(root == NULL) return NULL;
	else if(root->key == x) return root;
	else if(root->key < x) return Search(x, root->right);
	else return Search(x, root->left);
}


void InsertNode(KeyType x, Tree *t){
	if(*t == NULL){
		(*t) = (struct Node*) malloc(sizeof(struct Node));
		(*t)->key = x;
		(*t)->left = NULL;
		(*t)->right = NULL;
	}else{
		if((*t)->key == x) printf("Da ton tai %d \n", x);
		else{
			if((*t)->key > x) InsertNode(x, &(*t)->left);
			else InsertNode(x, &(*t)->right);
		}
	}
}


KeyType DeleteMin(Tree *t){
	KeyType k;
	if((*t)->left == NULL){
		k = (*t)->key;
		(*t) = (*t)->right;
		return k;
	}else{
		DeleteMin(&(*t)->left);
	}
}


void DeleteNode(KeyType x, Tree *t){
	if((*t)!= NULL){
		if(x < (*t)->key) DeleteNode(x, &(*t)->left);
		else{
			if(x > (*t)->key) DeleteNode(x, &(*t)->right);
			else{
				if(((*t)->left == NULL) && ((*t)->right == NULL)) (*t) = NULL;
				else{
					if((*t)->left == NULL) (*t) = (*t)->right;
					else{
						if((*t)->right == NULL) (*t) = (*t)->left;
						else{
							(*t)->key = DeleteMin(&(*t)->right);
						}
					}
				}
			}
		}
	}
}











