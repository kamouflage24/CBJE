#pragma once
#include "Player.hpp"
#include "Entity.hpp"
#include <random>

void OnPlayerCollideWithEnemy(Player& player, Entity& entity);
void Fight(Entity& player, Entity& entity);
bool CheckCollision(const Entity& a, const Entity& b);


int RollDie(int sides = 6);