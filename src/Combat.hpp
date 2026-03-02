#pragma once
#include "Player.hpp"
#include <random>

void OnPlayerCollideWithEnemy(Player& player, Player& enemy);

int RollDie(int sides = 6);