#pragma once

#include <vector>
#include "Door.hpp"
#include "Brawler.hpp"
#include "Hunter.hpp"
#include "Manticore.hpp"


class Entity;
class Player;
class Monster;

class Room {
public:
    void Load(std::string _path);
    void Enemies();
    void Draw();
    void Update();
    char GetLocation(Vec2 _pos);
    void ClearLocation(Vec2 _pos);
    void OpenDoor(Vec2 _pos);
    void UnlockedDoor();
    void HealPlayer(int hp);
private:
    std::vector<Entity*> m_entities;
    Player* m_player = nullptr;
    std::vector<Monster*> m_monsters;
    Brawler* m_brawler = nullptr;
    Hunter* m_hunter = nullptr;
    Manticore* m_manticore = nullptr;
    std::vector<std::vector<char>> m_map;
    std::vector<Door> m_doors;
};