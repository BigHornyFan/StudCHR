// StudChr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum Kategory {
    old = 1, young = 0
};

string print_age(int m, int y);

int main()
{
    ofstream write;
    ifstream read;

    read.open("Stud.txt");
    write.open("result.txt");

    char x;
    int counter=0;
    
    int month;
    int year;
    string m;
    string y;

    while (read >> x) {
        
        ++counter;
        if (counter == 4)
            m.push_back(x);
        if (counter == 5) {
            m.push_back(x);
            month = stoi(m);
        }
        if (counter == 9)
            y.push_back(x);
        if (counter == 10) {
            y.push_back(x);

            string info = print_age(stoi(m), stoi(y));
            write << info << endl;

            m.clear();
            y.clear();
            counter = 0;
        }
    }
}

string print_age(int m, int y)
{
    if (y < 50)
        y += 2000;
    else
        y += 1900;
    if (m < 8)
        --y;
    
    string ;
    return "01.09." + to_string(y) + "-31.08." + to_string(y + 1) + ";";
}
