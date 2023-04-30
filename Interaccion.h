#ifndef INTERACCION_H
#define INTERACCION_H

#include "Vuelos.h"
#include <fstream>

class Interaccion
{
public:
	Interaccion();
	~Interaccion();
	void programarVuelo(Vuelos arrayVuelosAux[], int numMaxVuelosAux);
	void descargarVuelos(Vuelos arrayVuelosAux[], int numMaxVuelosAux);
	void cargarVuelos(Vuelos arrayVuelosAux[], int numMaxVuelosAux);
	void imprimirVuelos(Vuelos arrayVuelosAux[]);
	void consultarVuelo(Vuelos arrayVuelosAux[], int numMaxVuelosAux);
	void modificarEstadoVuelo(Vuelos arrayVuelosAux[], int numMaxVuelosAux);
	void verificarAsientos(Vuelos arrayVuelosAux[], int numMaxVuelosAux);
	void checkInVuelos(Vuelos arrayVuelosAux[], int numMaxVuelosAux);
private:

};





#endif // !INTERACCION_H

