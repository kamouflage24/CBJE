#pragma once

#include "Entity.hpp"
#include "Stats.hpp"

class Player;
class Room;

class Hunter : public Entity{
    public:
        Hunter(Vec2 pos, const Stats& stats);
        void Update(Player* player, Room* room);
        bool Ded() const;
        Stats& GetStats() override;
    private:
        int m_keyCount = 0;
        Stats m_stats;
        
};
