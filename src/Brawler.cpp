#include "Brawler.hpp"
#include "Room.hpp"
#include "fogpi/io.hpp"
#include "Stats.hpp"
#include "Combat.hpp"
#include "Player.hpp"


Brawler::Brawler(Vec2 pos, const Stats& stats): m_stats(stats)
   
{
    m_character = 'B';
    m_position = pos;
}


Stats& Brawler::GetStats() {
    return m_stats;
}

void Brawler::Update(Player* player, Room* room){

    if (m_position == player->GetPosition())
    {
        printf("BRAWLER triggered fight!\n");
        Fight(*player, *this);
        return;
    }

Vec2 direction;
if(player->GetPosition().x > m_position.x) direction.x = 1;
else if(player->GetPosition().x < m_position.x) direction.x = -1;

if (player->GetPosition().y > m_position.y) direction.y = 1;
else if(player->GetPosition().y < m_position.y) direction.y = -1;


}