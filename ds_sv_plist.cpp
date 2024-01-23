#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
   char ID[10];
   char Name[50];
   float R1, R2, R3;
}Student;

typedef Student ElementType;
struct Node{
	ElementType Element;
	struct Node* Next;
};
typedef struct Node* List;



List getList(){
	List l = (struct Node*) malloc(sizeof(struct Node));
	l->Next = NULL;
	return l;
}

struct Node* locate(char x[], List l){
	struct Node* p = l;
	while(p->Next != NULL){
		if(strcmp(x, p->Next->Element.ID) == 0){
			return p;
		}
		p = p->Next;
	}
	return p;
}

int append(Student s, List *l){
	struct Node* p = *l;
	while(p->Next != NULL){
		if(strcmp(s.ID, p->Next->Element.ID) == 0) return 0;
		p = p->Next;
	}
	struct Node* t = (struct Node*) malloc(sizeof(struct Node));
	t->Element = s;
	t->Next = NULL;
	p->Next = t;
	return 1;
}


List readList(){
	List l;
	l = getList();
	int n;
	scanf("%d", &n);
	getchar();
	for(int i=1; i<=n; ++i){
		Student s;
		fgets(s.ID, sizeof(s.ID)+1, stdin);
		s.ID[strlen(s.ID)-1] = '\0';
		fgets(s.Name, sizeof(s.Name)+1, stdin);
		s.Name[strlen(s.Name)-1] = '\0';
		scanf("%f%f%f", &s.R1, &s.R2, &s.R3);
		getchar();
		
		struct Node* t = (struct Node*) malloc(sizeof(struct Node));
		t->Element = s;
		append(s, &l);
	}
	return l;
}

void printList(List L){
	int tt = 0;
	struct Node* p = L;
	while(p->Next != NULL){
		printf("%2d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n",
			++tt, p->Next->Element.ID, p->Next->Element.Name,
			 p->Next->Element.R1, p->Next->Element.R2, p->Next->Element.R3,
			 (p->Next->Element.R1 + p->Next->Element.R2 + p->Next->Element.R3)/3);
			 p = p->Next;
	}
}



/*

-----Điền chỗ trống hàm readList
	
	struct Node* p = locate(s.ID, L);
        if(p->Next == NULL){
        	append(s, &L);
		}else{
			printf("%s exists\n", s.ID);
		}
		
---Điền 2 ô chỗ trống:

	int tt = 0;
	struct Node* p = L;
	while(p->Next != NULL){
		printf("%2d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n",
			++tt, p->Next->Element.ID, p->Next->Element.Name,
			 p->Next->Element.R1, p->Next->Element.R2, p->Next->Element.R3,
			 (p->Next->Element.R1 + p->Next->Element.R2 + p->Next->Element.R3)/3);
			 p = p->Next;
		}
	
	
	
	
	
	List L = getList();
	L = readList();
	printList(L);
	
	
	
*/

