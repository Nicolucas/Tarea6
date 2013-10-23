#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int const PI= 3.14159;
int const G=6.67384*pow(10,-11);//en Nm²/kg²

float conv_kpc_m(float a);
float conv_m_kpc(float a);
float conv_msolar_kg(float a);
float conv_kg_msolar(float a);
float magn_v(float m,float g, float r);


//-------------Main---------------
int main(int argc, char **argv){
  system("clear");


  if(argc!=5){
    printf("Se requieren 4 datos para introducir para el centro de masa; \n-posicion inicial en eje x\n-posicion inicial en eje y\n-velocidad inicial en el eje x\n-velocidad inicial en el eje y");
    exit(1);
  }

  float xo=atof(argv[1]);
  float yo=atof(argv[2]);
  float V_xo=atof(argv[3]);
  float V_yo=atof(argv[4]);

  printf("Los datos introducidos fueron: \nX: %f\nY: nV_X %f\nV_Y%f\n",xo,yo,V_xo,V_yo);
 
/*------------------------------------------------------------------------
Checkpoint; Los datos de posicion y velocidades fueron introducidos
--------------------------------------------------------------------------*/
/*------------------------------------------------------------------------
Variables
Numero de estrellas
Output
distancia de las orbitas
Masa
--------------------------------------------------------------------------*/
  int num_particles=120; 
  FILE *output;
  float dist_orbi=10.0; //en kpc
  float masa=pow(10.0,12.0); //masas solares
	
/*---------------------------------------------------------
Data memory allocation
x,y estan en kpc
vx,vy estan en km/s
-----------------------------------------------------------*/ 
  float *x_axis;
  float *y_axis;
  float *Vx_axis;
  float *Vy_axis;
   
  x_axis = malloc(num_particles * sizeof(float));
  y_axis = malloc(num_particles * sizeof(float));
  Vx_axis = malloc(num_particles * sizeof(float));
  Vy_axis = malloc(num_particles * sizeof(float));

  if(!x_axis||!y_axis||!Vx_axis||!Vy_axis){
    printf("Algo salió mal con la reserva de espacio para los arrays x, y o velocidades\n");
    exit(1);
  }
/*---------------------------------------------------------
se tiene la magnitud de la velocidad dependiente de radio, masa y la constante G
-----------------------------------------------------------*/

/*---------------------------------------------------------
se les da un valor espacial a las particulas en cada orbita
primera: 12
segunda: 18
tercera: 24
cuarta: 30
quinta: 36

es decir se divide 2PI entre el numero de particulas en cada orbita, teniendo el angulo, se le da una ubicacion en coordenadas cartesianas considerando el radio y se les suma la posicion de la masa central
-----------------------------------------------------------*/ 
  int (par_1)=12;
  int (par_2)=18;
  int (par_3)=24;
  int (par_4)=30;
  int (par_5)=36;

  float firstorb=2*PI/(par_1);
  float secondorb=2*PI/(par_2);
  float thirdorb=2*PI/(par_3);
  float fourthorb=2*PI/(par_4);
  float fifthorb=2*PI/(par_5);

  int alpha=0;

  //radio =10 kpc
  float radio=10.0;

  for (int i=0;i<par_1;i++){
    x_axis[i]=radio*cos(firstorb*i);
    y_axis[i]=radio*sin(firstorb*i);
    
  }
  alpha+=(par_1);

 
/*---------------------------------------------------------
luego se calcula la magnitud de la velocidad de cada particula y se separa la componente vertical de la horizontal y se guarda en los array de velocidades, luego se suma la velocidad de la particula central
-----------------------------------------------------------*/ 

/*---------------------------------------------------------
se guarda la primera columna de datos introducidos en posicion -1 y los arrays en orden de posicones y velocidades de 0 hasta el numero de particulas
-----------------------------------------------------------*/ 

/*---------------------------------------------------------
se guarda en un archivo las columnas de datos
-----------------------------------------------------------*/
/*---------------------------------------------------------
FIN
-----------------------------------------------------------*/   
  return 0;
}

