//------------------------------------------------------------------------------
// tribe.cpp - содержит функции племени
//------------------------------------------------------------------------------

#include <thread>
#include "Tribe.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
Tribe::Tribe(): count{0} {}

//------------------------------------------------------------------------------
// Деструктор контейнера
Tribe::~Tribe() {
    for(int i = 0; i < count; ++i) {
        delete storage[i];
    }
    count = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Tribe::In(ifstream &ifst) {
    this->common_pot.In(ifst);
    while(!ifst.eof()) {
        Savage new_man;
        new_man.In(ifst);
        storage[count] = &new_man;
        ++count;
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Tribe::InRnd() {
    int size = random.getInt(1, 50);
    this->common_pot.InRnd();
    for (int i = 0; i < size; ++i) {
        Savage new_man;
        new_man.InRnd();
        storage[count] = &new_man;
        ++count;
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Tribe::Out(ofstream &ofst) {
    ofst << "В племени " << count << " дикарей:\n";
    for(int i = 0; i < count; i++) {
        ofst << i << ": ";
        storage[i]->Out(ofst);
    }
}

//------------------------------------------------------------------------------
// Начало обеда для всех членов племени
void Tribe::startLunch(ofstream &ofst) {
    std::thread threads[count];
    for (int i = 0; i < count; ++i) {
        threads[i] = std::thread(&Savage::haveLunch, storage[i], ref(common_pot), ref(ofst));
        threads[i].join();
    }
}