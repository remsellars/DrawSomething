#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
  char word[20];
  int length;
  int i;
  
    FILE *words_in;
     if ((words_in=fopen("DrawSomethingWordListOriginal.txt","r")) == NULL)
    {
      printf("Error: input file cannot be opened \n");
      system("pause");
      return 1;
   } 
   
  FILE *words_out;
      words_out=fopen("DrawSomethingFormattedList.txt","w"); 
  
  
  
      while(fscanf(words_in, "%s", &word )>0)
   { length=(strlen(word)-4);    
  
      for(i=0;i<length;i++)
    {
      fprintf(words_out,"%c",word[i] );  
     }
     fprintf(words_out,"\n");
  };
   
    fclose(words_in); 
    fclose(words_out);
    
    system ("pause");
    return 0;
}
