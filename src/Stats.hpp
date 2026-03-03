#pragma once

#include "fogpi/Math.hpp"

class Stats{

    private:
    int level;
    int experience;
    int health;
    int current_health;
    int strength;
    int defence;
    int speed;
    int luck;
    
    public:
    Stats(int lvl, int exp, int h, int str, int def, int spd, int chan) : level(lvl), experience(exp), health(h), current_health(h), strength(str), defence(def), speed(spd), luck(chan){

    
    }
    int getLevel() const{ return level; }
    int getExperience() const{ return experience; }
    int getHealth() const{ return health; }
    int getCurrentHealth() const{ return current_health; }
    int getStrength() const{ return strength; }
    int getDefence() const{ return defence; }
    int getSpeed() const{ return speed; }
    int getLuck() const{return luck; }
    
    void addExperience(int XP) { experience += XP; }

    void takeDamage(int dmg){
        health -= dmg;
        health == current_health;      
    }

    void heal(int hp){
        current_health += hp;
        if(current_health > health){
            current_health = health;
        }
    }

    void levelUp(int XP, int max_xp){
        if (XP = max_xp){
            level + 1;
            health + 2;
            current_health + 0;
            strength + 1;
            defence + 2;
            speed + 3;
            luck + 1;
        }
    }

};