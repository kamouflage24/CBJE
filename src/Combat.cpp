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
    printf("A fight begins!\n");

    while (player.m_health > 0 && enemy.m_health > 0) {
        int pRoll = RollDie();
        int eRoll = RollDie();

        printf(("Player rolls: %d\n"),pRoll);
        printf(("Enemy rolls: %d\n"),eRoll);

        if (pRoll > eRoll) {
            enemy.m_health -= 2;
            printf("You hit the enemy! Enemy HP: %d\n", enemy.m_health);
        }
        else if (eRoll > pRoll) {
            player.m_health -= 2;
            printf("Enemy hits you! Your HP: %d\n", player.m_health);
        }
        else {
            printf("Both attacks miss!\n");
        }

        request_char("Press Enter to continue...");
    }

    if (player.m_health <= 0) {
        printf("You were defeated!\n");
    } else {
        printf("Enemy defeated!\n");
    }
}

bool CheckCollision(const Entity& a, const Entity& b) {
    return a.GetPosition() == b.GetPosition();
}
