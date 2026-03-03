#include "Brawler.hpp"
#include "Room.hpp"
#include "fogpi/io.hpp"
#include "Stats.hpp"

void Brawler::Start(Vec2 _pos, Stats m_stats){
    m_character = 'B';
    m_position = _pos;
    m_stats = Stats(1, 2, 3, 4, 5 ,6 ,7);
    
}

void Brawler::Update(const Vec2& playerPos, Room* room){

Brawler brawler; 

Vec2 direction;
if(playerPos.x > m_position.x) direction.x = 1;
else if(playerPos.y < m_position.x) direction.x = -1;

if (playerPos.y > m_position.y) direction.y = 1;
else if(playerPos.y < m_position.y) direction.y = -1;


}