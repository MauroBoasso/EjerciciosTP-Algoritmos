#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
using namespace std;
void linCaractInicio(int cantidad);
void linCaractFin(int cantidad);
void caractLetraI(int parte);
void caractLaterales();
void caractLetraT();
void margen();
void titulo();
void margen(SHORT x,SHORT y);
void raya();
short bienvenida();
void separacion();
void tijera(short x,short y);
void papel(short x,short y);
void piedra(short x,short y);
void ronda(short x,short y,int computadora, int usuario);
void elemento(short x, short y,int numElemento);
short resultato(short x, short y, int computadora, int usuario);

int main(){
	system("mode con: cols=200 lines=500");
	system("color 02"); //fondo negro y letras verdes
	short x, y;
	int usuario;
	int computadora;
	int puntajeUsuario=0; 
	titulo();
	x=15; 
	y=15;
	//Ubica el cursor en x=y=15 e imprime mensaje
	margen(x,y);
	cout << "BIENVENID@S!";
	//Baja dos filas, se corre 4 columnas a la derecha e imprime mensaje
	x+=4; y+=2;
	margen(x,y); cout << "INICIO DEL JUEGO... Buena Suerte!";
	//Se van a dar cinco rondas
	for(int i=0; i<10; i++){
		y+=2; margen(x+4,y); cout << "RONDA " << i+1 << ":"; y++; margen(x+4,y); for(int i=0; i<7; i++){ cout << "~";}
		y++; margen(x+6,y); cout << "> Ingrese 1 (Piedra) - 2 (Papel) - 3 (Tijera): >>> ";
		cin >> usuario;
		//Si se ingresa un número que no esté en el rango de 1 a 3 se pide reingresar el número y no se cuenta como una ronda
		while(usuario<1 || usuario>3){
			y+=2; margen(x+4,y); cout << "RONDA " << i+1 << ":"; y++; margen(x+4,y); for(int i=0; i<7; i++){ cout << "~";}
			y++; margen(x+6,y); cout << "> Ingrese 1 (Piedra) - 2 (Papel) - 3 (Tijera): >>> ";
			cin >> usuario;
		}
		//Determinación de número aleatorio
		srand(time(NULL));
		computadora=(rand()%3)+1;
		//Muestra gráfica de los resultados de la ronda
		y=resultato(x,y,computadora,usuario);
		//Impresión del resultado de la ronda
		margen(x+30,y+1); cout << "=) ";
		if((computadora==3 && usuario==1) || (computadora==2 && usuario==3) || (computadora==1 && usuario==2)){
			cout << "Ganaste la ronda. Un punto más para vos.";
			puntajeUsuario++;
		}else if((computadora==1 && usuario==3) || (computadora==3 && usuario==2) || (computadora==2 && usuario==1)){
			cout << "Perdiste la partida. No sumas un punto.";
		}else{
			cout << "Empataste la ronda. No sumas un punto.";
		}
		cout << " (=";
		y+=3;
	}
	//Mensaje final con el puntaje obtenido
	y+=2; margen(x,y); cout << "FIN DEL JUEGO...No quedan más rondas...";
	y+=2; margen(x,y); cout << "PUNTAJE QUE OBTUBISTE: " << puntajeUsuario;
	y+=2; margen(x+4,y); 
	if(puntajeUsuario>=4){
		cout << "Muy bien! Puedes volver a jugar y tener el mismo éxito...";
	}else if(puntajeUsuario==3){
		cout << "Bien! Puedes volver a jugar y superarte...";
	}else{
		cout << "Puedes volver a jugar y mejorar tu puntaje...";
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
	//Muestra de dibujo de elemento
	short x=35; short y=6;
	piedra(x,y); papel(x+10,y-1); tijera(x+21,y);
	
	//x+=26; margen(x,y); cout << "H"; 
	//x+=89; margen(x,y+3); cout << "H";
	
	tijera(x+103,y); papel(x+113,y-1); piedra(x+124,y); 
	//Defino posición inicial de cursor en pantalla
	x=74; y=3;
	//Defino un margen - Cada columnas de funciones es una letra => cada fila de funciones es una parte de cada letra empezando desde arriba
	//Voy incrementando el número de fila
	margen(x,y); y++; linCaractInicio(8); caractLetraI(1); linCaractInicio(8); linCaractInicio(0); linCaractInicio(8); caractLetraI(1);
	margen(x,y); y++; caractLaterales();  caractLetraI(0); caractLaterales();  linCaractInicio(0); caractLetraT();     caractLetraI(0);
	margen(x,y); y++; caractLaterales();  caractLetraI(1); caractLaterales();  linCaractInicio(8); caractLetraT();     caractLetraI(1);
	margen(x,y); y++; linCaractInicio(8); caractLetraI(1); linCaractInicio(8); linCaractFin(2);    caractLetraT();     caractLetraI(1);
	margen(x,y); y++; linCaractInicio(2); caractLetraI(1); linCaractInicio(2); linCaractInicio(8); caractLetraT();     caractLetraI(1);
	margen(x,y); y++; linCaractInicio(2); caractLetraI(1); linCaractInicio(2); caractLaterales();  caractLetraT();     caractLetraI(1);
	margen(x,y);      linCaractInicio(2); caractLetraI(2); linCaractInicio(2); linCaractInicio(8); caractLetraT();     caractLetraI(2);
	//Reajusto margen e imprimo linea de guiones bajos
	margen(0,y+3); raya();
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
	//Si 'cantidad'<8 imprime la cantidad de caracteres y el resto de caracteres hasta 8 se completa con espacios
	if(cantidad<8){
		cantidad=8-cantidad;
		for(int j=0; j<cantidad; j++){
			cout << " ";
		}
	}
}
void linCaractFin(int cantidad){
	int c=219;
	//Imprimo separación entre letras
	separacion();
	//Imprime en una misma línea espacios en blanco 8-'cantidad' veces
	for(int j=0; j<(8-cantidad); j++){
		cout << " ";
	}
	//Después de los espacios en blanco se imprimen caracteres rellenados hasta llegas a 8 caracteres
	for(int i=0; i<cantidad; i++){
		cout << (char) c;
	}
}
void caractLetraI(int parte){
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
			//Si 'parte'==1 imprime 2 caracteres rellenados y un espacio después => va a ser el cuerpo de la i
			for(int i=0; i<2; i++){
				cout << (char) c;
			}
			cout << " ";
		}else if(parte==2){
			//Si 'parte'==1 imprime 3 caracteres rellenados => va a ser parte de abajo de la i
			for(int i=0; i<3; i++){
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
			for(int j=0; j<4; j++){
				cout << " ";
			}
		}else{
			//Paredes
			cout << (char) c;
		}
	}
}
void caractLetraT(){
	int c=219;
	//Imprimo separacion entre variables
	separacion();
	//Imprime tres espacios, 2 caracteres de relleno y tres espacios
	for(int i=0; i<7; i++){
		if(i==3){
			for(int j=0; j<2; j++){
				cout << (char) c;
			}
		}else{
			cout << " ";
		}
	}
}
void margen(SHORT x,SHORT y){
	//Coloca el cursor en la posición de la pantalla que se le indique mediante x e y
	COORD par={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), par);
}

