#ifndef __Pot__
#define __Pot__

//------------------------------------------------------------------------------
// Pot.h - содержит описание горшка с едой
//------------------------------------------------------------------------------

#include <fstream>
#include <mutex>
#include "rnd.h"
using namespace std;

// Горшок с едой
class Pot {
private:
    int portions_count_;
    Random random;
    mutex m;

public:
    // Ввод параметров горшка с едой из файла
    void In(ifstream &ifst);
    // Случайный ввод параметров горшка с едой
    void InRnd();
    // Вывод параметров горшка с едой в форматируемый поток
    void Out(ofstream &ofst);
    // Уменьшить количество порций
    void decreasePortion();
    // Есть ли порции
    bool isEmpty();
};

#endif //__Pot__
