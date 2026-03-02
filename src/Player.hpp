#pragma once

#include "Entity.hpp"
#include "Brawler.hpp"

class Player : public Entity
{
public:
    void Start(Vec2 _pos);
    void SetBrawler(Brawler* b);
    void Update();
private:
    Brawler* m_brawler = nullptr;
    int m_keyCount = 0;
};