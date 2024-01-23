#include <stdio.h>
#include <stdlib.h>

struct AVLNODE{
    int key;
    int bal;
    struct AVLNODE* left;
    struct AVLNODE* right;
};
	
struct AVLNODE* CreateNode(int data){
    struct AVLNODE* p = (struct AVLNODE*)malloc(sizeof(struct AVLNODE));
    if(p == NULL) {
        return NULL;
    }
    p->key = data;
    p->left = NULL;
    p->right = NULL;
    p->bal = 0;
    return p;
}


void LeftRotate(struct AVLNODE* *p){
    struct AVLNODE* q = (*p)->right;
    (*p)->right = q->left;
    q->left = (*p);
    (*p) = q;
}

void RightRotate(struct AVLNODE* *p){
    struct AVLNODE* q = (*p)->left;
    (*p)->left = q->right;
    q->right = (*p);
    (*p) = q;
}


void LeftBalance(struct AVLNODE* *p){
    switch((*p)->left->bal){
        case 1:
            RightRotate(p);
            (*p)->bal = 0;
            (*p)->right->bal = 0;
            break;
        case 2:
            LeftRotate(&((*p)->left));
            RightRotate(p);
            switch((*p)->bal){
                case 0:
                    (*p)->left->bal = 0;
                    (*p)->right->bal = 0;
                    break;
                case 1:
                    (*p)->left->bal = 0;
                    (*p)->right->bal = 2;
                    break;
                case 2:
                    (*p)->left->bal = 1;
                    (*p)->right->bal = 0;
                    break;
            }
            (*p)->bal = 0;
            break;
    }
}

void RightBalance(struct AVLNODE* *p){
    switch((*p)->right->bal){
        case 1:
            RightRotate(&((*p)->right));
            LeftRotate(p);
            switch((*p)->bal){
                case 0:
                    (*p)->left->bal = 0;
                    (*p)->right->bal = 0;
                    break;
                case 1:
                    (*p)->left->bal = 1;
                    (*p)->right->bal = 0;
                    break;
                case 2:
                    (*p)->left->bal = 0;
                    (*p)->right->bal = 2;
                    break;
            }
            (*p)->bal = 0;
            break;
        case 2:
            LeftRotate(p);
            (*p)->bal = 0;
            (*p)->left->bal = 0;
            break;
    }
}


int InsertNode(AVLNODE** t, int x){
	int res;
	if(*t == NULL){
		*t = CreateNode(x);
		if(*t == NULL) return -1;
	}else{
		if((*t)->key == x) return 0;
		else if((*t)->key > x){
			res = InsertNode(&((*t)->left), x);
			if(res < 2) return res;
			switch((*t)->bal){
				case 0:
					(*t)->bal = 1;
					return 2;
				case 1:
					LeftBalance(t);
					return 1;
				case 2:
					(*t)->bal = 0;
					return 1;
			}
		}else{
			res = InsertNode(&((*t)->right), x);
			if(res < 2) return res;
			switch((*t)->bal){
				case 0:
					(*t)->bal = 2;
					return 2;
				case 1:
					(*t)->bal = 0;
					return 1;
				case 2:
					RightBalance(t);
					return 1;
			}
		}		
	}
	return res;
}
void Traverse(AVLNODE* t){
	if(t != NULL){
		Traverse(t->left);
		printf("key: %d - Cân bằng :%d\n", t->key, t->bal);
		Traverse(t->right);
	}
}
void RemoveAll(AVLNODE** t){
	if(*t != NULL){
		RemoveAll(&((*t)->left));
		RemoveAll(&((*t)->right));
		free(*t);
		*t = NULL;
	}
}

