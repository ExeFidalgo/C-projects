#include <stdio.h>
#include <string.h>
#include <iostream>
#define v 50

void datos (int *v1, char *v2, int *v3, int *v4, int dia, char centro, int acce, int cant, int i);
void mostrar (int *v1, char *v2, int *v3, int *v4, int i);
int menu();

main ()
{
	int dia, acce, cant, i = 0, x;
	char centro, v2[v] = {' '};
	int v1[v] = {0}, v3[v] = {0},v4[v] = {0};
	
	x = menu();
	
	while ( x != 3){
		switch ( x ){
			case 1:
				printf("Ingrese el dia, del 1 al 31\n");
				fflush(stdin);
				scanf("%d", &dia);
				
				printf("Centro turistico a, b o c\n");
				fflush(stdin);
				scanf("%c", &centro);
				
				printf("Ingrese via de acceso: \n 1=Auto 2=Avion 3=Micro 4=Tren:\n");
				fflush(stdin);
				scanf("%d", &acce);
				
				printf("Cantidad de turistas: \n");
				fflush(stdin);
				scanf("%d", &cant);
				
				datos (v1, v2, v3, v4, dia, centro, acce, cant, i);
				i++;
				system("cls");
				break;
				
				case 2:
					mostrar (v1, v2, v3, v4, i);
				break;
		}
		x = menu();
	}	
}

menu (){
	int x;
	printf("\t\t Menu\n 1: Ingresar datos \n 2: Mostrar resultados \n 3: Salir.\n");
	fflush(stdin);
	scanf("%d", &x);
	
return x;
}
void datos (int *v1, char *v2, int *v3, int *v4, int dia, char centro, int acce, int cant, int i){
	*(v1 + i) = dia;
	*(v2 + i) = centro;
	*(v3 + i) = acce;
	*(v4 + i) = cant;
}
void mostrar(int *v1, char *v2, int *v3, int *v4, int i){
	int cant1=0, cant2=0, cont=0,j;
	char turi;
	printf("Centro turistico a, b, c, o d:\n");
	fflush(stdin);
	scanf("%c", &turi);
	
	for (j = 0; j < i; j++){
		if (*(v2 + j) == turi){
			if(*(v1 + j) <= 15){
				cant1 = cant1 + *(v4 + j);
				}
				else
				cant2 = cant2 + *(v4 + j);
				if (*(v3 + j) == 1){
					cont ++;
				}
			}
			}
			
			printf (" El centro turistico %c tuvo: \n 1er quincena: %d personas \n 2da quincena: %d personas\n", turi, cant1, cant2);
			printf ("Cantidad de auto que entraron a dicho centro: %d \n", cont);
			system("pause");
			system("cls");
		}
