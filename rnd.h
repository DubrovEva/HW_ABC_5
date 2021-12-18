#ifndef __rnd__
#define __rnd__

#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime> // для функции time()
//------------------------------------------------------------------------------
// rnd.h - содержит генератор случайных чисел в заданном диапазоне
//------------------------------------------------------------------------------

class Random {
public:
    Random() {
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
    }
    // Генерация случайного числа в заданном диапазоне
    int getInt(int left, int right) {
        return rand() % (right - left) + left;
    }

    std::string getString() {
        std::string str;
        str.push_back(rand() % (122 - 97) + 97);
        str.push_back(rand() % (122 - 97) + 97);
        str.push_back(rand() % (122 - 97) + 97);
        return str;
    }
};

#endif //__rnd__
