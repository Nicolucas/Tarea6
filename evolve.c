/*---------------------------------------------------------
codigo que evoluciona un archivo con condiciones iniciales
-----------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define PI 3.14159

float fun_prime (int n, float t, float x, float y, float V_x, float V_y);

//Main
int main(int argc, char **argv){
  system("clear");

/*---------------------------------------------------------
llama el archivo producido y lo coloca en distintos arrays cada columna
-----------------------------------------------------------*/  
    FILE *ic = fopen(argv[1], "r");
 	
    float *xo;
    float *yo;
    float *V_xo;
    float *V_yo;
    
    xo= malloc(120*sizeof(float));
    yo= malloc(120*sizeof(float));
    V_xo= malloc(120*sizeof(float));
    V_yo= malloc(120*sizeof(float));

    
/*---------------------------------------------------------
Usando RUNGEKUTTA:
se aplica a cada particula alrededor de la particula central el cambio de posicion y 
velocidades dado por la interaccion con cada particula central presente por cada cambio de tiempo 
-----------------------------------------------------------*/  

    int h=5000;
    int n=1000;
    float *x;
    float *y;
    float *V_x;
    float *V_y;
    x= malloc(n*sizeof(float));
    y= malloc(n*sizeof(float));
    V_x= malloc(n*sizeof(float));
    V_y= malloc(n*sizeof(float));
	

    	

/*---------------------------------------------------------
exporta los datos de posicion y velocidades por cada particula en varios archivos que representan una ubicacion en el tiempo
-----------------------------------------------------------*/  

/*---------------------------------------------------------
FIN
-----------------------------------------------------------*/   
  return 0;
}
float fun_prime (int n,float t, float x, float y, float V_x, float V_y){

	float *posicion;
        float *velocidad;
        posicion= malloc(n*sizeof(float));
	velocidad= malloc(n*sizeof(float));

        return n;

    }
