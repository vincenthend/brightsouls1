#include <stdio.h>
#include "boolean.h"
#include "player.h"

typedef struct{
	int hp;
	int exp;
	int str;
	int def;
	boolean boss;
} Enemy;

#define HPE(E) (E).hp
#define EXPE(E) (E).exp
#define STRE(E) (E).str
#define DEFE(E) (E).def
#define Boss(E) (E).boss

#define BaseEHP 80
#define BaseESTR 7
#define BaseEDEF 6
#define BaseEEXP 8


void initEnemy(Enemy * E, int mapcount, boolean boss);
