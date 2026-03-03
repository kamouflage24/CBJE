#include "Player.hpp"
#include "Room.hpp"
#include "Combat.hpp"
#include "Brawler.hpp"
#include "Stats.hpp"
#include "fogpi/io.hpp"

//Stats playerStats(1,0,8,5,3,2,1);
//Player player({5,5}, playerStats);
void Player::SetBrawler(Brawler* b){
    m_brawler = b;
}
Player::Player(Vec2 _pos, const Stats& stats) : m_stats(stats) {
    m_character = 'P';
    m_position = _pos;
}

Stats& Player::GetStats() {
    return m_stats;
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

    
    if (m_brawler && CheckCollision(*this, *m_brawler)) {
        Fight(*this, *m_brawler);
} 
    if(m_stats.Ded()){
        printf("Back to the lobby with thee!!!");
        exit(0);
    }
}

    void Player::Heal(int hp){
        m_stats.heal(hp);

    }

    bool Player::Ded() const{
        return m_stats.Ded();
    }
   