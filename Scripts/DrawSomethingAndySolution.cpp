#include <iostream>
#include <map>
#include <algorithm>
#include <time.h>

#define ALPHABET_LENGTH 26
#define ASCII_OFFSET 97
  
  void fillWithLetters(char* characterArray, int size){
    int letter;
    for(int i=0; i<size; ++i){
      letter = rand()%ALPHABET_LENGTH+1;
      letter += ASCII_OFFSET;
      characterArray[i] = char(letter);
    }    
  }
  
  void fillTestWordTrue(char* word, int wordSize, char* userLetters, int userLetters_Size){
    for(int i=0; i<wordSize; i++){
      int randIndex = rand()%userLetters_Size;
      word[i] = userLetters[randIndex];
    }
  }
      
  void printLetters(char* characterArray, int size){
    for(int i=0; i<size; ++i){
      std::cout<<characterArray[i];
    }
    std::cout<<"\n";
  }
  
  void fillAlphabetMap(std::map<char, int>& alphaMap){
    for(int i=0; i<ALPHABET_LENGTH; ++i){
      alphaMap[char(i+ASCII_OFFSET)] = 0;
    }
  }
  
  void catchLetters(std::map<char, int>& alphaMap, char* characterArray, int size){
    char character;
    for(int i=0; i<size; ++i){
    character = characterArray[i];
    ++alphaMap[character];
    }
  }

  int wordSearch(std::map<char, int> alphaMap, char* word, int wordSize){
    char character;
    for(int i=0; i<wordSize; ++i){
      character = word[i];
      if(alphaMap[character] == 0){
       return 0;
      }
      else{
           --alphaMap[character];
      }
    }
    return 1;
  }
int main() {
  std::map<char, int> alphabetMap;
  int numLetters = 12;
  char userLetters[numLetters];
  
  int wordSize = 8;
  int numWords = 4;
  // An array of characters. In others words: a string.
  char testWord1[wordSize];
  char testWord2[wordSize];
  char testWord3[wordSize];
  char testWord4[wordSize];
  char testWord5[wordSize]; 
  char testWord6[wordSize];
  char testWord7[wordSize];
  char testWord8[wordSize];

  //An array of strings. ...a sentance?
  char* pToWords[numWords];
  pToWords[0] = testWord1;
  pToWords[1] = testWord2;
  pToWords[2] = testWord3;
  pToWords[3] = testWord4;
  pToWords[4] = testWord5;
  pToWords[5] = testWord6;
  pToWords[6] = testWord7;
  pToWords[7] = testWord8;

  srand (time(NULL) );
  // -------------------- fill arrays
  printf("Enter given letters: ");
  scanf("%s", userLetters);  
  // -------------------- fill the alphabet map with characters
  fillAlphabetMap(alphabetMap);
  
  // --------------------- catch letters will switch the letters found in userLetters to 'true'
  catchLetters(alphabetMap, userLetters, numLetters);

       FILE* words8;
             if((words8 = fopen("DrawSomething8Characters.txt","r"))==NULL)
             {  printf("Error: input file cannot be opened \n");
                system("pause");
                return 1;
             }
int i=0;
                       while(fscanf(words8, "%s", &testWord1 )>0)
                       {
                       ++i; 
                       printf("Word number %d is %s\n", i, testWord1);
  
      // for all words
     // checkWord
    // if checkWord == true then print
 
 for(int i=0; i<numWords; ++i){
     if(wordSearch(alphabetMap, pToWords[i], wordSize)){
      std::cout<< "Found: ";
      printLetters(pToWords[i], wordSize); 
      fillAlphabetMap(alphabetMap);
      catchLetters(alphabetMap, userLetters, numLetters);
     }
     else{
      std::cout<< "Not found: ";
      printLetters(pToWords[i], wordSize); 
     }
   }
    
      

/*  fillWithLetters(testWord1, wordSize);
    // will be a 'word' that can be made using the users letters
  fillTestWordTrue(testWord2, wordSize,userLetters, numLetters);
  fillWithLetters(testWord3, wordSize);
  fillTestWordTrue(testWord4, wordSize,userLetters, numLetters);
*/  
  // ------------------ print user letters and the words that will be matched
 
  std::cout<< "User letters are: ";
  printLetters(userLetters, numLetters);
   for(int i=0;i<numWords; ++i){
   std::cout<<"Word "<<i<<" is: ";
   printLetters(pToWords[i], wordSize); 
  }
   }
 fclose(words8);
system("pause");
  return 0;
}

