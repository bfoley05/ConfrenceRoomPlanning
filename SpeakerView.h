#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include <iostream>
#include <fstream>
#include "FileProcessor.h"
#include "MonoStack.h"
using namespace std;

class SpeakerView{
    public:
        SpeakerView();
        SpeakerView(string input_file);
        ~SpeakerView();
        void goThroughGrid();

    
    private:
        FileProcesser *fp;
        MonoStack<double> *ms;
        double** grid;
        int sizeOfCols;
        int sizeOfRows;
};



#endif