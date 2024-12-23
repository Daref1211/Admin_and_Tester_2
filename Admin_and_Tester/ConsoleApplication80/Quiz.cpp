#include "Quiz.h"  
#include <iostream>  

Quiz::Quiz() : correctCount(0), incorrectCount(0) {
    questions[0] = {
        "Что является основным законом государства?",
        'A',
        { "A) Конституция", "B) Указ президента", "C) Международный договор" }
    };

    questions[1] = {
        "Как называется форма правления, при которой власть сосредоточена у одного человека?",
        'C',
        { "A) Демократия", "B) Республика", "C) Монархия" }
    };

    questions[2] = {
        "Как называется основной денежный доход граждан?",
        'B',
        { "A) Рента", "B) Зарплата", "C) Налог" }
    };

    questions[3] = {
        "Кто является автором труда 'Капитал'?",
        'A',
        { "A) Карл Маркс", "B) Адам Смит", "C) Владимир Ленин" }
    };

    questions[4] = {
        "Как называется совокупность норм, регулирующих общественные отношения?",
        'C',
        { "A) Политика", "B) Культура", "C) Право" }
    };

    questions[5] = {
        "Что регулирует поведение людей в обществе?",
        'B',
        { "A) Экономика", "B) Мораль", "C) Искусство" }
    };
} 
void Quiz::resetCounts() {
    correctCount = 0;
    incorrectCount = 0;
} 
void Quiz::start() {
    resetCounts();
    char userAnswer;

    cout << "Добро пожаловать на викторину по обществознанию!" << endl;
    cout << "Всего 6 вопросов. Ответьте, выбрав правильный вариант (A, B, C)." << endl;

    for (int i = 0; i < 6; ++i) {
        const Question& q = questions[i];

        // Отображаем вопрос и варианты ответа  
        cout << "\nВопрос " << i + 1 << ": " << q.text << endl;
        for (int j = 0; j < 3; ++j) {
            cout << q.options[j] << endl;
        }

        // Получаем ответ пользователя  
        cout << "Ваш ответ: ";
        cin >> userAnswer;
        userAnswer = toupper(userAnswer); // Приводим к верхнему регистру на случай ввода строчной буквы  

        if (userAnswer == q.correctAnswer) {
            cout << "Правильно!" << endl;
            ++correctCount;
        }
        else {
            cout << "Неправильно. Правильный ответ: " << q.correctAnswer << endl;
            ++incorrectCount;
        }
    }

    displayResults();
}
void Quiz::displayResults() const {
    if (incorrectCount <= 5) {
        cout << "Ваши результаты хорошие" << endl;
    }
    else if (correctCount >= 2) {
        cout << "Ваши результаты плачевные" << endl;
    } 
    cout << endl << endl<< "Спасибо за участие!" << endl;
}

void Quiz::showScore() const { 
    cout << "Текущий итог:" << endl;
    cout << "Правильных ответов: " << correctCount << ", Неправильных ответов: " << incorrectCount << endl;
}