#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getFile (int numOfLetters);
int main (void)
{
    
    int numOfLetters;

        
    printf("How many letters does your word contain? ");
    scanf("%d",&numOfLetters);

     while (numOfLetters<2 || numOfLetters>8)
   {    printf("Please enter a number between 2 and 8. How many letters? ");
        scanf("%d",&numOfLetters);
   };
   
    getFile(numOfLetters);


//char *strchr(const char *word, int letter1)// -- Find first occurrence of character c in string. 

return 0;
}


int getFile(int numOfLetters)
{
	char word[10];
	FILE* words_i;
	char fileName[20];

	sprintf(fileName, "resources/words_numChar%d.txt", numOfLetters);

             if((words_i = fopen(fileName,"r"))==NULL)
             {  printf("Error: input file cannot be opened \n");
                system("pause");
                return 1;
             }
                       while(fscanf(words_i, "%s", &word )>0)
                       {
                            printf("%s\n",word);
                       }
       fclose(words_i);
 
    

  return 0;
}

