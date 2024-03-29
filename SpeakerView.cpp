#include <iostream>
#include "SpeakerView.h"
using namespace std;

SpeakerView::SpeakerView(){
    fp = new FileProcesser();
    grid = fp->processFile("input.txt");
}

SpeakerView::SpeakerView(string input_file){
    fp = new FileProcesser();
    grid = fp->processFile(input_file);
}

SpeakerView::~SpeakerView(){
    delete fp;
}


void SpeakerView::goThroughGrid() {
    try{
        sizeOfCols = fp->cols;
        sizeOfRows = fp->rows;

        for (int i = 0; i < sizeOfCols; ++i) {
            ms = new MonoStack<double>(sizeOfRows+1, 'i');
            for (int j = 0; j < sizeOfRows; ++j) { // Iterate over rows first, then columns
                ms->push(grid[j][i]); // Access grid elements as grid[row][column]
            }
            cout << "In column " << i << " there are " << ms->counter << " that can see. Their heights are: ";
            int k;
            for (k = 0; k < ms->counter-1; ++k) {
                cout << ms->canSee[k] << ",";
            }
            cout << ms->canSee[k];
            cout << " inches." << endl;
            delete ms;
        }
    }catch(runtime_error &e){
        cerr << e.what() << endl;
    }
}