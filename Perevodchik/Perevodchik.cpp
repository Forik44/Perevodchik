#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;

int main(int argc, char* argv[])
{

    setlocale(LC_ALL, "Russian");
    string s;
    struct Translation {
        char* ru;
        char* en;
    };
    struct Array {
        size_t size;
        Translation* data;
    };
    Array transstorage = { 0,nullptr };
    char buffer[500];
    ifstream fse;
    fse.open("d.txt", ios_base::binary);
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
    }
    else
    {
        cout << "Файл не открыт!";
    }
    for (size_t i = 0; i < transstorage.size; i++)
    {
        std::cout << transstorage.data[i].en << " в переводе: " << transstorage.data[i].ru;
        cout << "\n\n\n";
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


