#include "Interaccion.h"

using namespace std;

Interaccion::Interaccion()
{
}

Interaccion::~Interaccion()
{
}


void Interaccion::programarVuelo(Vuelos arrayVuelosAux[], int numMaxVuelosAux)
{
	system("cls");

	char modeloAvionAux[25];
	char pilotoAux[30];
	char coPilotoAux[30];
	char auxiliarVueloAux[30];
	char fechaVueloAux[20];
	char horaVueloAux[20];
	char puntoSalidaAux[50];
	char puntoDestinoAux[50];
	char duracionVueloAux[50];
	int asientosVueloAux;

	cout << "Digite el modelo del avion: ";
	cin.ignore(100, '\n');
	cin.getline(modeloAvionAux, 25, '\n');

	cout << "Digite el nombre del piloto del avion: ";
	cin.getline(pilotoAux, 30, '\n');

	cout << "Digite el nombre del copiloto del avion: ";
	cin.getline(coPilotoAux, 30, '\n');

	cout << "Digite el nombre del auxiliar de vuelo del avion: ";
	cin.getline(auxiliarVueloAux, 30, '\n');

	cout << "Digite la fecha del vuelo con el formato DD/MM/AAAA: ";
	cin.getline(fechaVueloAux, 20, '\n');

	cout << "Digite la hora del vuelo con el formato HH:MM:SS: ";
	cin.getline(horaVueloAux, 20, '\n');

	cout << "Digite el punto de salida del vuelo: ";
	cin.getline(puntoSalidaAux, 50, '\n');

	cout << "Digite el punto de destino del vuelo: ";
	cin.getline(puntoDestinoAux, 50, '\n');

	cout << "Digite la duracion del vuelo con el formato HH:MM:SS: ";
	cin.getline(duracionVueloAux, 50, '\n');

	cout << "Digite el numero de asientos del avion: ";
	cin >> asientosVueloAux;
	cout << endl;

	int numVuelosAux = arrayVuelosAux[0].getNumVuelos();
	arrayVuelosAux[numVuelosAux] = Vuelos(modeloAvionAux, pilotoAux, coPilotoAux, auxiliarVueloAux, fechaVueloAux, horaVueloAux, puntoSalidaAux, puntoDestinoAux, duracionVueloAux, asientosVueloAux);

	cout << "Vuelo ID #" << numVuelosAux << " creado";
	cout << endl << endl;

	cout << "Digite una tecla para continuar....";
	cin.ignore(); cin.ignore();
}

void Interaccion::descargarVuelos(Vuelos arrayVuelosAux[], int numMaxVuelosAux)
{

	ofstream vuelos_O;
	vuelos_O.open("vuelos.txt");

	if (vuelos_O.is_open())
	{
		for (int i = 0; i < arrayVuelosAux[0].getNumVuelos(); i++)
		{
			long inicioVuelo = std::chrono::duration_cast<std::chrono::milliseconds>(arrayVuelosAux[i].getInicioVuelo().time_since_epoch()).count();


			vuelos_O << arrayVuelosAux[i].getNumVuelo() << "," << arrayVuelosAux[i].getNumVuelos() << "," << arrayVuelosAux[i].getModeloAvion() << "," << arrayVuelosAux[i].getPiloto()
				<< "," << arrayVuelosAux[i].getCoPiloto() << "," << arrayVuelosAux[i].getAuxiliarVuelo() << "," << arrayVuelosAux[i].getFechaVuelo()
				<< "," << arrayVuelosAux[i].getHoraVuelo() << "," << arrayVuelosAux[i].getPuntoSalida() << "," << arrayVuelosAux[i].getPuntoDestino()
				<< "," << arrayVuelosAux[i].getDuracionVuelo() << "," << arrayVuelosAux[i].getNumAsientos() << "," << arrayVuelosAux[i].getEstadoVuelo()
				<< "," << arrayVuelosAux[i].getVueloVigente() << "," << inicioVuelo << "," << arrayVuelosAux[i].getHorasTranscurridas();

			for (int e = 0; e < arrayVuelosAux[i].getNumAsientos(); e++)
			{
				Asiento* asientoAux = arrayVuelosAux[i].getAsientos();

				vuelos_O << "," << asientoAux[e].getNumero() << "," << asientoAux[e].getUbicacion() << "," << asientoAux[e].getDisponible();
			}
			vuelos_O << std::endl;

		}
		vuelos_O.close();

		cout << "Datos Descargados exitosamente..." << endl << endl;
	}
	else
	{
		cout << "No se pudo abrir el archivo" << endl << endl;
	}

	cout << "Digite una tecla para continuar....";
	cin.ignore(); cin.ignore();
}

