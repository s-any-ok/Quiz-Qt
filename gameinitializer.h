#ifndef GAMEINITIALIZER_H
#define GAMEINITIALIZER_H
#include "question.h"
#include "datamanager.h"
#include <vector>
using namespace std;


class GameInitializer
{
public:
    explicit GameInitializer(DatabaseManager);
    explicit GameInitializer();
    ~GameInitializer();
    void setDataManager(DatabaseManager);
    vector<Question> initQuestions();
private:
    DatabaseManager datamanager;
};

#endif // GAMEINITIALIZER_H
