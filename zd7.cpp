// zd7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<array>
using namespace std;


//typedef enum { married, divorced, neverBeenMarried } questFamilyStatus;


typedef enum { man, woman } questGender;
struct questionary {
    string fio, familyStatus;
    int birthday;
    questGender gender;
    union {
        char military[100]; 
        char address[100];  
    } detailed;
};

void Print(questionary q[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "------------------------" << endl;
        std::cout << "FIO: " << q[i].fio << endl;
        std::cout << "Birthday: " << q[i].birthday << endl;
        std::cout << "Family status: " << q[i].familyStatus << endl;
        switch (q[i].gender) {
        case man: {
            std::cout << "Gender: man" << endl;
            std::cout << "Military service: " << q[i].detailed.military << endl;
            break;
        }
        case woman: {
            std::cout << "Gender: woman" << endl;
            std::cout << "Address: " << q[i].detailed.address << endl;
            break;
        }
        }
    }
}

questionary* Sort(questionary q[], int size, int& sortedSize) {
    questionary* sortArr = new questionary[size];
    sortedSize = 0;
    for (int i = 0; i < size; i++) {
        if (q[i].gender == woman && q[i].familyStatus == "married")
            sortArr[sortedSize++] = q[i];
    }
    for (int i = 0; i < sortedSize - 1; i++) {
        for (int j = 0; j < sortedSize - i - 1; j++) {
            if (sortArr[j].birthday > sortArr[j + 1].birthday) {
                questionary temp = sortArr[j];
                sortArr[j] = sortArr[j + 1];
                sortArr[j + 1] = temp;
            }
        }
    }
    return sortArr;
}



int main()
{
    questionary q[3];
    for (int i = 0; i < sizeof(q) / sizeof(q[0]); i++) {
        std::cout << "Enter FIO" << endl;
        cin >> q[i].fio;
        std::cout << "Enter birthday" << endl;
        cin >> q[i].birthday;
        while (true) {
            std::cout << "Enter family status" << endl;
            cin >> q[i].familyStatus;
            if (q[i].familyStatus == "married" || q[i].familyStatus == "divorced" || q[i].familyStatus == "never been married")
                break;
            else 
                std::cout << "Family status entered incorrectly" << endl;
        }
        while (true) {
            std::cout << "Enter gender" << endl;
            string gender;
            cin >> gender;
            if (gender == "man") {
                q[i].gender = man;
                break;
            }
            else if (gender == "woman") {
                q[i].gender = woman;
                break;
            }
            else
                std::cout << "Gender entered incorrectly" << endl;
        }
        switch (q[i].gender) {
        case man: {
            std::cout << "Enter, are you liable for military service" << endl;
            cin >> q[i].detailed.military;
            break;
        }
        case woman: {
           std::cout << "Enter address" << endl;
           cin >> q[i].detailed.address;
           break;
        }
        }
    }
    std::cout << "------------------------" << endl;
    std::cout << "All users" << endl;
    Print(q, sizeof(q) / sizeof(q[0]));
    std::cout << "------------------------" << endl;
    std::cout << "Married women" << endl;
    int sortedSize;
    questionary* sort = Sort(q, sizeof(q) / sizeof(q[0]), sortedSize);
    Print(sort, sortedSize);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
