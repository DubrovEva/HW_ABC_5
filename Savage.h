#ifndef __Savage__
#define __Savage__

//------------------------------------------------------------------------------
// Savage.h - содержит описание дикаря
//------------------------------------------------------------------------------

#include <fstream>
#include <string>
using namespace std;

#include "rnd.h"
#include "Pot.h"

//------------------------------------------------------------------------------
// Дикарь
class Savage {
private:
    // Базовые характеристики
    int age_, height_, weight_, name_;
    // Характеризует как часто дикарь хочет есть (в милисекундах)
    int frequency_;
    Random random_;
public:
    // Ввод характеристик дикаря
    void In(ifstream &ifst);
    // Случайный ввод характеристик дикаря
    void InRnd();
    // Вывод характеристик в форматируемый поток
    void Out(ofstream &ofst);
    // Обед
    void haveLunch(Pot & common_pot, ofstream & ofst);
    // Получить имя дикаря
    int getName();
};

#endif //__Savage__
