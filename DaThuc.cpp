#include <stdio.h>
#include <malloc.h>

typedef struct {
    double he_so;
    int bac;
} DonThuc;

struct Node{
    DonThuc e;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position DaThuc;

DaThuc khoitao(){
	DaThuc d = (struct Node*)malloc(sizeof(struct Node));
	d->Next = NULL;
	return d;
}

void chenDonThuc(DonThuc s, DaThuc *d) {
	struct Node* p = *d;
	if(p->Next == NULL){
		struct Node* T;
		T = (struct Node*) malloc(sizeof(struct Node));
		T->e = s;
		T->Next = NULL;
		p->Next = T;
		return;
	}
	
	while(p->Next != NULL){
		if(p->Next->e.bac == s.bac){
			p->Next->e.he_so += s.he_so;
			return;
		}
		if(p->Next->e.bac < s.bac){
			struct Node* T;
			T = (struct Node*) malloc(sizeof(struct Node));
			T->e = s;
			T->Next = p->Next;
			p->Next = T;
			return;
		}
		
		p = p->Next;
	}
	struct Node* T;
	T = (struct Node*) malloc(sizeof(struct Node));
	T->e = s;
	T->Next = NULL;
	p->Next = T;
}



DaThuc nhapDaThuc(){
	DaThuc d;
	d = khoitao();
	int n;
	scanf("%d", &n);
	double a;
	int x;
	for(int i=1; i<=n; ++i){
		scanf("%lf%d", &a, &x);
		DonThuc e = {a, x};
		chenDonThuc(e, &d);
	}
	return d;
}


DaThuc congDaThuc(DaThuc d1, DaThuc d2){
	DaThuc sum = khoitao();
	
	struct Node* p = d1;
	while(p->Next != NULL){
		chenDonThuc(p->Next->e, &sum);
		p = p->Next;
	}
	
	p = d2;
	while(p->Next != NULL){
		chenDonThuc(p->Next->e, &sum);
		p = p->Next;
	}
	
	return sum;
}


void inDaThuc(DaThuc d){
	struct Node* p = d;
	while(p->Next != NULL){
		printf("%.3lfX^%d", p->Next->e.he_so, p->Next->e.bac);
		if(p->Next->Next != NULL)
			printf(" + ");
		p = p->Next;
	}
}

DaThuc nhanDaThuc(DaThuc d1, DaThuc d2){
	DaThuc d = khoitao();
	DonThuc x;
	struct Node* p = d1;
	while(p->Next != NULL){
		struct Node* q = d2;
		while(q->Next != NULL){
			x.he_so = p->Next->e.he_so * q->Next->e.he_so;
			x.bac = p->Next->e.bac + q->Next->e.bac;
			chenDonThuc(x, &d);
			q = q->Next;
		}
		p = p->Next;
	}
	return d;
}

DaThuc tinhDaoHam(DaThuc d){
	DaThuc l = khoitao();
	DonThuc x;
	struct Node* p = d;
	while(p->Next != NULL){
		if(p->Next->e.bac == 0){
			x.he_so = 0;
			x.bac = 0;
		}else{
			x.he_so = p->Next->e.he_so * p->Next->e.bac;
			x.bac = p->Next->e.bac -1 ;
		}
		chenDonThuc(x, &l);
		p = p->Next;
	}
	return l;
}



