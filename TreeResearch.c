#include<stdio.h>
#include<stdlib.h>

typedef struct el{
	int v;
	struct el *left;
	struct el * right;
}Nodo;
typedef Nodo * Tree;

int somma(Tree);
int cercaMax(Tree);
Tree insert(Tree, int);

int main(){
	Tree t=NULL;

	t=insert(t,12);
	t=insert(t,1);
	t=insert(t,12);
	t=insert(t,20);
	t=insert(t,21);
	t=insert(t,15);

	printf("somma: %d, max val: %d\n", somma(t), cercaMax(t));

	return 0;
}

Tree insert(Tree t, int x){
	Tree tmp;

	if(t==NULL){
		tmp=(Tree)malloc(sizeof(Nodo));
		tmp->v=x;
		tmp->left=NULL;
		tmp->right=NULL;
		return tmp;
	}

	if(x < t->v){
		t->left=insert(t->left,x);
	}else if(x > t->v){
		t->right=insert(t->right,x);
	}

	return t;
}
