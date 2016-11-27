/*ADT GUI*/
#include "ADTgui.h"
//#include "scene.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<windows.h>

//#define clear() printf("\033[2J")
//#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

#ifdef _WIN32

    #include <windows.h>
    void ClearScreen()
    {
        system("cls");
    }



#elif __linux__
    #include <unistd.h>
    void ClearScreen()
    {
        system("clear");
    }

#endif

void delay(int x)
{
   int c = 1, d = 1;

   for ( c = 1 ; c <= x*10 ; c++ )
       for ( d = 1 ; d <= x*10 ; d++ )
       {}


}

void Back()
{
	char x;
	do{
		scanf(" %c",&x);
		if(x!='B'){
			printf("Ketik 'B' untuk kembali ke menu utama\n");
		}
	}while(x!='B');
}
void printMainMenu()
/*I.S. sembarang
  F.S. menampilkan main menu pada saat program dijalankan
*/
{

	ClearScreen();
	//printf("%c==================================================================%c\n",201,187);
	printf("****                                                            ****\n");	
	printf("****                                                            ****\n");
	printf("****           ___             |   |                   |        ****\n");
	printf("****          |   \\            |   |    __             | __     ****\n");
	printf("****          |   /   __ o  __ |_--|-- /  \\  __        |/  \\    ****\n");
	printf("****          |---  |/   | /  ||  \\|   \\__  /  \\ |    ||\\__     ****\n");
	printf("****        A |   \\ |    ||   ||  ||      \\|    ||    ||   \\    ****\n");
	printf("****       <[>|___/ |    | \\__||  |\\__/\\__/ \\__/  \\__/ |\\__/    ****\n");
	printf("****        [             \\___|                                 ****\n");
	printf("****  /\\    [****\\\\\\\\\\*************************>>               ****\n");
	printf("**** <*******[000000000000***********************>>             ****\n");
	printf("****  \\/    [****/////*************************>>               ****\n");
	printf("****        [                                                   ****\n");
	printf("****       <[>                                                  ****\n");
	printf("****        V                                                   ****\n");
	printf("****                      (N)NEW GAME                           ****\n");
	printf("****                                                            ****\n");
	printf("****                      (S)START GAME                         ****\n");
	printf("****                                                            ****\n");
	printf("****                      (L)LOAD GAME                          ****\n");
	printf("****                                                            ****\n");
	printf("****                      (H)? HELP ?                           ****\n");
	printf("****                                                            ****\n");
	printf("****                      (E)EXIT                               ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("                           INPUT : ");
	//	printf("%c==================================================================%c\n",200,188);

	//pilihOpsi(a);

}

void pilihOpsi(char a[],int *b,int *s)
{
	char x;

	do{
		scanf(" %c",&x);
		switch (x){
			case 'N' : NewGame(a); break;
			case 'S' : printStartGame(a,s); break;
			case 'L' : loadingBar(); break;//buat sementara blm ada
			case 'H' : printHelp(); break;//buat sementara blm ada
			case 'E' : printExit(b); break;
			default : printf("Invalid input!\n");
		}

	}while(((x!='N')&&(x!='S')&&(x!='L')&&(x!='H')&&(x!='E'))&&(b!=0));

}

void NewGame(char a[])
/*I.S. sembarang
  F.S. menampilkan kotak pengisian nama pemain pada saat pilihan menu New Game dipilih
*/
{

	printf("                INSERT YOUR NAME : ");
	scanf("%s",a);

	printf("Tekan 'B' untuk kembali ke menu utama");
	Back();
	/*printf("                                                                      \n"
		   "                                                                      \n"
		   "                                                                      \n"
		   "                                                                      \n"
		   "                                                                      \n"
		   "                                                                      \n"
		   "                                                                      \n"
		   "                                                                      \n"
		   "                                                                      \n"
		   "                                                                      \n"
		   "                                                                      \n"
		   "                          INSERT YOUR NAME                            \n"
		   "                                                                      \n"
		   "                        ");
	*/
		   /*13*29*/

}
void printStartGame(char a[],int *s)
/*I.S. sembarang
  F.S. menampilkan cerita awal jika pemain sudah memasukkan nama pemain,
  jika belum ada nama pemain, tampilkan "nama pemain belum dimasukkan!" dan kembali ke
  tampilan main menu
*/
{

	if(strlen(a)==0){
		printf("> Pemain belum ada! Input nama terlebih dahulu dengan memilih menu New Game(N)!\n");
		printf("> (B)Back\n");
		Back();
	}else{
		printf("Selamat bermain %s!\n",a);
		*s = 1;
        //Overworld();
	}

}
void loadingBar()
/*I.S. sembarang
  F.S. menampilkan loading bar sebelum main menu
  tidak penting, HANYA OPTIONAL!!
*/
{
	ClearScreen();
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  LOADING\n");
	for(int i=1;i<=10;i++){
		printf(">");
		fflush(stdout);
		usleep(500000);
	}
	for(int i=1;i<=20;i++){
		printf(">");
		fflush(stdout);
		usleep(200000);
	}
	for(int i=1;i<=10;i++){
		printf(">");
		fflush(stdout);
		usleep(300000);
	}
	for(int i=1;i<=10;i++){
		printf(">");
		fflush(stdout);
		usleep(150000);
	}
	for(int i=1;i<=10;i++){
		printf(">");
		fflush(stdout);
		usleep(100000);
	}
	printf("\n");
}
void printGUIInGame(char nm[], int lvl, int hp, int str, int def, int exp)
/*I.S. sembarang
  F.S. menampilkan tabel dan peta setelah start game
*/
{
	char x;
	ClearScreen();
	/*printf("|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
			|                                                                    |\n
	");*/
	printf(" %s / LVL : %d / HP : %d / STR : %d / DEF : %d / EXP : %d \n",nm,lvl,hp,str,def,exp);
	printf("Command : ");
	scanf(" %c",&x);
	printf("\n");
}
void printExit(int *b)
/*I.S. sembarang
  F.S. menampilkan "are you sure? Yes No" saat menu exit dipilih
*/
{
	char x;
	printf("are you sure? Y/N ");

	do{
		scanf(" %c",&x);
		if(x=='Y'){
			printf("Good bye!\n");
			*b = 0;
		}else if(x=='N'){
			*b = 1;
		}else{
			printf("Invalid input!\n");
		}
	}while((x!='Y')&&(x!='N'));
}

void printHelp()
{

}


void PrintHeader(char * Nama, int HP, int STR, int DEF, int Level, int EXP, int Next ){
    printf(    "\t\t\t\t\t%s\n\n",Nama);
    printf(    "_________________________________________________________________________________________________\n\n");
    printf(    " | HP : %d\t| STR : %d\t| DEF : %d\t| Lv : %d\t| EXP : %d\t| Next : %d\t|\n",HP,STR,DEF,Level,EXP,Next);
    printf(    "_________________________________________________________________________________________________\n\n");
}

void printGameOver(){
	printf("****                                                            ****\n");	
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");	
	printf("****         ___   ___   _  _  ___      __       ___ __               ****\n");
	printf("****        /   \\ /   \\ / \\/ \\|        /  \\ |  ||   |  \\            ****\n");
	printf("****       | ___  |___||  |  ||___    |    ||  ||___|__/             ****\n");
	printf("****       |    | |   ||  |  ||       |    ||  ||   |  \\           ****\n");	
	printf("****        \\___/ |   ||  |  ||___     \\__/  \\/ |___|  |           ****\n");
	printf("****                                                            ****\n");	
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");	
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");	
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
}

void printCredits(){
	printf("****                                                            ****\n");	
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                          CREDITS                           ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                  Vincent Hendryanto Halim                  ****\n");
	printf("****                                                            ****\n");
	printf("****                       Roland Hartanto                      ****\n");	
	printf("****                                                            ****\n");
	printf("****                        Dicky Novanto                       ****\n");
	printf("****                                                            ****\n");
	printf("****                       Alif Ijlal Wafi                      ****\n");
	printf("****                                                            ****\n");	
	printf("****                Daniel Christian Pradipta Baso              ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");	
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");	
	printf("****                                                            ****\n");
	printf("****                                                            ****\n");

}