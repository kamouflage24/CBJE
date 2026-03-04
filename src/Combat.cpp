#include "Combat.hpp"
#include <iostream>
#include "fogpi/io.hpp"
#include "Stats.hpp"
#include "Player.hpp"
#include "Brawler.hpp"
#include "Entity.hpp"
#include <random>




int RollDie(int sides) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, sides);
    return dist(gen);
}




void Fight(Entity& player, Entity& brawler) {
    
    printf("A fight begins!\n");

    while (player.GetStats().getCurrentHealth() > 0 && 
            brawler.GetStats().getCurrentHealth() > 0) {
        int pRoll = RollDie(6);
        int eRoll = RollDie(6);

        printf("Player rolls: %d\n", pRoll);
        printf("Enemy rolls: %d\n", eRoll);

        if (pRoll > eRoll) {
            int damage = player.GetStats().getStrength() - 
            brawler.GetStats().getDefence();
            if(damage < 1)
            damage = 1;
            brawler.GetStats().takeDamage(damage);

            printf("You hit the enemy! Enemy HP: %d\n",
                   brawler.GetStats().getCurrentHealth());
        }
        else if (eRoll > pRoll) {
            
            int damage = brawler.GetStats().getStrength() - 
            player.GetStats().getDefence();
            if(damage < 1)
            damage = 1;
            player.GetStats().takeDamage(damage);

            printf("Enemy hits you! Your HP: %d\n",
                   player.GetStats().getCurrentHealth());
        }
        else {
            printf("Both attacks miss!\n");
        }

        request_char("Press Enter to continue...");
    }

    if (player.GetStats().getCurrentHealth() <= 0) {
        printf("You were defeated!\n");
        exit(1);
    } else {
        printf("Enemy defeated!\n");
        printf("You have %d hp remaining.\n", player.GetStats().getCurrentHealth());
    }

    player.GetStats().addExperience(10);
        player.GetStats().levelUp(20);

    if (brawler.GetStats().getCurrentHealth() <= 0) {
    printf("Enemy defeated!\n");
    printf("You have %d hp remaining.\n", player.GetStats().getCurrentHealth());
    }

}

bool CheckCollision(const Entity& a, const Entity& b) {
    return a.GetPosition() == b.GetPosition();
}
