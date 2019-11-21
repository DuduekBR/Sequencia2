#include <stdio.h>
#include <stdlib.h>
#define EXP_tam 50
typedef struct info{
	int *vetor;
	int tam_max, tam_atual;
	
}tInfo;
void expande(int *v, int *tam_max){
	tam_max += EXP_tam;
	int *aux = (int*)malloc(sizeof(int)**tam_max);
	free(v);
	v = aux;
}
void print(int* x, int a){
	for(int i =0; i<a; i++){
		printf("%d\t", x[i]);
	}
	printf("\n");
}
void plot(int *v, int * x){
	int i, n, aux;
	int *pot;
	pot = (int*)malloc(sizeof(int)**x);
	for(i=0;i<*x;i++){
		pot[i] = i+1;
	}
	for(i=0;i<*x;i++){
		for(n=i;n<*x;n++){
			if(v[i] > v[n]){
				aux = v[i];
				v[i] = v[n];
				v[n] = aux;
				
				aux = pot[i];
				pot[i]=pot[n];
				pot[n] = aux;
			
		}
	}
	}
	printf("\n\n\nCOMEÇOU\n");
	print(v, *x);
	print(pot, *x);
}
int main() {
  tInfo x;
  x.vetor = (int*)malloc(sizeof(int)*EXP_tam);
  x.tam_max = EXP_tam;
  char c;
	int i;
	for(i=0;;i++){
		
		scanf("%d%c", &x.vetor[i], &c);

		if(c == '\n'){
			break;
		}

		if(i == EXP_tam){
			expande(x.vetor, &x.tam_max);
		}	

	}
	x.tam_atual = i+1;
	plot(x.vetor, &x.tam_atual);	
  return 0;
}