#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "gameinitializer.h"
#include "gamedatawriter.h"

class GameManager
{
public:
    explicit GameManager(GameInitializer, GameDataWriter);
    explicit GameManager();
    ~GameManager();
    GameInitializer getGameInitializer();
    GameDataWriter getGameDataWriter();
private:
    GameInitializer gameInitializer;
    GameDataWriter gameDataWriter;
};

#endif // GAMEMANAGER_H
