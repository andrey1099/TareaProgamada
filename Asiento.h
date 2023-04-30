#ifndef ASIENTO_H
#define ASIENTO_H

class Asiento
{
public:

	Asiento();
	Asiento(int numeroAux, char ubicacionAux[]);
	~Asiento();
	void copiar_cadenaA(char origen[], char destino[]);
	void mi_strcpy(char* destino, const char* fuente);
	int getNumero();
	char* getUbicacion();
	bool getDisponible();

private:

	int numero;
	char ubicacion[30]; //A = Ventana B = Medio C = Borde
	bool disponible;

};










#endif // !ASIENTO_H
