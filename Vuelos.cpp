#include "Vuelos.h"

int Vuelos::numVuelos = 0;


void Vuelos::mi_strcpy(char* destino, const char* fuente) 
{
	while (*fuente != '\0') {
		*destino = *fuente;
		destino++;
		fuente++;
	}
	*destino = '\0';
}

void Vuelos::copiar_cadenaV(char origen[], char destino[])
{
	int tamano = sizeof(origen) / sizeof(origen[0]);

	for (int i = 0; i < tamano; i++) {
		destino[i] = origen[i];
	}
}


Vuelos::Vuelos()
{
	numVuelo = 0;
	modeloAvion[25] = {0};
	tripulacion = Tripulacion();
	fechaVuelo[20] = { 0 };
	horaVuelo[20] = { 0 };
	puntoSalida[50] = { 0 };
	puntoDestino[50] = { 0 };
	duracionVuelo[50] = { 0 };
	asientos = nullptr;
	numAsientos = 0;
	estadoVuelo[50] = { 0 };
	vueloVigente = false;
	inicio_vuelo = std::chrono::steady_clock::now();
	horas_transcurridas = 0; 
}

Vuelos::Vuelos(char modeloAvionAux[],char pilotoAux[], char coPilotoAux[], char auxiliarVueloAux[], char fechaVueloAux[], 
			   char horaVueloAux[], char puntoSalidaAux[], char puntoDestinoAux[], char duracionVueloAux[], int numAsientosAux)
{
	numVuelo = numVuelos;
	numVuelos++;
	copiar_cadenaV(modeloAvionAux, modeloAvion);
	tripulacion = Tripulacion(pilotoAux, coPilotoAux, auxiliarVueloAux);
	copiar_cadenaV(fechaVueloAux, fechaVuelo);
	copiar_cadenaV(horaVueloAux, horaVuelo);
	copiar_cadenaV(puntoSalidaAux, puntoSalida);
	copiar_cadenaV(puntoDestinoAux, puntoDestino);
	copiar_cadenaV(duracionVueloAux, duracionVuelo);
	asientos = new Asiento[numAsientosAux];
	numAsientos = numAsientosAux;
	mi_strcpy(estadoVuelo, "Programado");

	vueloVigente = true;
	inicio_vuelo = std::chrono::steady_clock::now();
	std::chrono::steady_clock::duration calculoHoras = std::chrono::steady_clock::now() - inicio_vuelo;
	horas_transcurridas = std::chrono::duration_cast<std::chrono::hours>(calculoHoras).count();
}

int Vuelos::getNumVuelo()
{
	return numVuelo;
}

char* Vuelos::getModeloAvion()
{
	return modeloAvion;
}

int Vuelos::getNumVuelos()
{
	return numVuelos;
}

char* Vuelos::getPiloto()
{
	return tripulacion.getPiloto();
}

char* Vuelos::getCoPiloto()
{
	return tripulacion.getCoPiloto();
}

char* Vuelos::getAuxiliarVuelo()
{
	return tripulacion.getAuxiliarVuelo();
}

char* Vuelos::getFechaVuelo()
{
	return fechaVuelo;
}

char* Vuelos::getHoraVuelo()
{
	return horaVuelo;
}

char* Vuelos::getPuntoSalida()
{
	return puntoSalida;
}

char* Vuelos::getPuntoDestino()
{
	return puntoDestino;
}

char* Vuelos::getDuracionVuelo()
{
	return duracionVuelo;
}

int Vuelos::getNumAsientos()
{
	return numAsientos;
}

Asiento* Vuelos::getAsientos()
{

	return asientos;

}

char* Vuelos::getEstadoVuelo()
{
	return estadoVuelo;
}

bool Vuelos::getVueloVigente()
{
	return vueloVigente;
}

chrono::steady_clock::time_point Vuelos::getInicioVuelo()
{
	return inicio_vuelo;
}

int Vuelos::getHorasTranscurridas()
{
	return horas_transcurridas;
}

void Vuelos::setNumVuelo(int num) {
	numVuelo = num;
}

void Vuelos::setNumVuelos(int num) {
	numVuelos = num;
}

void Vuelos::setModeloAvion(char modelo[]) {
	mi_strcpy(modeloAvion, modelo);
}

void Vuelos::setPiloto(char piloto[]) {
	tripulacion.setPiloto(piloto);
}

void Vuelos::setCoPiloto(char coPiloto[]) {
	tripulacion.setCoPiloto(coPiloto);
}

void Vuelos::setAuxiliarVuelo(char AuxiliarVuelo[]) {
	tripulacion.setAuxiliarVuelo(AuxiliarVuelo);
}

void Vuelos::setFechaVuelo(char fecha[]) {
	mi_strcpy(fechaVuelo, fecha);
}

void Vuelos::setHoraVuelo(char hora[]) {
	mi_strcpy(horaVuelo, hora);
}

void Vuelos::setPuntoSalida(char punto[]) {
	mi_strcpy(puntoSalida, punto);
}

void Vuelos::setPuntoDestino(char punto[]) {
	mi_strcpy(puntoDestino, punto);
}

void Vuelos::setDuracionVuelo(char duracion[]) {
	mi_strcpy(duracionVuelo, duracion);
}

void Vuelos::setNumAsientos(int numAsientosAux){
	numAsientos = numAsientosAux;
}

void Vuelos::setEstadoVuelo(char estado[]) {
	mi_strcpy(estadoVuelo, estado);
}

void Vuelos::setVueloVigente(bool vigente) {
	vueloVigente = vigente;
}

void Vuelos::setInicioVuelo(chrono::steady_clock::time_point inicio) {
	inicio_vuelo = inicio;
}

void Vuelos::setHorasTranscurridas(int horas) {
	horas_transcurridas = horas;
}

void Vuelos::imprimirVuelo()
{
	cout << "El numero estatico del vuelo con ID#" << numVuelo << " es: " << numVuelos << endl;
	cout << "El modelo de avion del vuelo con ID#" << numVuelo << " es: " << modeloAvion << endl;
	cout << "El piloto del vuelo con ID#" << numVuelo << " es: " << getPiloto() << endl;
	cout << "El copiloto del vuelo con ID#" << numVuelo << " es: " << getCoPiloto() << endl;
	cout << "El auxiliar de vuelo del vuelo con ID#" << numVuelo << " es: " << getAuxiliarVuelo() << endl;
	cout << "La fecha del vuelo con ID#" << numVuelo << " es: " << fechaVuelo << endl;
	cout << "La hora del vuelo con ID#" << numVuelo << " es: " << horaVuelo << endl;
	cout << "El punto de salida del vuelo con ID#" << numVuelo << " es: " << puntoSalida << endl;
	cout << "El punto de destino del vuelo con ID#" << numVuelo << " es: " << puntoDestino << endl;
	cout << "La duracion del vuelo con ID#" << numVuelo << " es: " << duracionVuelo << endl;
	cout << "El numero de asientos del vuelo con ID#" << numVuelo << " es: " << numAsientos << endl;
	cout << "El estado del vuelo con ID#" << numVuelo << " es: " << estadoVuelo << endl;
	long inicioVuelo = std::chrono::duration_cast<std::chrono::milliseconds>(inicio_vuelo.time_since_epoch()).count();
	cout << "El inicio del vuelo con ID#" << numVuelo << " es: " << inicioVuelo << endl;
	cout << "Las horas transcurridas del vuelo con ID#" << numVuelo << " es: " << horas_transcurridas << endl;
}






Vuelos::~Vuelos()
{
	delete[] asientos;
}


