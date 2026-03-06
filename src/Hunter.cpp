#include "Hunter.hpp"
#include "Room.hpp"
#include "fogpi/io.hpp"
#include "Stats.hpp"
#include "Combat.hpp"
#include "Player.hpp"


Hunter::Hunter(Vec2 pos, const Stats& stats): m_stats(stats)
   
{
    m_character = 'H';
    m_position = pos;
}


Stats& Hunter::GetStats() {
    return m_stats;
}

void Hunter::Update(Player* player, Room* room){
Vec2 direction(0.0f);

Vec2 trypos = m_position + direction;

if(room->GetLocation(trypos) == ' ' || trypos == player->GetPosition()){
    m_position = trypos;
}

if (m_position == player->GetPosition())
    {
        printf("Hunter triggered fight!\n");
        Fight(*player, *this);
        return;
    }

}