#include "Combat.hpp"
#include <iostream>
#include "fogpi/io.hpp"
#include "Stats.hpp"
#include "Player.hpp"
#include "Brawler.hpp"
#include "Hunter.hpp"
#include "Entity.hpp"
#include <random>




int RollDie(int sides) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, sides);
    return dist(gen);
}




void Fight(Entity& player, Entity& b) {
    printf("A fight begins!\n");

    while (player.GetStats().getCurrentHealth() > 0 && 
            b.GetStats().getCurrentHealth() > 0) {
        int pRoll = RollDie(6);
        int eRoll = RollDie(6);

        printf("Player rolls: %d\n", pRoll);
        printf("Enemy rolls: %d\n", eRoll);

        if (pRoll > eRoll) {
            int damage = player.GetStats().getStrength() - 
            b.GetStats().getDefence();
            if(damage < 1)
            damage = 1;
            b.GetStats().takeDamage(damage);

            printf("You hit the enemy! Enemy HP: %d\n",
                   b.GetStats().getCurrentHealth());
        }
        else if (eRoll > pRoll) {
            
            int damage = b.GetStats().getStrength() - 
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
        printf("Gold lost: %d\n", player.GetStats().getGold());
        exit(1);
    } else {
        printf("Enemy defeated!\n");
        printf("You have %d hp remaining.\n", player.GetStats().getCurrentHealth());
        printf("Your current stats:\n");
        printf("HP: %d\n", player.GetStats().getCurrentHealth());
        printf("Strength: %d\n", player.GetStats().getStrength());
        printf("Defence: %d\n", player.GetStats().getDefence());
        printf("Speed: %d\n", player.GetStats().getSpeed());
        printf("Luck: %d\n", player.GetStats().getLuck());

        player.GetStats().addExperience(10);
        player.GetStats().levelUp(20);
    }

    

}

bool CheckCollision(const Entity& a, const Entity& b) {
    return a.GetPosition() == b.GetPosition();
}
