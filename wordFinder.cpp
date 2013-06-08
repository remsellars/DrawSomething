#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <limits>
#include "dictionary.h"


#define ALPHABET_LENGTH 26
#define ASCII_OFFSET 97
#define FALSE 0
#define TRUE 1


void fillAlphabetMap(std::map<char, int>& alphaMap);
int getUserWordSize();
std::string getUserLetters();
std::vector<std::string> getDictionary(int n);
void printDictionary(Dictionary* p_Dict);
void catchLetters(std::map<char, int>& alphaMap, std::string userLetters);
bool wordSearch(std::map<char, int>& alphaMap, std::string words);
void findWords(Dictionary* p_Dict, std::map<char, int> alphaMap, std::string userLetters);
Dictionary* dictionaryFactory(int numLetters);

int main (void)
{

//initializations
    int numLetters;
    //std::vector<std::string> dictionary;
    
    std::string userLetters;
    std::map<char, int> alphabetMap;
    fillAlphabetMap(alphabetMap);
    Dictionary* p_Dict;

    numLetters = getUserWordSize();

//Call to function to get word list from file
// FUTURE UPDATE: Get words from a class instead of external text file so that the text file is not included in the package
    //dictionary = getDictionaryTemp(numLetters);
    p_Dict = dictionaryFactory(numLetters);
    p_Dict->fillDictionary();
    printDictionary(p_Dict);
    std::cout<<"Number of Words: " << p_Dict->size()+1 << std::endl;
    userLetters=getUserLetters();
    catchLetters(alphabetMap, userLetters);
    std::cout << "Your letters are: " << userLetters << std::endl;
    findWords(p_Dict, alphabetMap, userLetters);
    delete p_Dict;
    return 0;
}


int getUserWordSize(){
    int numLetters;
    //How many Letters
    std::cout << "How many letters does the word you are trying to guess contain?" << std::endl;
    std::cin >> numLetters;
        while (numLetters<2 || numLetters>8)
        {
             std::cin.clear();
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             std::cout << "Please enter a number between 2 and 8. How many letters? " << std::endl;
             std::cin >> numLetters;
        };
    return numLetters;
}

Dictionary* dictionaryFactory(int numLetters){
	switch(numLetters){
	  case 2:
	    return new TwoCharDictionary();
	    break;
	  case 3:
	     return new ThreeCharDictionary();
	     break;
	  case 4:
	      return new FourCharDictionary();
	      break;
	  case 5:
	      return new FiveCharDictionary();
	      break;
	  case 6:
	    return new SixCharDictionary();
	    break;
	  case 7:
	     return  new SevenCharDictionary();
	     break;
	  case 8:
	    return new EightCharDictionary();
	    break;
	  }
	
}

///////FUNCTION: GET DICTIONARY FROM FILE///////
std::vector<std::string> getDictionary(int n)
{
//initialisations
  std::string filename;
  std::string word;
  std::vector<std::string> dictionary;

//Create filename using n letters
     std::stringstream sstm;
     sstm << "DrawSomething" << n <<"Characters.txt";
     filename = sstm.str();
     std::cout << "File Name: " << filename << std::endl;

//Open file
     std::ifstream infile(filename.c_str());

        if (! infile)
        {
            std::cout << "Error, Could not open file" << std::endl;
        };

//Get words from infile, and save in vector 'dictionary'
    for ( int i=0; !infile.eof(); i++)
    {
            std::getline(infile, word);
            dictionary.push_back(word);
    };

return dictionary;
}

///////FUNCTION: GET USERS LETTERS///////
std::string getUserLetters()
{
 std::string userLetters;

      std::cout << "Please enter your letters:" << std::endl;
      std::getline (std::cin, userLetters);
            while((userLetters.size()!=12)&&(userLetters.size()!=8))
            {
                std::cout << "Please enter either 8 or 12 letters:" << std::endl;
                std::getline (std::cin, userLetters);
            }
return userLetters;
}

///////FUNCTION: CREATES A MAP WITH ALPHA LETTERS AS KEYS AND INTS AS VALUES.
void fillAlphabetMap(std::map<char, int>& alphaMap)
{
    for(int i=0; i<ALPHABET_LENGTH; ++i)
    {
      alphaMap[char(i+ASCII_OFFSET)] = FALSE;
    }
}

void printDictionary(Dictionary* p_Dict){
    for (int i=0; i<p_Dict->size(); i++)                                        // test line
     {                                                                          // test line
         std::cout << p_Dict->getWord(i) << std::endl;                               // test line
     };
}

///////FUNCTION: maps user letters to alpha map. IF ZERO THEN NO CHAR IS PRESENT. IF >0 THEN IS HOW MANY OCCURENCES FOUND
void catchLetters(std::map<char, int>& alphaMap, std::string userLetters)
{
  char character;
  int size = userLetters.size();

    for(int i=0; i<size; ++i)
    {
       character = userLetters[i];
       ++alphaMap[character];
    }
}

bool wordSearch(std::map<char, int>& alphaMap, std::string word)
{
  char character;
  int wordSize = word.size();
    for(int i=0; i<wordSize; ++i)
    {
      character = word.at(i);

          if(alphaMap[character] == 0)
          {
            return 0;
          }
      else
      {
           --alphaMap[character];
      }
    }
    return 1;
}

void findWords(Dictionary* p_Dict, std::map<char, int> alphabetMap, std::string userLetters){
    for(int i=0; i<p_Dict->size()-1; ++i){
        bool foundWord;
        foundWord = wordSearch(alphabetMap, p_Dict->getWord(i));
        if(foundWord) std::cout << "\t Found: " << p_Dict->getWord(i) << std::endl;
        fillAlphabetMap(alphabetMap);
        catchLetters(alphabetMap, userLetters);
    }
}
