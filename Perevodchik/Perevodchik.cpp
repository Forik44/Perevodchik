#include <iostream>
#include <cstring>
#include <fstream>
#include <Windows.h>
#include <stdio.h>


using namespace std;

const char* Rus(const char* str)
{
    static char s[1024];
    CharToOem(str, s);
    return s;
}
struct Translation {
    char* ru;
    char* en;
};
struct Array {
    size_t size;
    Translation* data;
};
Array transstorage = { 0,nullptr };
void AddTranslition(const char* en, const char* ru)
{
    fstream fse;
    fse.open("slovar.txt", ios_base::binary | ios_base::out | ios_base::app);
    if (fse.is_open())
    {
        fse.seekp(0, ios_base::end);
        fse << "\n" << en << "\t" << ru;
        fse.close();
    }
    else
    {
        cout << Rus("Файл не открыт!");
    }
}
//Translation findTranslation(Array* array, const char* en)
//{
//    return 0;
//}
//deleteTranslation



int main(int argc, char* argv[])
{
    
    string s;
    char buffer[450];
    fstream fse;
    fse.open("slovar.txt", ios_base::binary | ios_base::in);
    if (fse.is_open())
    {
        for (size_t j = 1; j < 1000000; j++)
        {
           
            if (transstorage.size >= 0) {
                if (fse.eof())
                    break;
                Translation* tmp = new Translation[j];
                fse.getline(buffer, 200, '\t');
                size_t k = 0;
                for (;k < 100;++k)
                    if (buffer[k] == '\0')
                        break;
                tmp[j - 1].en = new char[k + 1];
                for (size_t counter = 0; counter < k + 1;++counter)
                    tmp[j - 1].en[counter] = buffer[counter];

                fse.getline(buffer, 450, '\n');
                k = 0;
                for (;k < 500;++k)
                    if (buffer[k] == '\0')
                        break;
                tmp[j - 1].ru = new char[k + 1];
                for (size_t counter = 0; counter < k + 1;++counter)
                    tmp[j - 1].ru[counter] = buffer[counter];

                for (size_t i = 0; i < transstorage.size; i++)
                {
                    tmp[i] = transstorage.data[i];
                }
                delete transstorage.data;
                transstorage.data = tmp;
                transstorage.size++;
            }
        }
        fse.close();
        AddTranslition("Egor", "Егор");
    }
    else
    {
        cout << Rus("Файл не открыт!");
    }
    
    for (size_t i = 0; i < transstorage.size; i++)
    {
        delete[] transstorage.data[i].en;
        delete[] transstorage.data[i].ru;
    }
    delete transstorage.data;
    int o;
    cin >> o;
    return 0;

}


