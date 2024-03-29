#ifndef FILE_PROCESSER
#define FILE_PROCESSER

#include <iostream>
#include <fstream>
using namespace std;

class FileProcesser{
    public:
        FileProcesser();
        ~FileProcesser();
        double** processFile(string file_in);
        int rows;
        int cols;

    
    private:
        string file_output;
        ofstream ofs;
};



#endif