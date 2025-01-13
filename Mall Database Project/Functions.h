#include <stdio.h>
#include <stdlib.h>


typedef struct Local{

	char name[20];
	int cod;
	int floor;
	int state;
	int cost;
	

}local_t;


void menu(){

	printf( "\n" );
  	printf( "QUE DESEA?\n" );
  	printf( "1. Agregar locales\n" );
  	printf( "2. Alquilar un local\n" );
  	printf( "3. Listar locales en el piso deseado\n" );
   	printf( "0. salir\n" );
   	printf( "opcion: " );

   	return;
}

int floors(){
	int pisos;
	printf("Cuantos pisos tiene el centro comercial: ");
	scanf("%d",&pisos);

	return pisos;
}

int locals(){
	int locales;

	printf("Cuantos espacios para locales tiene cada piso: ");
	scanf("%d", &locales);
	
	return locales;
}



local_t localData (){
	local_t local;

	printf("\nIngrese el codigo del local: ");
	scanf("%d", &local.cod);
	printf("\n");
	printf("Ingrese el nombre del local: ");
	fflush(stdin);
	fgets(local.name, 20, stdin);
	printf("\n");
	printf("Ingrese el estado del local (1: ocupado, 0: desocupado): ");
	scanf("%d", &local.state);
	printf("\n");
	printf("Ingrese el costo del arrendamiento del local: ");
	scanf("%d", &local.cost);
	printf("\n");

	return local;

}
void addLocal(local_t list[][50], int filas, int columnas){
	int j, numLocales, piso;
	


	printf("\nEn que piso desea adicionar el/los locales: ");
	scanf("%d", &piso);
	if(piso > filas){
		printf("Error! El piso %d no existe\n", piso );
	}
	else{
		printf("\nCuantos locales desea adicionar: ");
		scanf("%d", &numLocales );
		if(numLocales > columnas){
			printf("Error! hay suficiente espacio para %d locales\n", numLocales);
		}
		else{
			for(j=0;j<numLocales;j++){
				printf("\nIngrese los datos del local %d\n", j);
				list[piso][j] = localData();
			}
				
		}

	}

}

void alquilarLocal(local_t list[][50], int pisos, int locales){
	int j, pisoDeseado, budject;

	printf("\nDigite el piso en el que desea el local: ");
	scanf("%d",&pisoDeseado );
	if(pisoDeseado > pisos){
		printf("Error! El piso %d no existe\n", pisoDeseado );
		return;
	}
	printf("\nDigite el presupuesto que tiene para el arriendo del local: ");
	scanf("%d",&budject);
	for(j=0;j<locales;j++){
		if((list[pisoDeseado][j].state == 0) && (list[pisoDeseado][j].cost <= budject)){
			list[pisoDeseado][j].state = 1;
			break;
		}
		
	}
	printf("Usted acaba de alquilar el local %d\n",list[pisoDeseado][j].cod);

}


void listarLocales(local_t list[][50], int pisos, int locales){
	int j, floor;

	printf("En que piso desea ver los locales\n");
	scanf("%d",&floor);
	if(floor > pisos){
		printf("No existe el piso %d\n",floor );
	}
	for(j=0;j<locales;j++){
		printf("%d\n",list[floor][j].cod);
	}

}
