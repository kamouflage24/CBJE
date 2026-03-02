#include "Combat.hpp"
#include <iostream>
#include "fogpi/io.hpp"



int RollDie(int sides) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, sides);
    return dist(gen);
}

void Fight(Entity& player, Entity& enemy);


void Fight(Entity& player, Entity& enemy) {
    print("A fight begins!\n");

    while (player.m_health > 0 && enemy.m_health > 0) {
        int pRoll = RollDie();
        int eRoll = RollDie();

        print("Player rolls: " + std::to_string(pRoll) + "\n");
        print("Enemy rolls: " + std::to_string(eRoll) + "\n");

        if (pRoll > eRoll) {
            enemy.m_health -= 2;
            print("You hit the enemy! Enemy HP: " + std::to_string(enemy.m_health) + "\n");
        }
        else if (eRoll > pRoll) {
            player.m_health -= 2;
            print("Enemy hits you! Your HP: " + std::to_string(player.m_health) + "\n");
        }
        else {
            print("Both attacks miss!\n");
        }

        request_char("Press Enter to continue...");
    }

    if (player.m_health <= 0) {
        print("You were defeated!\n");
    } else {
        print("Enemy defeated!\n");
    }
}

bool CheckCollision(const Entity& a, const Entity& b) {
    return a.GetPosition() == b.GetPosition();
}
