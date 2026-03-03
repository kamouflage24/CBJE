#pragma once

#include "Entity.hpp"
#include "Stats.hpp"

class Brawler : public Entity{
    public:
        void Start(Vec2 _pos, Stats m_stats);
        void Update(const Vec2& playerPos, Room* room);
    private:
        int m_keyCount = 0;
        
};