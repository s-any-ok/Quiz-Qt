#ifndef GAMEINITIALIZER_H
#define GAMEINITIALIZER_H
#include "question.h"
#include "datamanager.h"
#include <vector>
using namespace std;


class GameInitializer
{
public:
    explicit GameInitializer(DataManager);
    explicit GameInitializer();
    ~GameInitializer();
    void setDataManager(DataManager);
    vector<Question> initQuestions();
private:
    DataManager datamanager;
};

#endif // GAMEINITIALIZER_H
