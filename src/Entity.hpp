#pragma once

#include "fogpi/Math.hpp"
#include "Stats.hpp"



class Room;

class Entity {
    public:
        Room* room;

        virtual void Start(Vec2 _pos) {}
        virtual void Update() {}

        Vec2 GetPosition() { return m_position; };
        char Draw() { return m_character;
         }
        virtual Stats& GetStats() = 0;  
        virtual ~Entity() = default;

        Vec2 m_position;
    char m_character;
    int m_health = 10;   

    Entity() : m_position(0,0), m_character('?'), m_health(10) {}

    Vec2 GetPosition() const { return m_position; }
    void SetPosition(const Vec2& pos) { m_position = pos; }

    protected:
        /*Vec2 m_position;
        char m_character;*/
};