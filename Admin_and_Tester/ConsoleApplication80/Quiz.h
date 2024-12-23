#include <iostream>  
#include <string>  
#include "Menu.h"
using namespace std;

class Quiz {
private:
    static const int NUM_QUESTIONS = 6; 
    struct Question {
        string text;               
        char correctAnswer;       
        string options[3];         
    };

    Question questions[NUM_QUESTIONS];
    int correctCount;                  
    int incorrectCount;               

public:

    Quiz();
    void start();
    void showScore() const;
    void resetCounts();
    int getCorrectCount() const { return correctCount; }
    int getIncorrectCount() const { return incorrectCount; }
    void displayResults() const;   
};