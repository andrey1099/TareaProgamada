#ifndef TRIPULACION_H
#define TRIPULACION_H

class Tripulacion
{
public:
	Tripulacion();
	Tripulacion(char pilotoAux[], char coPilotoAux[], char auxiliarVueloAux[]);
	~Tripulacion();
	void copiar_cadena(char origen[], char destino[]);
	char* getPiloto();
	char* getCoPiloto();
	char* getAuxiliarVuelo();
	void setPiloto(char pilotoAux[]);
	void setCoPiloto(char coPilotoAux[]);
	void setAuxiliarVuelo(char auxiliarVueloAux[]);

private:

	char piloto[30];
	char coPiloto[30];
	char auxiliarVuelo[30];




};







#endif // !TRIPULACION

