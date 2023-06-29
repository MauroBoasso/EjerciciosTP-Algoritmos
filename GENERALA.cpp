#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int numAleat ();
int dosIgual (int, int, int);
int GENERALA (int, int, int);
int ESCALERA (int, int, int);

int main(){
	system("mode con: cols=90 lines=30");
	system("color 03");
	int aleatCom(0), aleatUsu(0);
	int aleat1, aleat2, aleat3; 
	int aleat4, aleat5, aleat6; 
	int puntosCom(0), puntosUsu(0);
	srand (time(NULL));
	do {
		aleatCom = numAleat ();
		cout << "\tLa computadora estrajo " << aleatCom << "\t\t\t";
		system ("pause > NUL");
		aleatUsu = numAleat ();
		cout << "Usted estrajo " << aleatUsu << endl;
		if (aleatCom == aleatUsu)
			cout << endl << "\t\tComo lo extraido por usted y la computadora es igual: \n\n";
	} while (aleatCom == aleatUsu);
	cout << "\n\t\t\tPresione una tecla para comenzar el juego" << endl;
	system ("pause > NUL");
	system ("cls");
	
	if (aleatCom > aleatUsu){
		cout << "Gano la Computadora. Comienza el turno..." << endl << endl;
		for (int i = 1; i <= 10; i++){
			aleat1 = numAleat ();
			aleat2 = numAleat ();
			aleat3 = numAleat ();
			cout << "\nTurno " << i << endl;
			cout << "Computadora:" << endl;
			cout << "\n\tDadoUno " <<"("<< aleat1 <<")"<< "\tDadoDos " <<"("<< aleat2 <<")"<< "\tDadoTres " <<"("<< aleat3 <<")"<< endl;
			if (dosIgual(aleat1, aleat2, aleat3) > 0){
				cout << "\t\tDOBLE! Obtuvo " << dosIgual(aleat1, aleat2, aleat3) << " Puntos." << endl;
				puntosCom += dosIgual(aleat1, aleat2, aleat3);
			}
			else if (GENERALA (aleat1, aleat2, aleat3) == 50){
				cout << "\t\tGENERALA!!! Obtuvo " << 50 << " Puntos." << endl;
				puntosCom += 50;
			}
			else if (ESCALERA (aleat1, aleat2, aleat3) == 25){
				cout << "\t\tESCALERA!! Obtuvo " << 25 << " Puntos."<< endl;	
				puntosCom += 25;
			}else{
				cout << "\t\tNo obtuvo Puntaje." << endl;
			}
			cout << "\t\tPuntos en total " << puntosCom << "." << endl;
			
			system("pause > NUL");
			
			aleat4 = numAleat ();
			aleat5 = numAleat ();
			aleat6 = numAleat ();
			cout << "Usuario:" << endl;
			cout << "\n\tDadoCuatro " <<"("<< aleat4 <<")"<< "\tDadoCinco " <<"("<< aleat5 <<")"<< "\tDadoSeis " <<"("<< aleat6 <<")"<< endl;
			
			if (dosIgual(aleat4, aleat5, aleat6) > 0){
				cout << "\t\tDOBLE! Obtuvo " << dosIgual(aleat4, aleat5, aleat6) << " Puntos." << endl;
				puntosUsu += dosIgual(aleat4, aleat5, aleat6);
			}
			else if (GENERALA (aleat4, aleat5, aleat6) == 50){
				cout << "\t\tGENERALA!!! Obtuvo " << 50 << " Puntos." << endl;
				puntosUsu += 50;
			}
			else if (ESCALERA (aleat4, aleat5, aleat6) == 25){
				cout << "\t\tESCALERA!! Obtuvo " << 25 << " Puntos."<< endl;	
				puntosUsu += 25;
			}else{
				cout << "\t\tNo obtuvo Puntaje." << endl;
			}
			cout << "\t\tPuntos en total " << puntosUsu << "." << endl;
			system("pause > NUL");
			system("cls");
		}
	}
	else if (aleatCom < aleatUsu){
		cout << "Gano el usuario. Comienza el turno..." << endl << endl;
		for (int i = 1; i <= 10; i++){
			aleat1 = numAleat ();
			aleat2 = numAleat ();
			aleat3 = numAleat ();
			cout << "\nTurno " << i << endl;
			cout << "Usuario:" << endl;
			cout << "\n\tDadoUno " <<"("<< aleat1 <<")"<< "\tDadoDos " <<"("<< aleat2 <<")"<< "\tDadoTres " <<"("<< aleat3 <<")"<< endl;
			if (dosIgual(aleat1, aleat2, aleat3) > 0){
				cout << "\t\tDOBLE! Obtuvo " << dosIgual(aleat1, aleat2, aleat3) << " Puntos." << endl;
				puntosCom += dosIgual(aleat1, aleat2, aleat3);
			}
			else if (GENERALA (aleat1, aleat2, aleat3) == 50){
				cout << "\t\tGENERALA!!! Obtuvo " << 50 << " Puntos." << endl;
				puntosCom += 50;
			}
			else if (ESCALERA (aleat1, aleat2, aleat3) == 25){
				cout << "\t\tESCALERA!! Obtuvo " << 25 << " Puntos."<< endl;	
				puntosCom += 25;
			}else{
				cout << "\t\tNo obtuvo Puntaje." << endl;
			}
			cout << "\t\tPuntos en total " << puntosCom << "." << endl;
			
			system("pause > NUL");
			
			aleat4 = numAleat ();
			aleat5 = numAleat ();
			aleat6 = numAleat ();
			cout << "Computadoara:" << endl;
			cout << "\n\tDadoCuatro " <<"("<< aleat4 <<")"<< "\tDadoCinco " <<"("<< aleat5 <<")"<< "\tDadoSeis " <<"("<< aleat6 <<")"<< endl;
			
			if (dosIgual(aleat4, aleat5, aleat6) > 0){
				cout << "\t\tDOBLE! Obtuvo " << dosIgual(aleat4, aleat5, aleat6) << " Puntos." << endl;
				puntosUsu += dosIgual(aleat4, aleat5, aleat6);
			}
			else if (GENERALA (aleat4, aleat5, aleat6) == 50){
				cout << "\t\tGENEARALA!!! Obtuvo " << 50 << " Puntos." << endl;
				puntosUsu += 50;
			}
			else if (ESCALERA (aleat4, aleat5, aleat6) == 25){
				cout << "\t\tESCALERA!! Obtuvo " << 25 << " Puntos."<< endl;	
				puntosUsu += 25;
			}else{
				cout << "\t\tNo obtuvo Puntaje." << endl;
			}
			cout << "\t\tPuntos en total " << puntosUsu << "." << endl;
			system("pause > NUL");
			system("cls");
		}
	}
	return 0;
}

