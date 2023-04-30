#include "Asiento.h"

void Asiento::copiar_cadenaA(char origen[], char destino[])
{
	int tamano = sizeof(origen) / sizeof(origen[0]);

	for (int i = 0; i < tamano; i++) {
		destino[i] = origen[i];
	}
}

void Asiento::mi_strcpy(char* destino, const char* fuente)
{
	while (*fuente != '\0') {
		*destino = *fuente;
		destino++;
		fuente++;
	}
	*destino = '\0';
}

Asiento::Asiento()
{
	numero = 0;
	mi_strcpy(ubicacion, "vacio");
	disponible = true;
}

Asiento::Asiento(int numeroAux, char ubicacionAux[])
{
	numero = numeroAux;
	copiar_cadenaA(ubicacionAux, ubicacion);
	disponible = false;
}

Asiento::~Asiento()
{
}

int Asiento::getNumero()
{
	return numero;
}

char* Asiento::getUbicacion()
{
	return ubicacion;
}

bool Asiento::getDisponible()
{
	return disponible;
}