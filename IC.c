#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

float const PI= 3.14159265;
float const G=6.67384*pow(10,-11);//en Nm²/kg²

float conv_kpc_m(float a);
float conv_msolar_kg(float a);
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

  printf("Los datos introducidos fueron: \nX: %f\nY: %f\nV_X %f\nV_Y%f\n",xo,yo,V_xo,V_yo);
 
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
  char filename[100]="IC_output.dat";
  output=fopen(filename,"w");
        
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
    printf("Algo salio mal con la reserva de espacio para los arrays x, y o velocidades\n");
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
  int i=0;
  int k=0;

  //radio =10 kpc
  float radio1=10.0;

  for (i=0;i<par_1;i++){
    x_axis[i]=radio1*(cosf(firstorb*i))+xo;
    y_axis[i]=radio1*(sinf(firstorb*i))+yo;
  }
  k+=par_1;

  //radio =20 kpc
  float radio2 =20.0;

  for (i=0;i<par_2;i++){
    x_axis[i+k]=radio2*cosf(secondorb*i)+xo;
    y_axis[i+k]=radio2*sinf(secondorb*i)+yo;
  }
  k+=par_2;

  //radio =30 kpc
  float radio3 =30.0;

  for (i=0;i<par_3;i++){
    x_axis[i+k]=radio3*cosf(thirdorb*i)+xo;
    y_axis[i+k]=radio3*sinf(thirdorb*i)+yo;
  }
  k+=par_3;

  //radio =40 kpc
  float radio4 =40.0;

  for (i=0;i<par_4;i++){
    x_axis[i+k]=radio4*cosf(fourthorb*i)+xo;
    y_axis[i+k]=radio4*sinf(fourthorb*i)+yo;
  }
  k+=par_4;

  //radio =50 kpc
  float radio5 =50.0;

  for (i=0;i<par_5;i++){
    x_axis[i+k]=radio5*cosf(fifthorb*i)+xo;
    y_axis[i+k]=radio5*sinf(fifthorb*i)+yo;
  }

/*--------------------------------------------------------------
convierto los datos de entrada (radios en kpc y masa en masas solares) para que la velocidad me de en m/s
---------------------------------------------------------------*/
float m1;
float m2;
float m3;
float m4;
float m5;
float kg;

float conv_kpc_m(float a){
  if(a==radio1)
  {
    m1=radio1*3.0*pow(10.0,16.0);
    return m1;
  }
  
  else if(a==radio2)
  {
    m2=radio2*3.0*pow(10.0,16.0);
    return m2;
  }

  else if(a==radio3)
  {
    m3=radio3*3.0*pow(10.0,16.0);
    return m3;
  }

  else if(a==radio4)
  {
    m4=radio4*3.0*pow(10.0,16.0);
    return m4;
  }

  else
  {
    m5=radio5*3.0*pow(10.0,16.0);
    return m5;
  }
}

float conv_msolar_kg(float masa){
  kg = masa*(1.989*pow(10.0,30.0));
  return kg;
}

 
/*---------------------------------------------------------
luego se calcula la magnitud de la velocidad de cada particula y se separa la componente vertical de la horizontal y se guarda en los array de velocidades, luego se suma la velocidad de la particula central
-----------------------------------------------------------*/
  float V_orb_1;
  V_orb_1= magn_v(kg, G, m1);
  float V_orb_2;
  V_orb_2= magn_v(kg, G, m2);
  float V_orb_3;
  V_orb_3= magn_v(kg, G, m3);
  float V_orb_4;
  V_orb_4= magn_v(kg, G, m4);
  float V_orb_5;
  V_orb_5= magn_v(kg, G, m5);

  for (i=0;i<par_1;i++){
    Vx_axis[i]=V_orb_1*cosf(firstorb*i+PI/2)+V_xo;
    Vy_axis[i]=V_orb_1*sinf(firstorb*i+PI/2)+V_yo;
  }
  k+=par_1;

 for (i=0;i<par_2;i++){
    Vx_axis[i+k]=V_orb_2*cosf(secondorb*i+PI/2)+V_xo;
    Vy_axis[i+k]=V_orb_2*sinf(secondorb*i+PI/2)+V_yo;
  }
  k+=par_2;

 for (i=0;i<par_3;i++){
    Vx_axis[i+k]=V_orb_3*cosf(thirdorb*i+PI/2)+V_xo;
    Vy_axis[i+k]=V_orb_3*sinf(thirdorb*i+PI/2)+V_yo;
  }
  k+=par_3;

 for (i=0;i<par_4;i++){
    Vx_axis[i+k]=V_orb_4*cosf(fourthorb*i+PI/2)+V_xo;
    Vy_axis[i+k]=V_orb_4*sinf(fourthorb*i+PI/2)+V_yo;
  }
  k+=par_4;


 for (i=0;i<par_5;i++){
    Vx_axis[i+k]=V_orb_5*cosf(fifthorb*i+PI/2)+V_xo;
    Vy_axis[i+k]=V_orb_5*sinf(fifthorb*i+PI/2)+V_yo;
  }
/*---------------------------------------------------------
se guarda la primera fila de datos introducidos en posicion -1 y se guarda tambien los arrays en orden de posiciones y velocidades de 0 hasta el numero de particulas
-----------------------------------------------------------*/
 fprintf(output,"-1 %f %f %f %f\n",xo,yo,V_xo,V_yo);

 for(i=0;i<num_particles;i++){
   fprintf(output,"%d %f %f %f %f\n",i,x_axis[i],y_axis[i],Vx_axis[i],Vy_axis[i]);
 }

/*---------------------------------------------------------
FIN
-----------------------------------------------------------*/
 fclose(output);
 return 0;
}



/*---------------------------------------------------------
Funciones
-----------------------------------------------------------*/
//entran valores de masa, constante gravitacional y radio, devuelve la magnitud de la velocidad.
//Se requiere salida en terminos de m/s
float magn_v(float m,float g, float r){
  float dato=m*g/r;
  float dato2=sqrt(dato);
  return dato2;
}
