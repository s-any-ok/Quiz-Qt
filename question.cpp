#include "question.h"
Question::Question(int id, int correctAnswer, string question, vector<string> answers)
{
    this->id = id;
    this->correctAnswer = correctAnswer;
    this->question = question;
    this->answers = answers;
}

Question::~Question()
{
}

string Question::getAnswerById(int id)
{
    return this->answers[id];
}
int Question::getCorrectAnswerId()
{
    return this->correctAnswer;
}
string Question::getQuestion()
{
    return this->question;
}
