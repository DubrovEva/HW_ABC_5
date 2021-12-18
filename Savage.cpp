//------------------------------------------------------------------------------
// Savage.cpp - содержит реализацию
//------------------------------------------------------------------------------

#include "Savage.h"

#include <chrono>
#include <thread>
#include <iostream>

//------------------------------------------------------------------------------
// Ввод характеристик дикаря
void Savage::In(ifstream &ifst) {
    ifst >> age_ >> height_ >> weight_ >> name_;
    frequency_ = height_ / age_ / weight_;
}

// Случайный ввод характестик
void Savage::InRnd() {
    age_ = random_.getInt(15, 100);
    height_ = random_.getInt(150, 200);
    weight_ = random_.getInt(45, 150);
    name_ = random_.getInt(1, 1000);
    frequency_ = height_ * age_ * weight_ % 100;
}

//------------------------------------------------------------------------------
// Вывод характеристик дикаря
void Savage::Out(ofstream &ofst) {
    ofst << "Дикарь по имени " << name_ << ", рост - " << height_
         << ", вес - " << weight_ << ", возраст - " << age_ << "\n";
}

//------------------------------------------------------------------------------
// Дикарь отправляется на обед
void Savage::haveLunch(Pot &common_pot, ofstream & ofst) {
    while (!common_pot.isEmpty()) {
        common_pot.decreasePortion();
        std::cout << "Дикарь взял порцию. \n";
        std::this_thread::sleep_for(std::chrono::milliseconds(frequency_));
    }
}

int Savage::getName() {
    return name_;
}