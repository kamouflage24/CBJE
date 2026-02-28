#pragma once

#include "fogpi/Math.hpp"

class Stats{

    private:
    int level;
    int experience;
    int health;
    int strength;
    int defence;
    int speed;
    int luck;
    
    public:
    Stats(int lvl, int exp, int h, int str, int def, int spd, int chan) : level(lvl), experience(exp), health(h), strength(str), defence(def), speed(spd), luck(chan){

    }
};