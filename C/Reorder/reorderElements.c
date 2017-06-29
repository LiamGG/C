//130190600

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>


struct element{
       int number, melt, boil, state;
       char string[6], name[2];
       double mass, density, ion;
};

void state(struct element *n);
void list(struct element *s);
void swap(struct element *a, struct element *b);

int main(void){
    FILE *data;
    FILE *states;
    const int num_elements = 92;
    int i;
    struct element n[num_elements];
    char symbol[2];
    
    if ((data = fopen("elements.txt", "r")) == NULL ){
              printf("The file 'elements.txt' could not be accessed.\n");
              system("Pause");
              return 0;
    }
    
    if((states = fopen("state.txt","w")) == NULL){
                 printf("The file state.txt cannot be opened.\n");
                 system("pause");
                 return 0;
    }
    
    for (i=0; i<num_elements; i++){
        fscanf(data, "%d %lf %s %d %d %lf %lf", &n[i].number, &n[i].mass, &n[i].name, &n[i].melt, &n[i].boil, &n[i].density, &n[i].ion);
    }
    
    state(n);    
    list(n);
   
    fprintf(states, "State,   Element,  Atomic Number,  Boiling Point,  Ion\n", n[i].state, n[i].name, n[i].number, n[i].boil, n[i].ion);
    
    for (i=0; i<num_elements; i++){
        fprintf(states, "%-8s %-9s %13.3d %15.5d %7.3lf\n", n[i].state, n[i].name, n[i].number, n[i].boil, n[i].ion);    
    }
   
    fclose(data);
     
    printf("File 'state.txt' created, listing elements from largest to smallest ionization energy, sorted by state at room temperature.\n");
 
    system("Pause");
    return 0;
}



void state(struct element *n){
     const int num_elements = 92;
     int i;
     
     for(i=0; i<92; i++){
            // Gas at 25
            if (n[i].boil<25){
                 n[i].state = "Gas";
            }
            //Liquid at 25   
            else if (n[i].boil>25 && n[i].melt<25){
                 n[i].state = "Liquid";
            }
			//Solid at 25            
            else if (n[i].melt>25){
                 n[i].state = "Solid";
            }
      }    
}

void list(struct element *s){
     const int num_elements = 92;
     int m, n;
     
     for(m=0; m<(num_elements-1); m++){
              for(n=0; n<(num_elements-1); n++){
                       if ((s[n].state>s[n+1].state)){
                       		swap(&s[n], &s[n+1]);
                       }
              }
     }
     
     for(m=0; m<(num_elements-2); m++){
              for(n=0; n<(num_elements-1); n++){
                       if ((s[n].ion<s[n+1].ion) && (s[n].state == s[n+1].state)){
                       		swap(&s[n], &s[n+1]);
                       }
              }
     }
}


void swap(struct element *a, struct element *b){
     struct element temp;
     temp=*a;
     *a=*b;
     *b=temp;
     return;
}
     
