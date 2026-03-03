#include "Brawler.hpp"
#include "Room.hpp"
#include "fogpi/io.hpp"
#include "Stats.hpp"


Brawler::Brawler(Vec2 pos, const Stats& stats): m_stats(stats)
   
{
    m_character = 'B';
    m_position = pos;
}


Stats& Brawler::GetStats() {
    return m_stats;
}

void Brawler::Update(const Vec2& playerPos, Room* room){


Vec2 direction;
if(playerPos.x > m_position.x) direction.x = 1;
else if(playerPos.x < m_position.x) direction.x = -1;

if (playerPos.y > m_position.y) direction.y = 1;
else if(playerPos.y < m_position.y) direction.y = -1;


}