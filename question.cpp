#include "question.h"
Question::Question(int id, int correctAnswer, string question, vector<string> answers)
{
    this->id = id;
    this->correctAnswer = correctAnswer;
    this->question = question;
    this->answers = answers;
}

Question::Question(string row)
{
    this->id = stoi(row.substr(row.find("--(id)--") + 8, row.find("--(correct answer)--") - row.find("--(id)--") - 8));
    this->correctAnswer = stoi(row.substr(row.find("--(correct answer)--") + 20, row.find("--(question)--") - row.find("--(correct answer)--") - 20));
    this->question = row.substr(row.find("--(question)--") + 14, row.find("--(answer 1)--") - row.find("--(question)--") - 14);
    vector<string>* x = new vector<string>();
    string answer;
    for (int i = 1; i < 5; i++)
    {
        answer = row.substr(row.find("--(answer " + to_string(i) + ")--") + 14, row.find("--(answer " + to_string(i + 1) + ")--") - row.find("--(answer " + to_string(i) + ")--") - 14);
        x->push_back(answer);
    }

    this->answers = *x;
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
