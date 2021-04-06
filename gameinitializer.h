#ifndef GAMEINITIALIZER_H
#define GAMEINITIALIZER_H
#include "question.h"
#include <vector>
using namespace std;


class GameInitializer
{
public:
    explicit GameInitializer();
    ~GameInitializer();
    vector<Question> initQuestions();
};

#endif // GAMEINITIALIZER_H
