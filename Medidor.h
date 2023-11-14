// -*- mode: c++ -*-

#ifndef MEDIDOR_H_INCLUIDO
#define MEDIDOR_H_INCLUIDO

// ------------------------------------------------------
// ------------------------------------------------------
class Medidor {
  // .....................................................
  // .....................................................
private:
  int pinVGas = 5;
  int pinVRef = 28; 
  int pinVTemp = 29;

public:
  float VeGas;
  float VeRef;
  float VeTemp;

  float aGas;
  float aRef;
  float aTemp;

  float Temp;
  float Vmedida;
  float Cx;
  float Itemp;
  float fCx;

  // .....................................................
  // constructor
  // .....................................................
  Medidor(  ) {
    pinMode(pinVGas,INPUT);
    pinMode(pinVRef,INPUT);
    pinMode(pinVTemp,INPUT);
  } // ()

  // .....................................................
  // .....................................................
  void iniciarMedidor() {

  
	// las cosas que no se puedan hacer en el constructor, if any
  } // ()

  // .....................................................
  // .....................................................
  int medirCO2() {
  aGas = analogRead(pinVGas);
  aRef = analogRead(pinVRef);
  aTemp = analogRead(pinVTemp);

  VeGas = (aGas/4096) * 3.3;
  VeRef = (aRef/4096) * 3.3;
  VeTemp = (aTemp/4096) * 3.3;

  Vmedida = VeGas - VeRef;

  Cx = (Vmedida)/(42.31 * 499 * 0.000001);
  
  Itemp = Temp - 20;
  fCx = Cx;

  if(Itemp > 20)
  {
    fCx = Cx - (Temp * 0.03);
  }
  if( Itemp < 20)
  {
    fCx = Cx + (Temp * 0.03);
  }
	return fCx;
  } // ()

  // .....................................................
  // .....................................................
  int medirTemperatura() {

  Temp = 87 * VeTemp - 18;
	return Temp; 
  } // ()
	
}; // class

// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------
// ------------------------------------------------------
#endif
