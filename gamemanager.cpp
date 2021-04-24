#include "gamemanager.h"
#include "databasemanager.h"

GameManager::GameManager(GameInitializer gameInitializer, GameDataWriter gameDataWriter)
{
    DatabaseManager dataManager;
    dataManager.setDB("D:/SQLiteDatabaseBrowserPortable/Data/", "database.db");
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
