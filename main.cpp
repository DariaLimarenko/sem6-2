#include <iostream>
#include <clocale>
#include <string>

#include "PendingQueue.h"
#include "Student.h"
#include "Teacher.h"
#include "School.h"

using namespace std;

void printMessage(const string& message) {
    cout << "[Сообщение]: " << message << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    PendingQueue queue;

    Teacher teacher("Иванова Мария Петровна", 40, "Математика");
    Student student("Петров Иван", 15, 101);
    School school("Средняя школа №1");

    cout << "--- Добавляем задачи в очередь ---" << endl;

    queue.enqueue(printMessage, string("Начало выполнения задач"));

    queue.enqueue(printMessage, string("Назначаем классного руководителя"));
    queue.enqueue(&Student::setClassTeacher, &student, &teacher);

    queue.enqueue(printMessage, string("Добавляем оценки ученику"));
    queue.enqueue(&Student::addGrade, &student, 5);
    queue.enqueue(&Student::addGrade, &student, 4);

    queue.enqueue(printMessage, string("Выводим дневник ученика"));
    queue.enqueue(&Student::showDiary, &student);

    queue.enqueue(printMessage, string("Выводим информацию об учителе"));
    queue.enqueue(&Teacher::showInfo, &teacher);

    queue.enqueue(printMessage, string("Добавляем объекты в школу"));
    queue.enqueue(&School::addStudent, &school, &student);
    queue.enqueue(&School::addTeacher, &school, &teacher);

    queue.enqueue(printMessage, string("Выводим список учеников"));
    queue.enqueue(&School::showAllStudents, &school);

    queue.enqueue(printMessage, string("Выводим список учителей"));
    queue.enqueue(&School::showAllTeachers, &school);

    queue.enqueue(printMessage, string("Все задачи выполнены"));

    cout << "\n--- Выполнение одного отложенного вызова через run() ---" << endl;
    queue.run();

    cout << "\n--- Выполнение остальных вызовов через run_all() ---" << endl;
    queue.run_all();

    return 0;
}
