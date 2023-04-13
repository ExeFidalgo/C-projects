#include <stdio.h>
#include <stdlib.h>
#define tam 50
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu();
void cargardatos(int *, int *,char *, int*, int *,char *,int *);
int informar(int*, int *,char *,int *);
int main(int argc, char *argv[]) {
	int opc,inicio;
	int code,codesuc,vcode[tam],vcodesuc[tam];
	int fichajes=0;
	char turno,turnos[tam];
	while(inicio!=3){
		menu();
		scanf("%d",&opc);
		switch(opc){
			
			case 1:
				system("cls");
				printf("\nIngrese codigo de empleado: ");
				fflush(stdin);
				scanf("%i",&code);
				printf("\nIngrese codigo de sucursal 1 - 2 - 3 - 4 : ");
				fflush(stdin);
				scanf("%d",&codesuc);
				printf("\nIngrese el turno");
				printf("\n'm'= mañana / 't'= tarde / 'n= noche'");
				printf("\n");
				fflush(stdin);
				scanf("%c",&turno);
				cargardatos(&code,&codesuc,&turno,vcode,vcodesuc,turnos,&fichajes);
				fichajes++;
				system("cls");
				break;
			case 2:
				informar(vcode,vcodesuc,turnos,&fichajes);
				break;
			case 3:inicio=3;
				break;		
				
		}
		
	}
	
	return 0;
}
void menu(){
	printf("\n");
	printf("\t--MENU--");
	printf("\n1-Ingresar datos de fichaje");
	printf("\n2-Generar informe de fichajes");
	printf("\n3-salir");
	printf("\nOpcion: ");
	fflush(stdin);
}
void cargardatos(int *code, int *codesuc,char *turno, int *vcode, int *vcodesuc,char *turnos,int *i){
	*(vcode+*i)=*code;
	*(vcodesuc+*i)=*codesuc;
	*(turnos+*i)=*turno;
}
int informar(int *vcode, int *vcodesuc,char *turnos,int *fichajes){
	int j;
	int x;
	int suc4=0;
	int fichajesC[3]={0,0,0};
	for(j=0;j<*fichajes;j++){
		switch(*(turnos+j)){
			case 'm':
				fichajesC[0]++;
				break;
			case 't':
				fichajesC[1]++;
				break;
			case 'n':
			fichajesC[2]++;
				break;
			
		}
	}
	for(x=0;x<*fichajes;x++){
		if(*(vcodesuc+x)==4){
			suc4++;
		}
	
	}
	system("cls");
	printf("\t ---Resultados---");


			printf("\nFichajes en turno mañana: %i",fichajesC[0]);
			printf("\nFichajes en turno tarde: %i",fichajesC[1]);
			printf("\nFichajes en turno noche: %i",fichajesC[2]);
	printf("\n-----------------------\n");
	printf("\nFichajes en sucursal 4 (%i)",suc4);
	printf("\n");
	system("pause");
	system("cls");
	
}
