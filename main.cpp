//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------
#include <iostream>
#include <cstring>

#include "Tribe.h"

void errMessage1() {
    cout << "incorrect command line!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

void errMessage2() {
    cout << "incorrect qualifier value!\n"
            "  Waited:\n"
            "     command -f infile outfile01 outfile02\n"
            "  Or:\n"
            "     command -n number outfile01 outfile02\n";
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
//    if(argc != 5) {
//        errMessage1();
//        return 1;
//    }

    ofstream ofst(argv[3]);
    cout << "Племя собирается на обед.."<< endl;
    Tribe vyshkints;
    vyshkints.InRnd();

//    if (strcmp(argv[1], "-f") && strcmp(argv[1], "-n")) {
//        errMessage2();
//        return 2;
//    }
//    if (!strcmp(argv[1], "-f")) {
//        ifstream ifst(argv[2]);
//        vyshkints.In(ifst);
//    } else {
//        vyshkints.InRnd();
//    }

    vyshkints.startLunch(ofst);
    cout << "Еда кончилась :("<< endl;
    
    return 0;
}