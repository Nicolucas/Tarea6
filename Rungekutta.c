/*---------------------------------------------------------
codigo que evoluciona un archivo con condiciones iniciales
-----------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
const float PI= 3.14159;
const float G= 1.31935 *pow(10,38); //Constante gravitacional en Km³/(mSolares * Myear²)
const float m=pow(10,12); //Masa solar
const float h=1;//million year

float func_prime_1(float x,float y_1,float x_1,float y_2,float *x_m,float *y_m,int *id,int a){
  return y_2;
}

float func_prime_2(float x,float y_1,float x_1,float y_2,float *x_m ,float *y_m,int *id, int a){
  float chapa1,chapa2;
  int ajiaco=sizeof(x_m);
  if (a != 1){
    
    float deltax,deltay;
    int i;
    
    for(i=0;i<ajiaco;i++){

    deltax=x_m[i]-y_1;
    deltay=y_m[i]-x_1;
    chapa1=pow(deltax,2)+pow(deltay,2);
    chapa2=-(G*m/pow(chapa1,(3/2)))*deltax;
    }
  }
  else{
    int i;

    for(i=0;i<ajiaco;i++){
      if(i==id[i]){
	continue;
      }
      float deltax=x_m[i]-y_1;
      float deltay=y_m[i]-x_1;
      chapa1=pow(deltax,2)+pow(deltay,2);
      chapa2=-(G*m/pow(chapa1,(3/2)))*deltax;
      }
  }
  return chapa2;
}

float *RungeKutta(float x_old, float y1_old,float x_1, float y2_old,float *x_m,float *y_m,int *id,int a){
  float k1= func_prime_1(x_old,y1_old,x_1,y2_old, x_m,y_m,id,a);
  float k11= func_prime_2(x_old,y1_old,x_1,y2_old, x_m, y_m,id,a);
  //Primer paso
  
  float x1=x_old + (h/2.0);
  float y1=y1_old + (h/2.0)*k1;
  float y11=y2_old + (h/2.0)*k11;

  float k2= func_prime_1(x1,y1,x_1,y11,x_m, y_m,id,a);
  float k21= func_prime_2(x1,y1,x_1,y11,x_m, y_m,id,a);

  //segundo paso
  
  float x2=x_old + (h/2.0);
  float y2=y1_old + (h/2.0)*k2;
  float y21=y2_old + (h/2.0)*k2;

  float k3= func_prime_1(x2,y2,x_1,y21,x_m, y_m,id,a);
  float k31= func_prime_2(x2,y2,x_1,y21,x_m, y_m,id,a);


  //tercer paso
  
  float x3=x_old + (h);
  float y3=y1_old + (h)*k3;
  float y31=y2_old + (h)*k31;

  float k4= func_prime_1(x3,y3,x_1,y31,x_m, y_m,id,a);
  float k41= func_prime_2(x3,y3,x_1,y31, x_m, y_m,id,a);

  //cuarto paso
  float prom_k1=(1.0/6.0)*(k1 + 2.0*k2+ 2.0*k3 + k4);
  float prom_k2=(1.0/6.0)*(k11 + 2.0*k21+ 2.0*k31 + k41);
  



  //entrega de datos
  float x_new =x_old + h;
  float y1_new=y1_old + h*prom_k1;
  float y2_new=y2_old + h*prom_k2;
  float *mojo = malloc(3*sizeof(float));
  mojo[0]=x_new;
  mojo[1]=y1_new;
  mojo[2]=y2_new;
  return mojo;

}
