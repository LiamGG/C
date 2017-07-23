#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct team{
       char Name[11];
       int Played, Won, Drawn, Lost, GoalsFor, GoalsAgainst, Points;
};


void initstruct(struct team *t);
int footystats(struct team *t);
void printleague(struct team *t);
void leaguetable(struct team *t);
void teamswap(struct team *a, struct team *b);


int main(void){
   const int NTEAMS=20;
   struct team t[NTEAMS];
   initstruct(t); // t is a pointer to the start of the array of structures
   if (footystats(t)) return 0;
   printf("Premier League listed Alphabetically\n");
   printleague(t);   
   leaguetable(t);
   printf("\nPremier League Sorted by points\n");
   printleague(t);
   system("pause");
   return 0;
}


void initstruct(struct team *t){
  const int NTEAMS=20;
  int n=0;
  for (n=0; n<NTEAMS; n++){
    t[n].Played=0;
    t[n].Won=0;
    t[n].Drawn=0;
    t[n].Lost=0;
    t[n].GoalsFor=0;
    t[n].GoalsAgainst=0;
    t[n].Points=0;
  }
  strcpy(t[0].Name,"Aston Villa");
  strcpy(t[1].Name,"Arsenal");
  strcpy(t[2].Name,"Blackburn");
  strcpy(t[3].Name,"Bolton");
  strcpy(t[4].Name,"Chelsea");
  strcpy(t[5].Name,"Everton");
  strcpy(t[6].Name,"Fulham");
  strcpy(t[7].Name,"Liverpool");
  strcpy(t[8].Name,"Man City");
  strcpy(t[9].Name,"Man Utd");
  strcpy(t[10].Name,"Newcastle");
  strcpy(t[11].Name,"Norwich");
  strcpy(t[12].Name,"QPR");
  strcpy(t[13].Name,"Stoke");
  strcpy(t[14].Name,"Sunderland");
  strcpy(t[15].Name,"Swansea");
  strcpy(t[16].Name,"Tottenham");
  strcpy(t[17].Name,"West Brom");
  strcpy(t[18].Name,"Wigan");
  strcpy(t[19].Name,"Wolves");
  return;
}


int footystats(struct team *t){
    FILE *stats;
    int home_num=0, away_num=0, goals_home=0, goals_away=0;
    char victor;
    
    if ((stats = fopen("data.txt", "r")) == NULL){
               printf("The file cannot be opened.\n");
               system("pause");
               return 0;
    }
     
     while (fscanf(stats, "%*s %d %d %d %d %c", &home_num, &away_num, &goals_home, &goals_away, &victor) >0){
      //Change games played    
          t[home_num].Played++;
          t[away_num].Played++;
      //Change Goals For    
          t[home_num].GoalsFor+=goals_home;
          t[away_num].GoalsFor+=goals_away;
      //Change Goals Against
          t[home_num].GoalsAgainst+=goals_away;
          t[away_num].GoalsAgainst+=goals_home;
      //Change games won/drawn/lost and points
          switch(victor){
            case 'H':
          	          (t[home_num].Won)++;
                          (t[home_num].Points)+=3;
                          (t[away_num].Lost)++;
                          break;
            case 'D':
                          (t[home_num].Drawn)++;
                          (t[away_num].Drawn)++;
                          (t[home_num].Points)++;
                          (t[away_num].Points)++;
                          break;
            case 'A':
            	          (t[away_num].Won)++;
                          (t[away_num].Points)+=3;
                          (t[home_num].Lost)++;
                          break;
          }
     }
     fclose(stats);
     return 0;
}
                          
void printleague(struct team *t){
     int i;
     printf("        Team  PL   W   D   L  GF  GA PTS\n");
     for (i=0; i<=19; i++)
     {
         printf("%12s  %2d  %2d  %2d  %2d  %2d  %2d  %2d\n", t[i].Name, t[i].Played, t[i].Won, t[i].Drawn, t[i].Lost, t[i].GoalsFor, t[i].GoalsAgainst, t[i].Points);
     }
}
     
void leaguetable(struct team *t){
	int m, n;
	for (m=0; m<18; m++){
		for (n=0; n<19; n++){
			if (t[n].Points<t[n+1].Points || (t[n].Points==t[n+1].Points && (t[n].GoalsFor-t[n].GoalsAgainst)<(t[n+1].GoalsFor-t[n+1].GoalsAgainst))){
			teamswap (&t[n], &t[n+1]);
			}
		}
	}
}
     
void teamswap(struct team *a, struct team *b){
  struct team temp;
  temp=*a;
  *a=*b;
  *b=temp;
  return;
}
