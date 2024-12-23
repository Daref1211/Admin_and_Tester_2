#include "Quiz.h"  
#include <iostream>  

Quiz::Quiz() : correctCount(0), incorrectCount(0) {
    questions[0] = {
        "��� �������� �������� ������� �����������?",
        'A',
        { "A) �����������", "B) ���� ����������", "C) ������������� �������" }
    };

    questions[1] = {
        "��� ���������� ����� ���������, ��� ������� ������ ������������� � ������ ��������?",
        'C',
        { "A) ����������", "B) ����������", "C) ��������" }
    };

    questions[2] = {
        "��� ���������� �������� �������� ����� �������?",
        'B',
        { "A) �����", "B) ��������", "C) �����" }
    };

    questions[3] = {
        "��� �������� ������� ����� '�������'?",
        'A',
        { "A) ���� �����", "B) ���� ����", "C) �������� �����" }
    };

    questions[4] = {
        "��� ���������� ������������ ����, ������������ ������������ ���������?",
        'C',
        { "A) ��������", "B) ��������", "C) �����" }
    };

    questions[5] = {
        "��� ���������� ��������� ����� � ��������?",
        'B',
        { "A) ���������", "B) ������", "C) ���������" }
    };
} 
void Quiz::resetCounts() {
    correctCount = 0;
    incorrectCount = 0;
} 
void Quiz::start() {
    resetCounts();
    char userAnswer;

    cout << "����� ���������� �� ��������� �� ��������������!" << endl;
    cout << "����� 6 ��������. ��������, ������ ���������� ������� (A, B, C)." << endl;

    for (int i = 0; i < 6; ++i) {
        const Question& q = questions[i];

        // ���������� ������ � �������� ������  
        cout << "\n������ " << i + 1 << ": " << q.text << endl;
        for (int j = 0; j < 3; ++j) {
            cout << q.options[j] << endl;
        }

        // �������� ����� ������������  
        cout << "��� �����: ";
        cin >> userAnswer;
        userAnswer = toupper(userAnswer); // �������� � �������� �������� �� ������ ����� �������� �����  

        if (userAnswer == q.correctAnswer) {
            cout << "���������!" << endl;
            ++correctCount;
        }
        else {
            cout << "�����������. ���������� �����: " << q.correctAnswer << endl;
            ++incorrectCount;
        }
    }

    displayResults();
}
void Quiz::displayResults() const {
    if (incorrectCount <= 5) {
        cout << "���� ���������� �������" << endl;
    }
    else if (correctCount >= 2) {
        cout << "���� ���������� ���������" << endl;
    } 
    cout << endl << endl<< "������� �� �������!" << endl;
}

void Quiz::showScore() const { 
    cout << "������� ����:" << endl;
    cout << "���������� �������: " << correctCount << ", ������������ �������: " << incorrectCount << endl;
}