void Interaccion::cargarVuelos(Vuelos arrayVuelosAux[], int numMaxVuelosAux)
{
	ifstream archivo("vuelos.txt");

	char linea2[256]; // array de caracteres para almacenar cada línea del archivo

	if (archivo.getline(linea2, 256)) {

		int numVuelos = 0;
		archivo.seekg(0, ios::beg);

		while (!archivo.eof() && numVuelos < numMaxVuelosAux)
		{
			Vuelos v;


			int aux1;
			archivo >> aux1;
			archivo.ignore(1, ','); // ignorar la coma después del número de vuelo
			v.setNumVuelo(aux1);


			int aux2;
			archivo >> aux2;
			archivo.ignore(1, ','); // ignorar la coma después del número de vuelo
			v.setNumVuelos(aux2);


			char aux3[25];
			archivo.getline(aux3, 25, ',');
			v.setModeloAvion(aux3);

			char aux4[30];
			archivo.getline(aux4, 30, ',');
			v.setPiloto(aux4);

			char aux5[30];
			archivo.getline(aux5, 30, ',');
			v.setCoPiloto(aux5);

			char aux6[30];
			archivo.getline(aux6, 30, ',');
			v.setAuxiliarVuelo(aux6);

			char aux7[20];
			archivo.getline(aux7, 20, ',');
			v.setFechaVuelo(aux7);

			char aux8[20];
			archivo.getline(aux8, 20, ',');
			v.setHoraVuelo(aux8);

			char aux9[50];
			archivo.getline(aux9, 50, ',');
			v.setPuntoSalida(aux9);

			char aux10[50];
			archivo.getline(aux10, 50, ',');
			v.setPuntoDestino(aux10);

			char aux11[50];
			archivo.getline(aux11, 50, ',');
			v.setDuracionVuelo(aux11);

			int aux12;
			archivo >> aux12;
			archivo.ignore(1, ','); // ignorar la coma después del número
			v.setNumAsientos(aux12);

			char aux13[50];
			archivo.getline(aux13, 50, ',');
			v.setEstadoVuelo(aux13);

			int aux14;
			archivo >> aux14;
			archivo.ignore(1, ','); // ignorar la coma después del número
			v.setVueloVigente(aux14);

			long aux15;
			archivo >> aux15;
			archivo.ignore(1, ','); // ignorar la coma después del número
			std::chrono::milliseconds duracion(aux15);// Crear una duración a partir del valor long.
			std::chrono::steady_clock::time_point tiempo_inicio = std::chrono::time_point<std::chrono::steady_clock>(duracion);// Crear un objeto time_point a partir de la duración.
			v.setInicioVuelo(tiempo_inicio);

			int aux16;
			archivo >> aux16;
			v.setHorasTranscurridas(aux16);


			arrayVuelosAux[numVuelos] = v;
			numVuelos++;

		}


	}
	else
	{



	}
	archivo.close();
}

void Interaccion::imprimirVuelos(Vuelos arrayVuelosAux[])
{
	system("cls");

	for (int i = 0; i < arrayVuelosAux[0].getNumVuelos(); i++)
	{
		arrayVuelosAux[i].imprimirVuelo();

		cout << endl << endl;
	}

	cout << "Digite una tecla para continuar....";
	cin.ignore(); cin.ignore();
}

void Interaccion::consultarVuelo(Vuelos arrayVuelosAux[], int numMaxVuelosAux)
{
	system("cls");
	bool encontrado = false;
	int numVueloAux = 0;
	cout << "Digite el ID del vuelo para consultar: ";
	cin >> numVueloAux;
	cout << endl << endl;

	for (int i = 0; i < arrayVuelosAux[0].getNumVuelos(); i++)
	{
		if (numVueloAux == arrayVuelosAux[i].getNumVuelo())
		{
			cout << "La inforamacion del vuelo con ID#" << arrayVuelosAux[i].getNumVuelo() << " es:" << endl << endl;

			arrayVuelosAux[i].imprimirVuelo();

			encontrado = true;

			cout << endl << endl;
		}
	}

	if (encontrado == false)
	{
		cout << "Vuelo no encontrado" << endl << endl;
	}

	cout << "Digite una tecla para continuar....";
	cin.ignore(); cin.ignore();
}

