#ifndef QUESTION_H
#define QUESTION_H
#include <vector>
#include <string>
#include <QtCore/QObject>
using namespace std;

class Question
{

public:
    explicit Question(int id, int correctAnswer, string question, vector<string> answers);
    explicit Question(string row);
    ~Question();
    string getQuestion();
    string getAnswerById(int);
    int getCorrectAnswerId();
private:
    int id;
    string question;
    int correctAnswer;
    vector<string> answers;
};

#endif // QUESTION_H
