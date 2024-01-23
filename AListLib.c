#include <stdio.h>
#define Maxlength 100

typedef int ElementType;
typedef int Position;

typedef struct {
	ElementType Elements[Maxlength];
	Position Last;
} List;

void makenullList(List *L){
	L->Last = 0;
}

int emptyList(List L){
	return L.Last == 0;
}

int fullList(List L){
	return L.Last == Maxlength;
}

Position first(List L){
	return 1;
}

Position endList(List L){
	return L.Last + 1;
}

Position next(Position P, List L){
	return P + 1;
}

Position previous(Position P, List L){
	return P - 1;
}

ElementType retrieve(Position P, List L){
	return L.Elements[P-1];
}

void insertList(ElementType X, Position P, List *L){
	int i=0;
	if(L->Last == Maxlength){
		printf("\nDanh sach day !!!");
	}else if((P<1) || (P>L->Last+1)){
		printf("\nVi tri khong hop le !!!");
	}else{
		for(i = L->Last; i>=P; --i){
			L->Elements[i] = L->Elements[i-1];
		}
		++L->Last;
		L->Elements[P-1] = X;
	}
}

void insertSet(ElementType x, List *l){
	insertList(x, endList(*l), l);
}

void deleteList(Position P, List *L){
	if(P > L->Last || P < 1){
		printf("\nVi tri khong hop le !!!");
	}else if(emptyList(*L)){
		printf("\nDanh sach dang rong !!!");
	}else{
		Position i;
		for(i = P; i<L->Last; ++i){
			L->Elements[i-1] = L->Elements[i];
		}
		--L->Last;
	}
}

void printList(List L){
	Position P;
	P = first(L);
	while(P != endList(L)){
		printf("%d ", retrieve(P, L));
		P = next(P, L);
	}
	printf("\n");
}

void readList(List *L){
	int i, N;
	ElementType X;
	makenullList(L);
	scanf("%d", &N);
	
	for(i=1; i<=N; ++i){
		scanf("%d", &X);
		insertList(X, endList(*L), L);
	}
}

int member(int x, List L){
	for(int i=0 ; i<L.Last; ++i){
		if(L.Elements[i] == x)
		return 1;
	}
	return 0;
}

Position locate(ElementType X, List L){
	Position P;
	int found = 0;
	P = first(L);
	while(P!=endList(L) && found==0){
		if(retrieve(P, L) == X){
			found = 1;
		}else{
			P = next(P, L);
		}
	}
	return P;
}

