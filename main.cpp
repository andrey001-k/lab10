#include <iostream>
#include <iomanip>

using namespace std;

// Структура для зберігання часу (для першого завдання)
struct TTime {
    int hours;    // Години (0-23)
    int minutes;  // Хвилини (0-59)
    int seconds;  // Секунди (0-59)
};

// Функція для перевірки правильності часу
bool IsValidTime(const TTime& T) {
    return (T.hours >= 0 && T.hours <= 23 &&
        T.minutes >= 0 && T.minutes <= 59 &&
        T.seconds >= 0 && T.seconds <= 59);
}

// Процедура для зменшення часу на 1 хвилину
void PrevMin(TTime& T) {
    // Перевірка чи час правильний
    if (!IsValidTime(T)) {
        return; // Якщо час неправильний, він не змінюється
    }

    // Зменшення часу на 1 хвилину
    T.minutes--;

    // Обробка випадку, коли хвилини стають від'ємними
    if (T.minutes < 0) {
        T.minutes = 59;
        T.hours--;

        // Обробка випадку, коли години стають від'ємними
        if (T.hours < 0) {
            T.hours = 23;
        }
    }
}

// Функція для виведення часу
void PrintTime(const TTime& T, const char* label) {
    cout << label << ": ";
    if (IsValidTime(T)) {
        cout << setfill('0') << setw(2) << T.hours << ":"
            << setfill('0') << setw(2) << T.minutes << ":"
            << setfill('0') << setw(2) << T.seconds;
    }
    else {
        cout << "Неправильное ";
    }
    cout << endl;
}

// Завдання 1: Param74
void Param74()
{
    cout << "\n--- Задание 1: Param74 ---" << endl;

    const int NUM_TIMES = 5;
    TTime times[NUM_TIMES];

    cout << "Введите " << NUM_TIMES << " моментов времени в формате: час мин сек:" << endl;

    // Зчитування введених користувачем моментів часу
    for (int i = 0; i < NUM_TIMES; i++)
    {
        cout << "Время " << (i + 1) << " (час мин сек): ";
        cin >> times[i].hours >> times[i].minutes >> times[i].seconds;
    }

    cout << "\nРезультаты выполнения процедури PrevMin:" << endl;

    // Застосування процедури PrevMin до кожного моменту часу
    for (int i = 0; i < NUM_TIMES; i++)
    {
        cout << "Час " << (i + 1) << ":" << endl;

        // Виведення початкового часу
        PrintTime(times[i], "До");

        // Застосування процедури PrevMin
        PrevMin(times[i]);

        // Виведення зміненого часу
        PrintTime(times[i], "После");

        cout << endl;
    }
}

// Завдання 2: Begin28
void Begin28()
{
    cout << "\n--- Задание 3: Begin28 ---" << endl;

    double A;
    cout << "Введите число A: ";
    cin >> A;

    // Початкове значення
    cout << "A^1 = " << A << endl;

    // Обчислюємо A^2 = A * A
    double A2 = A * A;
    cout << "A^2 = " << A2 << endl;

    // Обчислюємо A^3 = A^2 * A
    double A3 = A2 * A;
    cout << "A^3 = " << A3 << endl;

    // Обчислюємо A^5 = A^3 * A^2
    double A5 = A3 * A2;
    cout << "A^5 = " << A5 << endl;

    // Обчислюємо A^10 = A^5 * A^5
    double A10 = A5 * A5;
    cout << "A^10 = " << A10 << endl;

    // Обчислюємо A^15 = A^10 * A^5
    double A15 = A10 * A5;
    cout << "A^15 = " << A15 << endl;
}

// Завдання 3: Boolean2
void Boolean2()
{
    cout << "\n--- Завдання 2: Boolean2 ---" << endl;

    int A;
    cout << "Введите целое число A: ";
    cin >> A;

    // Перевірка, чи є число непарним
    bool isOdd = (A % 2 != 0);

    cout << "Выражение «Число A нечетное» - ";
    if (isOdd)
    {
        cout << "истина" << endl;
    }
    else
    {
        cout << "ложь" << endl;
    }
}

// Головна функція
int main()
{
    setlocale(LC_ALL, "rus");
    int choice;

    do
    {
        cout << "\nВыберите задание:\n"
            << "1. Param74\n"
            << "2. Begin28\n"
            << "3. Boolean2\n"
            << "0. Выход\n"
            << "Ваш выбор: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Param74();
            break;
        case 2:
            Begin28();
            break;
        case 3:
            Boolean2();
            break;
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор! Попробуйте еще раз.\n";
        }
    } while (choice != 0);

    return 0;
}
