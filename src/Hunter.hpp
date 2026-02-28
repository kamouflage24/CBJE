#pragma once

#include "Entity.hpp"

class Hunter : public Entity{
public:
    void Start(Vec2 _pos);
    void Update(const Vec2& playerPos, Room* room);
private:
    int m_keyCount = 0;
};