void Interaccion::modificarEstadoVuelo(Vuelos arrayVuelosAux[], int numMaxVuelosAux)
{
	system("cls");
	bool encontrado = false;
	int numVueloAux = 0;
	char estadoVueloAux[50];
	cout << "Digite el ID del vuelo para modificar su estado: ";
	cin >> numVueloAux;
	cout << endl << endl;

	for (int i = 0; i < arrayVuelosAux[0].getNumVuelos(); i++)
	{
		if (numVueloAux == arrayVuelosAux[i].getNumVuelo())
		{
			cout << "El estado actual del vuelo con ID#" << arrayVuelosAux[i].getNumVuelo() << " es: " << arrayVuelosAux[i].getEstadoVuelo() << endl << endl;

			cout << "Los estados que puede colocar son los siguientes:" << endl << endl << endl << endl;
			cout << "Programado: un vuelo ha sido creado. En este momento unicamente existe" << endl;
			cout << "            pero no necesariamente tiene pasajeros asignados." << endl;
			cout << "Cancelado.: como algunas veces los vuelos no llegan a la cantidad minima de personas" << endl;
			cout << "            los vuelos pueden ser cancelados si no son rentables para la empresa." << endl;
			cout << "A_tiempo..: estado que se muestra cuando un vuelo ha sido confirmado, pero no ha salido." << endl;
			cout << "Retrasado.: si ha sufrido cambios en el horario." << endl;
			cout << "En_curso..: cuando el vuelo se está ejecutando en el aire." << endl;
			cout << "Aterrizado: cuando se ha confirmado que llegó a su destino." << endl << endl << endl << endl;


			cout << "Digite el nuevo estado  del vuelo con ID#" << arrayVuelosAux[i].getNumVuelo() << " : ";

			cin.ignore(100, '\n');
			cin.getline(estadoVueloAux, 50);

			arrayVuelosAux[i].setEstadoVuelo(estadoVueloAux);

			cout << "Estado Actualizado..." << endl << endl;


			chrono::steady_clock::time_point inicio_vueloAux = std::chrono::steady_clock::now();
			arrayVuelosAux[i].setInicioVuelo(inicio_vueloAux);

			encontrado = true;

			cout << endl << endl;
		}
	}

	if (encontrado == false)
	{
		cout << "Vuelo no encontrado" << endl << endl;
	}

	cout << "Digite una tecla para continuar....";
	cin.ignore();
}

void Interaccion::verificarAsientos(Vuelos arrayVuelosAux[], int numMaxVuelosAux)
{
	system("cls");
	bool encontrado = false;
	bool sinAsientos = true;
	int numVueloAux = 0;
	cout << "Digite el ID del vuelo para verificar sus asientos: ";
	cin >> numVueloAux;
	cout << endl << endl;

	for (int i = 0; i < arrayVuelosAux[0].getNumVuelos(); i++)
	{
		if (numVueloAux == arrayVuelosAux[i].getNumVuelo())
		{
			Asiento* asientoAux = arrayVuelosAux[i].getAsientos();

			for (int e = 0; e < arrayVuelosAux[i].getNumAsientos(); e++)
			{
				if (asientoAux[e].getDisponible() != false)
				{
					cout << "El asiento #" << e << " esta disponible" << endl;
					sinAsientos = false;
				}
				else
				{
					cout << "El asiento #" << e << " no esta disponible" << endl;
				}
			}

			encontrado = true;

			cout << endl << endl;
		}
	}

	if (encontrado == false)
	{
		cout << "Vuelo no encontrado" << endl << endl;
	}
	if (sinAsientos == true)
	{
		cout << "No hay Asientos disponibles" << endl << endl;
	}

	cout << "Digite una tecla para continuar....";
	cin.ignore(); cin.ignore();
}

void Interaccion::checkInVuelos(Vuelos arrayVuelosAux[], int numMaxVuelosAux)
{
	system("cls");
	bool encontrado = false;
	int numVueloAux = 0;
	int asientoDeseado = 0;
	char ubicacionDeseada[30];
	cout << "Digite el ID del vuelo para el que quiere hacer checkIn: ";
	cin >> numVueloAux;
	cout << endl << endl;

	for (int i = 0; i < arrayVuelosAux[0].getNumVuelos(); i++)
	{
		if (numVueloAux == arrayVuelosAux[i].getNumVuelo())
		{
			Asiento* asientoAux = arrayVuelosAux[i].getAsientos();

			cout << "Digite el numero de asiento que desea que este entre 0 y " << arrayVuelosAux[i].getNumAsientos() - 1 << endl;
			cout << "Asiento deseado: ";
			cin >> asientoDeseado;
			cout << endl << endl;

			if (asientoAux[asientoDeseado].getDisponible() != false)
			{
				cout << "El asiento esta disponible por favor digite la ubicacion que desee" << endl;
				cout << "Ventana" << endl;
				cout << "Medio" << endl;
				cout << "borde" << endl;
				cout << "Ubicacion deseada: ";
				cin.ignore(100, '\n');
				cin.getline(ubicacionDeseada, 30);


				asientoAux[asientoDeseado] = Asiento(asientoDeseado, ubicacionDeseada);

				cout << "Asiento reservado exitosamente..." << endl << endl;;
			}
			else
			{
				cout << "El asiento no esta disponible por favor consulte los asientos disponibles y trate de nuevo" << endl;
			}


			encontrado = true;

			cout << endl << endl;
		}
	}

	if (encontrado == false)
	{
		cout << "Vuelo no encontrado" << endl << endl;
	}

	cout << "Digite una tecla para continuar....";
	cin.ignore(); cin.ignore();
}


