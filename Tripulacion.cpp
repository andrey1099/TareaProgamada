#include "Tripulacion.h"

void Tripulacion::copiar_cadena(char origen[], char destino[]) 
{
	int tamano = sizeof(origen) / sizeof(origen[0]);

	for (int i = 0; i < tamano; i++) {
		destino[i] = origen[i];
	}
}

Tripulacion::Tripulacion()
{
	piloto[30] = { 0 };
	coPiloto[30] = { 0 };
	auxiliarVuelo[30] = {0};
}

Tripulacion::Tripulacion(char pilotoAux[], char coPilotoAux[], char auxiliarVueloAux[])
{
	copiar_cadena(pilotoAux,piloto);
	copiar_cadena(coPilotoAux, coPiloto);
	copiar_cadena(auxiliarVueloAux, auxiliarVuelo);
}

Tripulacion::~Tripulacion()
{
}

char* Tripulacion::getPiloto()
{
	return piloto;
}

char* Tripulacion::getCoPiloto()
{
	return coPiloto;
}

char* Tripulacion::getAuxiliarVuelo()
{
	return auxiliarVuelo;
}

void Tripulacion::setPiloto(char pilotoAux[])
{
	copiar_cadena(pilotoAux, piloto);
}

void Tripulacion::setCoPiloto(char coPilotoAux[])
{
	copiar_cadena(coPilotoAux, coPiloto);
}

void Tripulacion::setAuxiliarVuelo(char auxiliarVueloAux[])
{
	copiar_cadena(auxiliarVueloAux, auxiliarVuelo);
}