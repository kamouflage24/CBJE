#include "Room.hpp"

#include "Player.hpp"
#include "Brawler.hpp"
#include "Hunter.hpp"
#include "Manticore.hpp"
#include "Combat.hpp"
#include "Entity.hpp"
#include <fstream>
#include <string>
bool m_CheckCollision(const Entity& a, const Entity& b){
    return a.GetPosition().x == b.GetPosition().x && a.GetPosition().y == b.GetPosition().y;
}
void Room::Load(std::string _path)
{
    m_map.clear();
    m_doors.clear();
    if(m_brawler){
        delete m_brawler;
        m_brawler = nullptr;
    }
    if(m_hunter){
        delete m_hunter;
        m_hunter = nullptr;
    }

    std::ifstream file;
    file.open(_path);

    if (!file.is_open())
    {
        printf("file not found at: %s \n", _path.c_str());
        exit(1);
    }

    std::string word;
    int number;

    while (file >> word)
    {
        if (word == "level")
        {
            if (file >> number)
            {
                printf("open level: %i\n", number);
            }
        }

        if (word == "next_level")
        {
            if (file >> word)
            {
                m_doors.push_back(Door());
                m_doors[m_doors.size() - 1].path = word;
            }
        }

        if (word == "map")
        {
            m_map.push_back(std::vector<char>());
            while(file >> word)
            {
                if (word == "-2")
                {
                    break;
                }

                if (word == "-1")
                {
                    m_map.push_back(std::vector<char>());
                    continue;
                }

                if (word == "0")
                    m_map[m_map.size() - 1].push_back(' ');
                else
                    m_map[m_map.size() - 1].push_back(word[0]);
                
            }
        }
    }
   
   

    int doorCount = 0;
    for (int y = 0; y < m_map.size(); y++)
    {
        for (int x = 0; x < m_map[y].size(); x++)
        {
                char tile = m_map[y][x];
            
            if (m_map[y][x] == 'S')
            {
                if (m_player == nullptr){ 
                    Stats playerStats(1,0,8,5,3,2,5,5);
                    m_player = new Player(Vec2(x,y), playerStats);
                    }
                else{
                    m_player->SetPosition(Vec2(x,y));
                }
                
                m_map[y][x] = ' ';
            }

            if (m_map[y][x] == 'B')
            {
                Stats enemyStats(1,0,6,4,2,2,1,2);
                m_brawler = new Brawler(Vec2(x,y), enemyStats);

                if (m_player)
                    m_player->SetBrawler(m_brawler);

                m_map[y][x] = ' ';
            }

            if (m_map[y][x] == 'H')
            {
                Stats enemyStats(1,0,6,4,2,2,1,2);
                m_hunter = new Hunter(Vec2(x,y), enemyStats);

                if (m_player)
                    m_player->SetHunter(m_hunter);

                m_map[y][x] = ' ';
                }

            if (m_map[y][x] == 'M')
            {
                Stats enemyStats(10,7,11,5,7,6,4,10);
                 m_manticore = new Manticore(Vec2(x,y), enemyStats);

                if (m_player)
                    m_player->SetManticore(m_manticore);

                m_map[y][x] = ' ';
            }
    
            if (m_map[y][x] == 'T')
            {
                int chance = rand() % 100;

                if (chance < 50) // 50% chance
                {
                    printf("You found a health potion!\n");
                    HealPlayer(5);
                }
                else if (chance < 80) // 30% chance
                {
                    printf("You found a gold coin!\n");
                    m_player->GetStats().addExperience(10);
                }
                else // 20% chance
                { 
                    printf("The chest was empty.\n");
                }
            }
            if (m_map[y][x] == 'D' || m_map[y][x] == 'L')
            {
                if (m_doors.size() - 1 >= doorCount)
                {
                    m_doors[doorCount].pos.x = x;
                    m_doors[doorCount].pos.y = y;
                    doorCount++;
                }
            }

            if (tile == ' ')
            {
                int chance = rand() % 100;

                if (chance < 5) // 5% chance
                {
                    m_map[y][x] = 'T';
                    continue;
                }
            }

        }
    }

}
void Room::Enemies(){
    if(m_brawler == nullptr && m_hunter == nullptr)
    {
        UnlockedDoor();
    }
}

