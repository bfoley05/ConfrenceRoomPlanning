#include "SpeakerView.h"
using namespace std;

int main(int argc, char **argv){

    SpeakerView *calc = new SpeakerView(argv[1]);
    calc->goThroughGrid();

    delete calc;
    return 0;
}