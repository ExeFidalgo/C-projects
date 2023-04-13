#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu();       //PROTOTIPO DE LAS FUNCIONES
void cargar(int numero, char posicion, int puntaje, int *v1, char *v2, int *v3, int i);
void informar(int puntajeEnemigo, int *v1, char *v2, int *v3);

main(){  //INICIO DEL MAIN
	
	int xxx, i=0, puntajeEnemigo=0, numero, tiroZona, tiroFuera, tiroLibre, respuesta, puntaje=0;
	int v1[50]={0}, v3[50]={0};
	char posicion, v2[50]={""};
	
	xxx=menu(); //INVOCO LA FUNCION MENU Y GUARDO EL VALOR QUE DEVUELVE EN XXX
	
	while(xxx!=4){ // INICIO DEL WHILE (EVALUO QUE XXX SEA DISTINTA DE 4)
		switch(xxx){ //INICIO DEL SWITCH (USO LA MISMA VARIABLE XXX QUE USE EN EL WHILE)
			case 1:printf("Ingrese el puntaje final del equipo contrario.\n");
			       scanf("%d", &puntajeEnemigo);
			       break;                //CASO 1 INGRESO EL PUNTAJE DEL ENEMIGO
			       
			case 2:do{ /*EN ESTE CASO USO UN DO WHILE PARA REGISTRAR LOS DATOS DE LOS JUGADORES HASTA
					   QUE NO HAYA MAS COMO RESPUESTA AL CIERRE DEL DO WHILE*/				
			       printf("Igresar el numero de camiseta.\n");
			       scanf("%d", &numero);
			       
			       printf("Ingresar posicion en la cancha:\nb=base.\np=pilar.\nd=defensor.\n");
			       fflush(stdin);
			       scanf("%c", &posicion);
			       
			       printf("Ingresar cantidad de tiros en la zona anotados.\n");
			       scanf("%d", &tiroZona);
			       
			       printf("Ingresar cantidad de tiros fuera de la zona anotados.\n");
			       scanf("%d", &tiroFuera);
			       
			       printf("Ingresar cantidad de tiros libres anotados.\n");
			       scanf("%d", &tiroLibre);
			       
			       puntaje=(tiroZona*2+tiroFuera*3+tiroLibre*1); //CALCULO EL PUNTAJE QUE HIZO EL JUGADOR
			       
			       cargar(numero, posicion, puntaje, v1, v2, v3, i);//INVOCO LA FUNCION PARA CARGAR LOS VECTORES 
			       
			       i++; //SUMO 1 A I PARA QUE EN LA PROXIMA VUELTA CARGUE LOS VECTORES EN LA POCICION 1
			       
			       printf("Hay mas datos de jugadores para ingresar? 1=SI, 2=NO\n");
			       scanf("%d", &respuesta);
			       system("cls");           //PREGUNTA PARA FINALIZAR EL INGRESO DE DATOS DE JUGADORES
			       }while(respuesta==1);
			       
			       break;
			       
			case 3:	informar(puntajeEnemigo, v1, v2, v3); 
			        break;  //INVOCO LA FUNCION INFORMAR CON LOS VECTORES CARGADOS Y EL PUNTAJE ENEMIGO
		}
	xxx=menu();// VUELVO A INVOCAR LA FUNCION MENU ARRIBA DE LA LLAVE DE CIERRE DEL WHILE PARA ACTUALIZAR EL VALOR DE XXX
	}		
}
                      //CUERPO DE LAS FUNCIONES
int menu(){
int xxx;
printf("\t\tMENU\n1-Ingresar puntaje final del equipo contrario.\n2-Ingresar datos de jugadores de la seleccion argentina que participaron del partido.\n3-Evaluacion del partido.\n4-Salir.\n");
scanf("%d", &xxx);	
system("cls");
return xxx;	
}

void cargar(int numero, char posicion, int puntaje, int *v1, char *v2, int *v3, int i){
	
	*(v1+i)=numero;      //CARGO LOS VECTORES CON LOS DATOS DE LOS JUGADORES
	*(v2+i)=posicion;
	*(v3+i)=puntaje;
}

void informar(int puntajeEnemigo, int *v1, char *v2, int *v3){
	int i, cont1=0, cont2=0, cont3=0, max, num, total=0;
	
	max=*(v3);  //GUARDO LA POCICION 0 DEL VECTOR EN LA VARIABLE MAX (CONTIENE EL PUNTAJE)
	num=*(v1);  //GUARDO LA POCICION 0 DEL VECTOR EN LA VARIABLE NUM (CONTIENE EL NUMERO DE CAMISETA)
	
	for(i=0; i<50; i++){
		switch(*(v2+i)){             //SWITCH PARA CONTAR CUANTOS JUGADORES HUBO EN CADA POSICION
			case 'b':cont1++; break;
			case 'p':cont2++; break;
			case 'd':cont3++; break;
		}
		if(*(v3+i)>max){ //COMPARO EL VECTOR CON LA POCICION 0 QUE GUARDE ANTES Y SI ES MAYOR ACTUALIZO A MAX Y NUM
		max=*(v3+i);
		num=*(v1+i);	
		}
		
		total=total+*(v3+i); //ACUMULO EL TOTAL DE PUNTOS DE ARGENTINA SUMANDO EL DE TODOS LOS JUGADORES
		
	}
	//HAGO LOS INFORMES DEL PUNTO A, B Y C FUERA DEL FOR
  printf("La cantidad de jugadores que jugaron en cada posicion es:\nBase: %d\nPilar: %d\nDefensor: %d\n", cont1, cont2, cont3);
  printf("El numero de camiseta del jugador que hizo mas puntos es: %d\n", num); 
  printf("El puntaje total obtenido en el partido es: %d\n", total);
  
  if(total>puntajeEnemigo) //COMPARO EL PUNTAJE DE ARGENTINA CON EL INGRESADO DEL EQUIPO ENEMIGO E INFORMO SI GANO O PERDIO
  printf("GANO\n");
  else
  printf("PERDIO\n");
  system("pause");
}