void Room::Update()
{
   if (m_player)
    {
        m_player->room = this;
        m_player->Update();
    }
    if(m_brawler){
        m_brawler->Update(m_player,this);

        if(m_brawler->GetStats().Ded()){
            printf("Brawler defeated!\n");

            m_player->GetStats().getGold();
            delete m_brawler;
            m_brawler = nullptr;
            if(m_player){
                m_player->SetBrawler(nullptr);
                
            }
            Enemies();
            return;
        }
    }
    if(m_hunter){
        m_hunter->Update(m_player,this);

        if(m_hunter->GetStats().Ded()){
            printf("Hunter defeated!\n");

            m_player->GetStats().getGold();
           
            delete m_hunter;
            m_hunter = nullptr;
            if(m_player){
                m_player->SetHunter(nullptr);
                
                
            }
            Enemies();
            
            return;
            
        }
    }
    if(m_player && m_brawler){
        if (CheckCollision(*m_player, *m_brawler)){
            Fight(*m_player, *m_brawler);
        }
    }
    if(m_player && m_hunter){
        if (CheckCollision(*m_player, *m_hunter)){
            Fight(*m_player, *m_hunter);
        }
    }

    if(m_player && m_manticore){
        if (CheckCollision(*m_player, *m_manticore)){
            Fight(*m_player, *m_manticore);
        }
    }

     if(m_player && m_manticore){
        m_manticore->Update(m_player,this);

        if(m_manticore->GetStats().Ded()){
            printf("Manticore defeated!\n");

            m_player->GetStats().getGold();
            delete m_manticore;
            m_manticore = nullptr;
        }
    }

    //if(m_player->GetStats().getCurrentHealth(0)){
    //     exit(1)
    // }
    // if(m_brawler->GetStats().getCurrentHealth(0)){
    //     delete m_brawler;

    Draw();
}

void Room::Draw()
{
    for (int y = 0; y < m_map.size(); y++)
    {
        for (int x = 0; x < m_map[y].size(); x++)
        {
            printf("%c ", GetLocation(Vec2(x, y)));
        }
        printf("\n");
    }
}

char Room::GetLocation(Vec2 _pos)
{
    if (_pos.y < 0 || _pos.y >= m_map.size())
        return ' ';
    
    if (_pos.x >= m_map[_pos.y].size())
        return ' ';

    if (m_player != nullptr)
        if (m_player->GetPosition() == _pos)
            return m_player->Draw();
    

    if (m_brawler != nullptr)
        if (m_brawler->GetPosition() == _pos)
            return m_brawler->Draw();
            //hunter is invisible; Trust its a feature
    // if (m_hunter != nullptr)
    //     if (m_hunter->GetPosition() == _pos)
    //         return m_hunter->Draw();

    if (m_manticore != nullptr)
        if (m_manticore->GetPosition() == _pos)
            return m_manticore->Draw();
    return m_map[_pos.y][_pos.x];
}

void Room::ClearLocation(Vec2 _pos)
{
    if (_pos.y >= m_map.size())
        return;
    
    if (_pos.x >= m_map[_pos.y].size())
        return;
    
    m_map[_pos.y][_pos.x] = ' ';
}

void Room::OpenDoor(Vec2 _pos)
{
    for(int i = 0; i < m_doors.size(); i++){
   
        if (m_doors[i].pos == _pos)
            { 
            if(m_player){
                HealPlayer(3); 
            } 
        Load(m_doors[i].path.c_str());
        }
    }
}
void Room::UnlockedDoor(){
    for(int y = 0; y < m_map.size(); y++){
        for(int x = 0; x < m_map[y].size(); x++){
            if(m_map[y][x] == 'L'){
                m_map[y][x] = 'D';
            }
        }
    }
}
void Room::HealPlayer(int hp){
    
        if(m_player)
    {
        Stats& stats = m_player->GetStats();
        if(stats.getCurrentHealth() < stats.getHealth() ){
        m_player -> Heal(hp);
        printf("you have recovered %d hp\n", hp);
        printf("current hp: %d\n", stats.getCurrentHealth());
        }
        else{
        printf("you are fearless entering the next room\n");
        }
    }
   
}

