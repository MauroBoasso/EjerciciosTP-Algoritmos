
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
using namespace std;
void linCaractInicio(int cantidad);
void linCaractFin(int cantidad);
void caractLetraIoL(int parte);
void caractLaterales();
void margen();
void titulo();
void margen(SHORT x,SHORT y);
void raya();
short bienvenida();
void separacion();
int main(){
	system("mode con: cols=200 lines=100");
	system("color 02"); //fondo negro y letras verdes
	srand(time(NULL));
	short x, y;
	int secreto=(rand()%100)+1;
	int numero=0;
	int intento=10; 
	titulo();
	x=15; 
	y=15;
	//Ubica el cursor en x=y=15 e imprime mensaje
	margen(x,y);
	cout << "BIENVENID@S!";
	//Baja dos filas y se corre cuatro columnas a la derecha e imprime mensaje
	x+=4; y+=2;
	margen(x,y); cout << "INICIO DEL JUEGO... Buena Suerte!";
	//Baja dos filas para abajo e imprime mensaje
	y+=2;
	margen(x,y); cout << "Adivina el número secreto - Ingresa un número del uno al cien (incluidos)";
	//Los intentos se van a repetir hasta que se hayan hecho 10 intentos o hasta que se adivine el número
	while(intento>0 && numero!=secreto){
		//Va bajando dos filas e imprimiendo mensaje para ingresar el número
		y+=2;
		margen(x+2,y); cout << "> Intento " << 11-intento << " >>> ";
		cin >> numero;
		y++;
		//Si se ingresa un número que esté fuera del rango de 1 a 100 se pide volver a ingresar el número y no se cuenta como un intento
		while(numero<1 || numero>100){
			margen(x+6,y); cout << "El número que ingresaste no está en el rango de 1 a 100. Reingrésalo.";
			y+=2;
			margen(x+2,y); cout << "> Intento " << 11-intento << " >>> ";
			cin >> numero;
			y++;
		}
		//Si el número ingresado conicide con el número secreto se imprime mensaje de éxito antes de salir del bucle
		if(numero==secreto){
			y+=3; margen(x,y); cout << "FELICITACIONES! HAZ GANADO LA PARTIDA";
			y+=2; margen(x,y); cout << "Tu puntaje final: " << intento;
			y+=2; margen(x+4,y); 
			if(intento!=10){
				cout << "Puedes volver a jugar y mejorar tu puntaje";
			}else{
				cout << "Puedes aprovechar tu suerte y volver a jugar";
			}
		}else{
			//Si no se adivina el número se imprime Frio o Caliente según corresponda
			if(numero>secreto){
				margen(x+6,y); cout << "Caliente";
			}else{
				margen(x+6,y); cout << "Frio";
			}
			y++;
			margen(x+6,y); cout << "Se te descuenta un punto";
		}
		//Descuento por cada inntento
		intento--;
		//Si se acaban los intentos se imprime el mensaje correspondiente
		if(intento==0 && numero!=secreto){
			y+=3;
			margen(x,y); cout << "Fin del juego... Se te han acabado los intentos";
			y++;
			margen(x,y); cout << "Tu puntaje final: " << intento;
			y+=2;
			margen(x,y); cout << "No te desanimes... Inténtalo de nuevo";
		}
	}
	return 0;
}
void raya(){
	//Imprime un espacio al principio y luego guiones bajos hasta el otro lado de la pantalla
	cout << " ";
	for(int i=0; i<196; i++){
		cout << "#";
	}
}
void titulo(){
	//Imprimo línea de guiones bajos
	raya();
	//Defino posición inicial de cursor en pantalla
	short x=76;
	short y=3;
	//Defino un margen - Cada columnas de funciones es una letra => cada fila de funciones es una parte de cada letra empezando desde arriba
	//Voy incrementando el número de fila
	margen(x,y); y++; linCaractInicio(7); linCaractInicio(0); caractLetraIoL(1); linCaractInicio(7); linCaractInicio(0); caractLetraIoL(1);
	margen(x,y); y++; linCaractInicio(2); linCaractInicio(0); caractLetraIoL(0); linCaractInicio(2); linCaractInicio(0); caractLetraIoL(1);
	margen(x,y); y++; linCaractInicio(2); linCaractInicio(7); caractLetraIoL(1); linCaractInicio(2); linCaractInicio(7); caractLetraIoL(1);
	margen(x,y); y++; linCaractInicio(6); linCaractInicio(2); caractLetraIoL(1); linCaractInicio(2); linCaractFin(2);    caractLetraIoL(1);
	margen(x,y); y++; linCaractInicio(2); linCaractInicio(2); caractLetraIoL(1); linCaractInicio(2); linCaractInicio(7); caractLetraIoL(1);
	margen(x,y); y++; linCaractInicio(2); linCaractInicio(2); caractLetraIoL(1); linCaractInicio(2); caractLaterales();  caractLetraIoL(1);
	margen(x,y);      linCaractInicio(2); linCaractInicio(2); caractLetraIoL(2); linCaractInicio(7); linCaractInicio(7); caractLetraIoL(2);
	//Reajusto margen e imprimo linea de guiones bajos
	margen(0,y+3);	raya();
}
//PARTES DE LETRAS - dentro de las funciones se utilizan for aunque sean pocas o una iteraciones pero lo hago así para que se pueda modificar el los anchos que se quieran
void separacion(){
	//Imprime dos espacios vacíos
	for(int i=0; i<2; i++){
		cout << " ";
	}
}
void linCaractInicio(int cantidad){
	int c=219;
	//Imprimo separación entre letras
	separacion();
	//Imprime en una misma linea una cantidad de caracteres rellenados determinada por 'cantidad'
	for(int i=0; i<cantidad; i++){
		cout << (char) c;
	}
	//Si 'cantidad'<7 imprime la cantidad de caracteres y el resto de caracteres hasta 7 se completa con espacios
	if(cantidad<7){
		cantidad=7-cantidad;
		for(int j=0; j<cantidad; j++){
			cout << " ";
		}
	}
}
void linCaractFin(int cantidad){
	int c=219;
	//Imprimo separación entre letras
	separacion();
	//Imprime en una misma línea espacios en blanco 7-'cantidad' veces
	for(int j=0; j<(7-cantidad); j++){
		cout << " ";
	}
	//Después de los espacios en blanco se imprimen caracteres rellenados hasta llegas a 7 caracteres
	for(int i=0; i<cantidad; i++){
		cout << (char) c;
	}
}
void caractLetraIoL(int parte){
	int c=219;
	//Imprimo separacion entre variables
	separacion();
	//Si 'parte'==0 imprimo 5 espacios => va a ser la parte de la i entre el punto y el resto del cuerpo de la i
	if(parte==0){
		for(int i=0; i<3; i++){
			cout << " ";
		}
	}else{
		if(parte==1){
			//Si 'parte'==1 imprime 2 caracteres rellenados y un espacio después => va a ser el cuerpo de la i o l
			for(int j=0; j<2; j++){
				cout << (char) c;
			}
			cout << " ";
		}else if(parte==2){
			//Si 'parte'==1 imprime 3 caracteres rellenados => va a ser parte de abajo de la i o l
			for(int j=0; j<3; j++){
				cout << (char) c;
			}
		}
	}
}
void caractLaterales(){
	int c=219;	
	//Imprimo separacion entre variables
	separacion();
	//Imprime en una misma línea 2 caracteres de relleno, 3 espacios y 2 caracteres de relleno => toma las paredes de una letra con el interior vació
	for(int i=0; i<5; i++){
		if(i==2){
			//Espaciado interior
			for(int j=0; j< 3; j++){
				cout << " ";
			}
		}else{
			//Paredes
			cout << (char) c;
		}
	}
}
void margen(SHORT x,SHORT y){
	//Coloca el cursor en la posición de la pantalla que se le indique mediante x e y
	COORD par={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), par);
}
