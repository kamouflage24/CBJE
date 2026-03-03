#include "Player.hpp"
#include "Room.hpp"
#include "Combat.hpp"
#include "Brawler.hpp"
#include "Stats.hpp"
#include "fogpi/io.hpp"

Stats playerStats(1,0,8,5,3,2,1);
Player player({5,5}, playerStats);
void Player::SetBrawler(Brawler* b){
    m_brawler = b;
}
Player::Player(Vec2 _pos, const Stats& stats) : m_stats(stats) {
    m_character = 'P';
    m_position = _pos;
}


void Player::Update()
 {
    //while(request_char("hit w to continue: ") != 'w') {}

    char directionInput;

    do {
        directionInput = request_char("wasd and Enter to move");
    } while (directionInput != 'w' &&
             directionInput != 'a' &&
             directionInput != 's' &&
             directionInput != 'd');
    
    Vec2 direction(0.0f);

    switch (directionInput)
    {
    case 'w':
        direction = {0.0f, -1.0f};
        break;
    case 'a':
        direction = {-1.0f, 0.0f};
        break;
    case 's':
        direction = {0.0f, 1.0f};
        break;
    case 'd':
        direction = {1.0f, 0.0f};
        break;
    default:
        direction = {0.0f, 1.0f};
        break;
    }


    Vec2 tryPos = m_position + direction;

    if (room->GetLocation(tryPos) == 'B') {
        return;
    }

    if (room->GetLocation(tryPos) == 'K') {
        m_keyCount++;
        room->ClearLocation(tryPos);
    }

    if (room->GetLocation(tryPos) == ' ') {
        m_position = tryPos;
    }

    if (room->GetLocation(tryPos) == 'D') {
        room->OpenDoor(tryPos);
    }

    bool CheckCollision(const Entity& a, const Entity& b);
    void Fight(Player& player, Entity& b);
    
    if (m_brawler && CheckCollision(*this, *m_brawler)) {
        Fight(*this, *m_brawler);
}
    }

    void Player::Heal(int hp){
        return m_stats.heal(hp);

    }