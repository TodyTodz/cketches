#include<iostream>
#include <windows.h>
#include <conio.h>
#include <unistd.h>
using namespace std;



const int w=56,a=52,s=54,d=50, fight=53, i=20;
char mass[i][i], grnt='*', bot='^', buf=' ';
int x=i/2, y=i-2;

//void instruction(){
//}
//
//void hello(){
//}




void start(){
//	hello();
//	instruction();
	
	int j;
	for(j=0;j<i;j++){
		
	mass[j][i-1]='|';
	mass[j][0]='|';	
	mass[i-1][j]='-';
	mass[0][j]='-';	
	}
}


void field(){
	int k, j;
	
	mass[10][10]=bot;
	
	for(j=0;j<i;j++){
		for(k=0;k<i;k++){
			cout<<mass[j][k];
		} 
		cout<<endl;
	}
}

void fig(int m){
	COORD position = {x,y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, position);
	mass[y-m][x]=buf;
	if(mass[y-m-1][x]!=bot)buf=mass[y-m-1][x];
	if(mass[y-m-1][x]!='-')mass[y-m-1][x]=grnt;
}


void change(char l){
	int j;
	switch((int)l){
		case w: --y; break;
		case a: --x; break;
		case s: ++x; break;
		case d: ++y; break;
		case fight: for(j=0;j<=y-2;j++){
			fig(j);sleep(1);system("cls"); field();
		} 	mass[y-j-1][x]==' ';break;
	}
	
	
}

void move(){

COORD position = {x,y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, position);

while(true){
	char l=getch();
	change(l);
	position = {x,y};
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);		
}
}




int main(){
	int m=0;
	setlocale(LC_ALL, "rus");

	start();
	field();
	move();


}
