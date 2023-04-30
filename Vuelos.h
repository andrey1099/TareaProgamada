#ifndef VUELOS_H
#define VUELOS_H

#include "Asiento.h"
#include "Tripulacion.h"
#include <iostream>
#include <chrono> //Manejo del tiempo

using namespace std; //Para no poner std antes de cada comando



class Vuelos
{
public:

	Vuelos();
	Vuelos(char modeloAvionAux[], char pilotoAux[], char coPilotoAux[], char auxiliarVueloAux[], char fechaVueloAux[],
		char horaVueloAux[], char puntoSalidaAux[], char puntoDestinoAux[], char duracionVueloAux[], int asientosVuelo);
	~Vuelos();

	void copiar_cadenaV(char origen[], char destino[]);
	void mi_strcpy(char* destino, const char* fuente);
	int getNumVuelo();
	int getNumVuelos();
	char* getModeloAvion();
	char* getPiloto();
	char* getCoPiloto();
	char* getAuxiliarVuelo();
	char* getFechaVuelo();
	char* getHoraVuelo();
	char* getPuntoSalida();
	char* getPuntoDestino();
	char* getDuracionVuelo();
	int getNumAsientos();
	Asiento* getAsientos();
	char* getEstadoVuelo();
	bool getVueloVigente();
	chrono::steady_clock::time_point getInicioVuelo();
	int getHorasTranscurridas();

	void setNumVuelo(int num);
	static void setNumVuelos(int num);
	void setModeloAvion(char modelo[]);
	void setPiloto(char piloto[]);
	void setCoPiloto(char coPiloto[]);
	void setAuxiliarVuelo(char auxiliarVuelo[]);
	void setFechaVuelo(char fecha[]);
	void setHoraVuelo(char hora[]);
	void setPuntoSalida(char punto[]);
	void setPuntoDestino(char punto[]);
	void setDuracionVuelo(char duracion[]);
	void setNumAsientos(int numAsientosAux);
	void setEstadoVuelo(char estado[]);
	void setVueloVigente(bool vigente);
	void setInicioVuelo(chrono::steady_clock::time_point inicio);
	void setHorasTranscurridas(int horas);

	void imprimirVuelo();


private:

	int numVuelo;
	static int numVuelos;
	char modeloAvion[25];
	Tripulacion tripulacion;
	char fechaVuelo[20];
	char horaVuelo[20];
	char puntoSalida[50];
	char puntoDestino[50];
	char duracionVuelo[50];
	Asiento* asientos;
	int numAsientos;
	char estadoVuelo[50];
	bool vueloVigente;
	chrono::steady_clock::time_point inicio_vuelo; //crea un punto en el tiempo que se usar a modo de cronometro
	int horas_transcurridas; //Variable para almacenar las horas transcurridas desde la ultima actualizacion
};



	
















#endif // !VUELOS_H

