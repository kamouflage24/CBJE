#pragma once

#include "Entity.hpp"
#include "Stats.hpp"


class Brawler : public Entity{
    public:
        Brawler(Vec2 pos, const Stats& stats);
        void Update(const Vec2& playerPos, Room* room);
        bool Ded() const;
        Stats& GetStats() override;
    private:
        int m_keyCount = 0;
        Stats m_stats;
        
};
