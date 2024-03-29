#include "FileProcessor.h"
#include <iostream>
#include <fstream>

FileProcesser::FileProcesser() {

}

FileProcesser::~FileProcesser(){

}


// opens both files and checks if it is found, if so reads each line of the file
// and returns the contents in array format to be used
double** FileProcesser::processFile(string input_file) {
    ifstream ifs(input_file);

    if (!ifs) {
        cerr << "No file found" << endl;
        return nullptr;
    }

    // Determine the number of rows and columns in the file
    rows = 0;
    cols = 0;
    string line;
    while (getline(ifs, line)) {
        int tempCols = 0;
        size_t pos = 0;
        while ((pos = line.find(' ', pos)) != string::npos) {
            pos++;
            tempCols++;
        }
        tempCols++; // Count the last number on the line
        if (tempCols > cols) {
            cols = tempCols;
        }
        rows++;
    }

    // Reset file stream to beginning
    ifs.clear();
    ifs.seekg(0, ios::beg);

    // Create the 2D array
    double** arr = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new double[cols];
    }

    // Read data from file and populate the array
    int row = 0;
    while (getline(ifs, line)) {
        int col = 0;
        size_t pos = 0;
        while ((pos = line.find(' ', pos)) != string::npos) {
            string numStr = line.substr(0, pos);
            arr[row][col] = stod(numStr); // Convert string to double
            line.erase(0, pos + 1);
            pos = 0;
            col++;
        }
        arr[row][col] = stod(line); // Convert string to double for the last number on the line
        row++;
    }

    // for(int i = 0; i < rows; ++i){
    //     for(int j = 0; j < cols; ++j){
    //         cout << arr[i][j] << "  ";
    //     }
    //     cout << endl;
    // }

    // Close the file
    ifs.close();

    return arr;
}