#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

void rellenarConjunto(char conj[7], char u[20]);
void imprimirConjunto(char conj[], int c, char name[]);
void ordenarConjunto(char conj[], int len);

int main(){
	srand(time(NULL));
	char univ[20];
	char conj1[7];
	char conj2[7];
	char conj3[7];

	for (int i = 0; i < 20; i++){
		univ[i] = i+97;
	}

	rellenarConjunto(conj1, univ);
	rellenarConjunto(conj2, univ);
	rellenarConjunto(conj3, univ);

	imprimirConjunto(conj1, 7, "c1");
	imprimirConjunto(conj2, 7, "c2");
	imprimirConjunto(conj3, 7, "c3");
	
	ordenarConjunto(conj1, 7);
	ordenarConjunto(conj2, 7);
	ordenarConjunto(conj3, 7);

	imprimirConjunto(conj1, 7, "c1");
	imprimirConjunto(conj2, 7, "c2");
	imprimirConjunto(conj3, 7, "c3");
	imprimirConjunto(univ, 20, "U");
	
	return 0;
}

void rellenarConjunto(char conj[7], char u[20]){
	int temp = 0;
	for(int i=0; i<7; i++){
		conj[i] = 126;
	}

	for(int i=0; i<7; i++){
		temp = rand()%20;
		if(i==0){
			conj[i] = u[temp];
		}
		for(int j=0; j<i; j++){
			if(conj[j]==u[temp]){
				conj[i] = 126;
				i=7;
				j=7;
			} else{
				conj[i] = u[temp];
			}
		}
	}
}

void imprimirConjunto(char conj[], int c, char name[]){
	int i = 0;
	printf("%s = {", name);
	while(conj[i]!=126 && i<c){
		printf("%c", conj[i]);
		if(i<c-1 && conj[i+1]!=126){
			printf(", ");
		}
		i++;
	}
	printf("}\n");
}

void ordenarConjunto(char conj[], int len){
	char tmp = 'a';
	for (int i=0; i < len; i++){
		for (int j=0; j < len; j++){
			if (conj[j] > conj[i]){
				tmp = conj[i];
				conj[i] = conj[j];
				conj[j] = tmp;
			}  
		}
	}
}

void unionConj(char conj1[], char conj2[], char res[]){
	
}

void menu(){
	printf("Que deseas hacer?\n");
	printf("1-Mostrar Conjunto Universo\n");
	printf("2-Generar Conjuntos\n");
	printf("3-Mostrar conjuntos\n");
	printf("4-Union\n");
	printf("5-Interseccion\n");
	printf("6-Diferencia\n");
	printf("7-Complemento\n");
	printf("8-Conjunto Potencia\n");
	printf("9-Producto cartesiano\n");
	printf("10-Igualdad\n");
	printf("11-Subconjunto\n");
	printf("12-Subconjunto propio\n");
}
