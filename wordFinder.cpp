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
void printDictionary(std::vector<std::string> dictionary);
void catchLetters(std::map<char, int>& alphaMap, std::string userLetters);
bool wordSearch(std::map<char, int>& alphaMap, std::string words);
void findWords(std::vector<std::string> dictionary, std::map<char, int> alphaMap, std::string userLetters);

int main (void)
{

//initializations
    int numLetters;
    std::vector<std::string> dictionary;
    std::string userLetters;
    std::map<char, int> alphabetMap;
    fillAlphabetMap(alphabetMap);
	TwoCharDictionary test();

    numLetters = getUserWordSize();

//Call to function to get word list from file
// FUTURE UPDATE: Get words from a class instead of external text file so that the text file is not included in the package
    dictionary = getDictionary(numLetters);
    printDictionary(dictionary);
    std::cout<<"Number of Words: " << dictionary.getSize()+1 << std::endl;
    userLetters=getUserLetters();
    catchLetters(alphabetMap, userLetters);
    std::cout << "Your letters are: " << userLetters << std::endl;
    findWords(dictionary, alphabetMap, userLetters);
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

void printDictionary(std::vector<std::string> dictionary){
    for (int i=0; i<dictionary.size(); i++)                                        // test line
     {                                                                          // test line
         std::cout << dictionary[i] << std::endl;                               // test line
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

void findWords(std::vector<std::string> dictionary, std::map<char, int> alphabetMap, std::string userLetters){
    for(int i=0; i<dictionary.size()-1; ++i){
        bool foundWord;
        foundWord = wordSearch(alphabetMap, dictionary[i]);
        if(foundWord) std::cout << "\t Found: " << dictionary[i] << std::endl;
        fillAlphabetMap(alphabetMap);
        catchLetters(alphabetMap, userLetters);
    }
}
