#pragma once

#include "Entity.hpp"
#include "Brawler.hpp"
#include "Stats.hpp"


class Player : public Entity
{
public:
    Player(Vec2 _pos, const Stats& stats);
    void SetBrawler(Brawler* b);
    void Heal(int hp);
    void Update();
    bool Ded() const;
private:
    Brawler* m_brawler = nullptr;
    Stats m_stats;
    int m_keyCount = 0;
    
};