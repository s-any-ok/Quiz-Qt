#include "gamemanager.h"

GameManager::GameManager(GameInitializer gameInitializer, GameDataWriter gameDataWriter)
{
    DataManager dataManager;
    this->gameInitializer = gameInitializer;
    this->gameDataWriter = gameDataWriter;

    this->gameInitializer.setDataManager(dataManager);
    this->gameDataWriter.setDataManager(dataManager);
}

GameManager::GameManager()
{}

GameManager::~GameManager()
{}


GameDataWriter GameManager::getGameDataWriter()
{
    return this->gameDataWriter;
}

GameInitializer GameManager::getGameInitializer()
{
    return this->gameInitializer;
}
