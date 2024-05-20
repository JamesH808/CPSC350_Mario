#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include "World.h"
#include <fstream>





using namespace std;

class FileProcessor {

  public:
    FileProcessor();  // constructor
    ~FileProcessor(); // destructor

    static const int array_Size = 8; //given size of input file 
    int specArray[array_Size];
    int count;

    void processInputFile(string inFile, string outFile); // process file
    

  private:
  World world;

};
#endif