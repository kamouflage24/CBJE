#include "Hunter.hpp"
#include "Room.hpp"
#include "fogpi/io.hpp"
#include "Stats.hpp"



void Hunter::Start(Vec2 _pos, Stats m_stats){
    m_character = 'H';
    m_position = _pos;
    m_stats = Stats(1 ,2, 5, 2, 2, 8, 5, 4);
}

void Hunter::Update(const Vec2& playerPos, Room* room){

Vec2 direction;
if(playerPos.x > m_position.x) direction.x = 1;
else if(playerPos.y < m_position.x) direction.x = -1;

if (playerPos.y > m_position.y) direction.y = 1;
else if(playerPos.y < m_position.y) direction.y = -1;

Vec2 tryPos = m_position + direction;

if(room ->GetLocation(tryPos) == ' '){
    
}
}