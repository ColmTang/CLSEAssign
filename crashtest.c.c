#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* these arrays are just used to give the parameters to 'insert',
   to create the 'people' array */

/* declare your struct for a person here */

struct players
{
	char name[20];
	char class[10];
	int type; 
    int health;
	int smartness;
	int magic;
	int strength;
	int dexterity;
	int luck;
};

int main(void) 
{									 //main function
//declation of the arrays
		struct players player[6];
  	int n;
  	printf("Enter the # of players\n");
  	scanf("%d", &n);

	while (n>6 || n<2)
	{							 // in case of too many players
    	printf("Error: player numbers invalid. Choose a number between 6 and 2 palyers and try again.\n");
  		scanf("%d", &n);
	}
	int type;
	int i=0;
			//n-1 because i starts at 0 so ends at 5
	while (i != n) //max 6 players and respective type
	{
		printf("Enter player name:\n");
		scanf("%s", &player[i].name);
		
		printf("Enter this player's type:\n1.Human 2.Ogre 3.Elf 4.Wizard\n");
		scanf("%d", &type);
		while (type < 1 || type > 4)
		{
			printf("Enter this player's type:\n1.Human 2.Ogre 3.Elf 4.Wizard\n");
			scanf("%d", &type);
		}	
		player[i].type = type;
		i++;
	}
// *** SECTION B ***
	srand ( time(NULL)); 
	
	for(i=0;i<n;i++)
	{
		if (player[i].type == 1)
		{ 						//human
		strcpy(player[i].class, "Human");
//randomly allocate capabilities while respecting the constraints provided in the line below.
			while ((player[i].dexterity + player[i].magic + player[i].smartness + player[i].strength + player[i].luck) < 300);
			{
			player[i].luck = (rand() %100 +1);
			player[i].smartness = (rand() %100 +1);
			player[i].strength = (rand() %100 +1);
			player[i].dexterity = (rand() %100 +1);
			player[i].magic = (rand() %100 +1);
			player[i].health = 100;
			}
		}
		else if (player[i].type == 2)
		{ 						//ogre
			strcpy(player[i].class, "Ogre");
			player[i].magic = 0;	
			while ((player[i].luck+player[i].smartness) <= 50)
			{
			player[i].smartness = (rand() %21);
			player[i].strength = (rand() %21 +80);
			player[i].dexterity = (rand() %21 +80);
			player[i].luck = (rand() %51);
			player[i].health = 100;
			}
		}
		else if (player[i].type == 3) //elf
		{
			strcpy(player[i].class, "Elf");
			player[i].luck = (rand() %41 +60);
			player[i].smartness = (rand() %31 +70);
			player[i].strength = (rand() %51 +1);
			player[i].dexterity = (rand() %99 +1);
			player[i].magic = (rand() %29 +51);//she said 50 < magic instead of
			player[i].health = 100; 		//50 <= magic
		}
		else if (player[i].type == 4) //wizard
		{
			strcpy(player[i].class, "Wizard");
			player[i].smartness = (rand() %11 +90);
			player[i].dexterity = (rand() %100 +1);
			player[i].strength = (rand() %21);
			player[i].luck = (rand() %51 +50);
			player[i].magic = (rand() %21 +80);	
			player[i].health = 100;
		}
	printf("Player %d;\n",(i+1));
	printf("name: %s\n", player[i].name);
	printf("class: %s\n",player[i].class);
	printf("health: %d\n",player[i].health);
	printf("smartness = %d\n",player[i].smartness);
	printf("magic = %d\n",player[i].magic);
	printf("strength = %d\n",player[i].strength);
	printf("dexterity = %d\n",player[i].dexterity);
	printf("luck = %d\n",player[i].luck);
	}
	printf("Proceeding to slot selection\n");
return 0;
}
