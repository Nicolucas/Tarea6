
/*---------------------------------------------------------
Funciones
-----------------------------------------------------------*/  

float conv_kpc_m(float a){
  dato=a*3.0*pow(10.0,16.0);
  return dato;
}
// convierte de kpc a metros

float conv_m_kpc(float a){
  dato=a/(3.0*pow(10.0,16.0));
  return dato;
}
// convierte de metros a kpc

float conv_msolar_kg(float a){
  dato=a*(1.989*pow(10.0,30.0));
  return dato
}
// convierte de kg a masas solares

float conv_kg_msolar(float a){
  dato=a/(1.989*pow(10.0,30.0));
  return dato
}
// convierte de masas solares a kg

float magn_v(float m,float g, float r){
  dato=m*g/r;
  dato2=sqrt(dato);
  return dato2;
}
/*---------------------------------------------------------
a_centripeta=v²/r=M*G/r²
v²=M*G/r
magnitud de la velocidad en la orbita dada = sqrt(M*G/r)
-----------------------------------------------------------*/

