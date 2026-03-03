#pragma once

#include "Entity.hpp"
#include "Brawler.hpp"
#include "Stats.hpp"

class Player : public Entity
{
public:
    void Start(Vec2 _pos, Stats m_stats);
    void SetBrawler(Brawler* b);
    void Update();
private:
    Brawler* m_brawler = nullptr;
    int m_keyCount = 0;
    
};