int numAleat (){
	return 1 + rand () % 6;
}

int dosIgual (int a, int b, int c){
	int sum = 0;
	if ((a == b) &&  (a != c))
		sum = a + b;
	else if ((a == c) &&  (a != b))
		sum = a + c;
	else if ((c == b) &&  (c != a))
		sum = c + b;
	return sum;
}

int GENERALA (int a, int b, int c){
	if ((a == b)&&(a == c)){
		return 50;
	}
	return 0;
}
int ESCALERA (int a, int b, int c){
	if (((a > b) && (a > c)) && (((a-1) == b) || ((a-1) == c))){
		if (b > c){
			if ((c+1) == b)
				return 25;
		}
		else if (c > b){
			if ((b+1) == c)
				return 25;
		}
	}
	else if (((b > a) && (b > c))  && (((b-1) == a) || ((b-1) == c))){
		if (a > c){
			if ((c+1) == a)
				return 25;
		}
		else if (c > a){
			if ((a+1) == c)
				return 25;
		}
	}
	else if (((c > b) && (c > a)) && (((c-1) == b) || ((c-1) == a))){
		if (b > a){
			if ((a+1) == b)
				return 25;
		}
		else if (a > b){
			if ((b+1) == a)
				return 25;
		}
	}
	return 0;
}
