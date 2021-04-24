#include "gamedatawriter.h"

GameDataWriter::GameDataWriter()
{
}

void GameDataWriter::setDataManager(DatabaseManager dataManager)
{
    this->datamanager = dataManager;
}

GameDataWriter::GameDataWriter(DatabaseManager dataManager)
{
    this->datamanager = dataManager;
}

GameDataWriter::~GameDataWriter()
{}

void GameDataWriter::setResult(string result){
    this->datamanager.setData(this->resultsFileName, result);
}
