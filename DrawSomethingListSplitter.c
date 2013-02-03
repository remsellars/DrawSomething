#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
  char word[20];
  int length;
  int i;
  
    FILE *words_in;
     if ((words_in=fopen("DrawSomethingFormattedList.txt","r")) == NULL)
    {
      printf("Error: input file cannot be opened \n");
      system("pause");
      return 1;
   } 

  FILE *words_out2;
      words_out2=fopen("words_numChar2.txt","w");    
  FILE *words_out3;
      words_out3=fopen("words_numChar3.txt","w"); 
  FILE *words_out4;
      words_out4=fopen("words_numChar4.txt","w"); 
  FILE *words_out5;
      words_out5=fopen("words_numChar5.txt","w"); 
  FILE *words_out6;
       words_out6=fopen("words_numChar6.txt","w");
  FILE *words_out7;
      words_out7=fopen("words_numChar7.txt","w"); 
  FILE *words_out8;
      words_out8=fopen("words_numChar8.txt","w"); 

      
      
   while(fscanf(words_in, "%s", &word )>0)
   { 
     length=(strlen(word));    
   
            if (length ==2)
      {
          fprintf(words_out2,"%s\n",word); 
      };   
           if (length ==3)
      {
          fprintf(words_out3,"%s\n",word);  
      };
      
            if (length ==4)
      {
          fprintf(words_out4,"%s\n",word);  
      };
            
            if (length ==5)
      {
          fprintf(words_out5,"%s\n",word);  
      };
      
            if (length ==6)
      {
          fprintf(words_out6,"%s\n",word);  
      };
      
            if (length ==7)
      {
          fprintf(words_out7,"%s\n",word);  
      };     
       
        if (length ==8)
      {
          fprintf(words_out8,"%s\n",word);  
      };
      
              if (length<2 || length>8)
      {
          printf("%s\n",word);  
      };
      
  };
   
   
    fclose(words_in); 
    fclose(words_out2);
    fclose(words_out3);
    fclose(words_out4);
    fclose(words_out5);
    fclose(words_out6);
    fclose(words_out7);
    fclose(words_out8);
    
    system ("pause");
    return 0;
}