void piedra(short x,short y){
	char c='&';
	//hace el dibujo de algo que hace las veces de piedra
	//Imprime 2 espacios, 3 caracteres de relleno y 1 espacio
	margen(x,y); for(int i=0; i<2; i++){ cout << " "; } for(int i=0; i<3; i++){ cout << c; } for(int i=0; i<1; i++){ cout << " "; } y++;
	//Imprime dos líneas de con 6 caractes de relleno en cada una
	for(int j=0; j<2; j++){	
		margen(x,y); for(int i=0; i<6; i++){ margen(x+i,y); cout << c; } y++; }
	//Imprime 1 espacio, 3 caracteres de relleno y 2 espacios 
	margen(x,y); for(int i=0; i<1; i++){ cout << " "; } for(int i=0; i<3; i++){ cout << c; } for(int i=0; i<2; i++){ cout << " "; }
	//margen(x,y); cout << " "; for(int i=0; i<3; i++){ cout << c; } cout << "  ";
}
void papel(short x,short y){
	char c1='_';
	char c2='/';
	//Dibuje algo que hace las veces de papel
	//Imprime en una misma linea 4 espacios y cuatro guiones bajos
	margen(x,y); for(int i=0; i<4; i++){cout << " ";} for(int i=0; i<4; i++){ cout << c1; } y++;
	//Imprime en una misma linea 3 espacios, una barra, 3 espacios y una barra
	margen(x,y); for(int i=0; i<3; i++){cout << " ";} cout << c2; for(int i=0; i<3; i++){cout << " ";} cout << c2; y++;
	//Imprime en una misma linea 2 espacios, una barra, 3 espacios y una barra
	margen(x,y); for(int i=0; i<2; i++){cout << " ";} cout << c2; for(int i=0; i<3; i++){cout << " ";} cout << c2; y++;
	//Imprime en una misma linea 1 espacios, una barra, 3 espacios y una barra
	margen(x,y); for(int i=0; i<1; i++){cout << " ";} cout << c2; for(int i=0; i<3; i++){cout << " ";} cout << c2; y++;
	//Imprime en una misma linea 1 barra, 3 guiones bajos y una barra
	margen(x,y); cout << c2; for(int i=0; i<3; i++){ cout << c1; } cout << c2; y++;
}
void tijera(short x,short y){
	char c1='\\';
	char c2='/';
	char c3='O';
	//Hace el dibujo de una tijera
	//Imprime el margen, un espacio, una barra invertida, 2 espacios y una barra.
	margen(x,y); for(int i=0; i<1; i++){cout << " ";} cout << c1; for(int i=0; i<2; i++){ cout << " "; } cout << c2; y++;
	//Imprime el margen, 2 espacios, una barra invertida y una barra
	margen(x,y); for(int i=0; i<2; i++){cout << " ";} cout << c1 << c2; y++;
	//Imprime el margen, 2 espacios, una barra y una barra inverida
	margen(x,y); for(int i=0; i<2; i++){cout << " ";} cout << c2 << c1; y++;
	//Imprime el margen, un espacio, una letra O, 2 espacios y una letra O
	margen(x,y); for(int i=0; i<1; i++){cout << " ";} cout << c3; for(int i=0; i<2; i++){cout << " ";} cout << c3; y++;
}
void elemento(short x, short y,int numElemento){
	//De acuerdo al numero de elemento que se le pase como parámetro es el elemento que muestra (elemento=pidra o papel o tijera)
	margen(x,y); 
	if(numElemento==1){
		cout << "1 -> Piedra -> "; piedra(x+16,y-1);
	}else if(numElemento==2){
		cout << "2 -> Papel -> "; papel(x+14,y-2);
	}else if(numElemento==3){
		cout << "3 -> Tijera -> "; tijera(x+15,y-1);
	}
}
void ronda(short x,short y,int computadora, int usuario){
	int altura=8;
	int anchoTotal; 
	int ancho;
	//De acuerdo a los los valores tomados por los parámetros define un ancho, un ancho total e imprime o un elemento o pares de elementos (elementos=piedra o papel o tijera)
	if(computadora==1 and usuario==3){
		//Piedra y tijera
		anchoTotal=23;
		ancho=12;
		piedra(x+3,y+2);
		tijera(x+ancho+2,y+2);
	}else if(computadora==3 and usuario==1){
		//Tijera y piedra
		anchoTotal=23;
		ancho=12;
		tijera(x+3,y+2);
		piedra(x+ancho+2,y+2);
	}else if(computadora==1 and usuario==0){
		//Gana piedra
		anchoTotal=23;
		ancho=12;
		piedra(x+3,y+2);
	}else if(computadora==0 and usuario==1){
		//Gana piedra
		anchoTotal=23;
		ancho=12;
		piedra(x+ancho+2,y+2);
	}else if(computadora==2 and usuario==3){
		//Papel y tijera
		anchoTotal=27;
		ancho=14;
		papel(x+3,y+1);
		tijera(x+ancho+3,y+2);
	}else if(computadora==3 and usuario==2){
		//Tijera y papel
		anchoTotal=27;
		ancho=14;
		tijera(x+4,y+2);
		papel(x+ancho+2,y+1);
	}else if(computadora==0 and usuario==3){
		//Gana tijera
		anchoTotal=27;
		ancho=14;
		tijera(x+ancho+3,y+2);
	}else if(computadora==3 and usuario==0){
		//Gana tijera
		anchoTotal=27;
		ancho=14;
		tijera(x+4,y+2);
	}else if(computadora==1 and usuario==2){
		//Piedra y papel
		anchoTotal=27;
		ancho=14;
		piedra(x+4,y+2);
		papel(x+ancho+2,y+1);
	}else if(computadora==2 and usuario==1){
		//Papel y piedra
		anchoTotal=27;
		ancho=14;
		papel(x+3,y+1);
		piedra(x+ancho+3,y+2);
	}else if(computadora==0 and usuario==2){
		//Gana papel
		anchoTotal=27;
		ancho=14;
		papel(x+ancho+2,y+1);
	}else if(computadora==2 and usuario==0){
		//Gana papel
		anchoTotal=27;
		ancho=14;
		papel(x+3,y+1);
	}else if(computadora==1 and usuario==1){
		//Piedra y piedra
		anchoTotal=23;
		ancho=12;
		piedra(x+3,y+2);
		piedra(x+ancho+2,y+2);
	}else if(computadora==2 and usuario==2){
		//Papel y papel
		anchoTotal=27;
		ancho=14;
		papel(x+3,y+1);
		papel(x+ancho+2,y+1);	
	}else if(computadora==3 and usuario==3){
		//Tijera y tijera
		anchoTotal=23;
		ancho=12;
		tijera(x+3,y+2);
		tijera(x+ancho+2,y+2);
	}
	margen(x,y); 
	//Realiza un marco al rededor los dibujos de los elementos
	for(int i=0; i<altura; i++){
		//En la primera y última de ocho filas se imprimen guiones hasta alcanzar el ancho total definido antes
		if(i==0 || i==(altura-1)){
			for(int j=0; j<anchoTotal; j++){
				margen(x+j,y+i); cout << '-';
			}
		}
		else{
			//En la primera, en la última y en la ancho-1 de anchoTotal columnas se imprime una barra vertical
			for(int k=0; k<anchoTotal; k++){
				if(k==0 || k==(ancho-1) || k==(anchoTotal-1)){
					margen(x+k,y+i); cout << '|';
				}
			}
		}
	}
}
short resultato(short x, short y, int computadora, int usuario){
	//Borra línea de mensaje de ingreso de número
	x+=6; margen(x,y); for(int i=0; i<60; i++){cout << " ";}
	//Muestra computadora y usuario con el dibujo del elemento elegido por la cada uno de ellos llamando a la función que determina el dibujo 
	x++; margen(x,y); cout << "Computadora: "; elemento(x+13,y,computadora); margen(x+45,y); cout << ";";  margen(x+55,y); cout << "Usuario: "; elemento(x+64,y,usuario);
	//Imprime mensaje con cierto margen
	y+=3; margen(x+1,y); cout << "Resultado de la ronda..."; 
	//Imprime dibujo representativo de la ronda
	y++; x+=13; ronda(x,y,computadora,usuario); margen(x+31,y+3); cout << "-->"; 
	//Imprime en la misma línea del dibujo anterior el dibujo representativo del resultado
	x+=38;
	//Determinación del dibujo representativo de quien ganó
	if(computadora==1 && usuario==3){
		ronda(x,y,1,0);
	}else if(computadora==3 && usuario==1){
		ronda(x,y,0,1);
	}else if(computadora==2 && usuario==3){
		ronda(x,y,0,3);
	}else if(computadora==3 && usuario==2){
		ronda(x,y,3,0);
	}else if(computadora==1 && usuario==2){
		ronda(x,y,0,2);
	}else if(computadora==2 && usuario==1){
		ronda(x,y,2,0);
	}else{
		//Determinación dibujo representativo de empate
		if(computadora==1 && usuario==1){
			ronda(x,y,1,1);
		}else if(computadora==2 && usuario==2){
			ronda(x,y,2,2);
		}else if(computadora==3 && usuario==3){
			ronda(x,y,3,3);
		}
	}
	//Imprime mensaje debajo que especifica qué elemento ganó
	y+=9; x-=20; margen(x,y); cout << "=] "; 
	if((computadora==1 && usuario==3) || (computadora==3 && usuario==1)){
		cout << "Piedra gana a Tijera.";
	}else if((computadora==2 && usuario==3) || (computadora==3 && usuario==2)){
		cout << "Tijera gana a Papel.";
	}else if((computadora==1 && usuario==2) || (computadora==2 && usuario==1)){
		cout << "Papel gana a Piedra.";
	}else if((computadora==1 && usuario==1) || (computadora==2 && usuario==2) || (computadora==3 && usuario==3)){
		cout << "Iguales. Nadie gana.";
	}
	cout << " [=";
	return y;
}
