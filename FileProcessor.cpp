#include <fstream>
#include <iostream>
#include <string>

#include "FileProcessor.h"

FileProcessor::FileProcessor() : count(0) {   //constructor 
  for (int i=0; i < array_Size; ++i) {
    specArray[i] = 0;
  }
}

FileProcessor::~FileProcessor() { //destructor 

}

void FileProcessor::processInputFile(string inFile, string outFile) {
  ifstream in_file(inFile);
  ofstream fileO(outFile);

  int temp;

 

  if (in_file.is_open()) {
    while (count < array_Size && in_file >> temp) {
      specArray[count++] = temp;
    }
      in_file.close();
  } else {
    cerr << "Error opening file" << endl;
  }

  if (!fileO.is_open()){
      cout << "Output file was not opened correctly." << endl;
      return;
  }

  world.makeWorld(specArray);
  world.play();


  in_file.close();
  fileO.close();


}

