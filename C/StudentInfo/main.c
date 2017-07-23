#include <stdio.h>
#include <stdlib.h>

struct studentdata
{
  int number;
  char name[12];
  int abc[5];
  float mark;
};

int bubblesort(struct studentdata* s, char sortby);
void swap(struct studentdata* a, struct studentdata* b);

int main()
{
  const int NUM_STUDENTS=34;
  
  int i, error;
  struct studentdata student[NUM_STUDENTS];
  FILE* database;

  if((database = fopen("student.txt", "r"))==NULL) 
  {
    printf("\n  ERROR: Could not open input database file 'students.txt'\n");
    system("pause");
    return 1;
  }
  
  for(i=0; i<NUM_STUDENTS; i++)
  {
    fscanf(database, "%s %d %d %d %d %d %d", student[i].name, &student[i].number, &student[i].abc[0], 
                &student[i].abc[1], &student[i].abc[2], &student[i].abc[3], &student[i].abc[4]);
    student[i].mark = (60.*student[i].abc[0] + 20.*(student[i].abc[1]+student[i].abc[2]) + 10.*(student[i].abc[3]+student[i].abc[4]))/120.;
    printf("Student name: %12s Average mark: %7.1f\n",student[i].name,student[i].mark);
  }
  
  fclose(database);
  
  printf("  Sorting by number . . . \n");
  error=bubblesort(student, 'n');
  if(error) {printf("ERROR: sorting file");system("pause");return 1;}
  error = writefile(student, "bynumber.txt");
  if(error) {printf("ERROR: writing file");system("pause");return 1;}

  printf("  Sorting by mark . . . \n");
  error=bubblesort(student, 'm');
  if(error) {printf("ERROR: sorting file");system("pause");return 1;}
  error = writefile(student, "bymark.txt");
  if(error) {printf("ERROR: writing file");system("pause");return 1;}

  system("pause");
  return 0;
}

int bubblesort(struct studentdata* s, char sortby)
{
  const int NUM_STUDENTS=34;
  int i,j,retcode=0;
  switch(sortby)
  {
    case 'n':
      // sort by number, ascending
      for(i=0; i<NUM_STUDENTS-1; i++)
        for(j=0; j<NUM_STUDENTS-1; j++)
          if(s[j].number > s[j+1].number) swap(&s[j], &s[j+1]);
      break;
    case 'm':
      // sort by mark, descending
      for(i=0; i<NUM_STUDENTS-1; i++)
        for(j=0; j<NUM_STUDENTS-1; j++)
          if(s[j].mark < s[j+1].mark) swap(&s[j], &s[j+1]);
      break;
    default:
      printf("\n  ERROR: Unable to sort - don't know what to sort by!\n");
      retcode=1;
  }
  return retcode;
}

void swap(struct studentdata* a, struct studentdata* b)
{
  struct studentdata temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int writefile(struct studentdata* s, char* fname)
{
  const int NUM_STUDENTS=34;
  int i;
  FILE* f;
  if((f = fopen(fname, "w"))==NULL) {
    printf("\n  ERROR: Could not open output database file '%s'\n", fname);
    return 1;
  }
  for(i=0; i<NUM_STUDENTS; ++i)
    fprintf(f,"%12s %06d %7.1f\n", s[i].name, s[i].number, s[i].mark);
  fclose(f);
  return 0;
}
