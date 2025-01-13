#include "Functions.h"

int main(){
/*	int pisos=floors(), locales=locals(), opt; */
	int pisos, locales, opt;
	printf("Cuantos pisos tiene el centro comercial: ");
	scanf("%d",&pisos);
	printf("Cuantos espacios para locales tiene cada piso: ");
	scanf("%d", &locales);

	local_t **CenCom = malloc(pisos * sizeof(local_t *));
    for (int i = 0; i < pisos; i++){
    	CenCom[i] = malloc(locales * sizeof(local_t));
    }

		do{
			menu();
			scanf("%d",&opt);
			
			switch( opt ){
				case 1: addLocal(CenCom, pisos, locales);
						system("PAUSE");

					break;

				case 2: alquilarLocal(CenCom, pisos, locales);
						system("PAUSE");
					break;

				case 3: listarLocales(CenCom, pisos, locales);
						system("PAUSE");
					break;
			}

		}while(opt != 0);

	for (int i = 0; i < pisos; i++) {
        free(CenCom[i]);
    }
    free(CenCom);
	return 0;
}