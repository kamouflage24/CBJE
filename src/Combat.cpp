#include "Combat.hpp"
#include <iostream>
#include "fogpi/io.hpp"
#include "Stats.hpp"
#include "Player.hpp"
#include "Brawler.hpp"



int RollDie(int sides) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, sides);
    return dist(gen);
}




void Fight(Entity& player, Entity& brawler) {
    Stats playerStats;
    Stats brawlerStats; 
    
    printf("A fight begins!\n");

    while (player.m_health > 0 && b.m_health > 0) {
        int pRoll = RollDie(6);
        int eRoll = RollDie(6);

        printf(("Player rolls: %d\n"),pRoll);
        printf(("Enemy rolls: %d\n"),eRoll);

        if (pRoll > eRoll) {
            b.m_health -= 2;
            printf("You hit the enemy! Enemy HP: %d\n", b.m_health);
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
        printf("You have %d hp remaining.\n", player.m_health);
        printf("%d", playerStats);
    }
}

bool CheckCollision(const Entity& a, const Entity& b) {
    return a.GetPosition() == b.GetPosition();
}
