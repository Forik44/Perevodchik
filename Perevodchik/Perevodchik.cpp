﻿#include <iostream>
#include <fstream>
#include <cstring>
#include <fstream>
#include <windows.h>
#include <string>

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
    fse.open("C:\\Users\\poi12\\source\\repos\\Pere\\Debug\\d.txt", ios_base::binary);
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
                for (;k < 200;++k)
                    if (buffer[k] == '\0')
                        break;
                tmp[j - 1].en = new char[k + 1];
                for (size_t counter = 0; counter < k + 1;++counter)
                    tmp[j - 1].en[counter] = buffer[counter];

                fse.getline(buffer, 500, '\n');
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
    for (size_t i = 0; i < transstorage.size; i++)
    {
        std::cout << transstorage.data[i].en << " в переводе: " << transstorage.data[i].ru;
        cout << "\n\n\n\n";
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
//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//int main(int argc, char* argv[])
//{
//    int k = 100;
//    if (argc < 7) {
//        cout << "Not enough parameters" << endl;
//        return 1;
//    }
//    for (size_t i = 0; i < 5; i++)
//    {
//        cout << argv[i] << endl;
//    }
//    char* srcfilename = nullptr;
//    char* twfilename = nullptr;
//    if (argv[1][0] == '-' && argv[1][1] == 's') {
//        srcfilename = argv[2];
//    }
//    if (argv[1][0] == '-' && argv[1][1] == 'd') {
//        twfilename = argv[2];
//    }
//    if (argv[1][0] == '-' && argv[1][1] == 'b') {
//        k = (int)argv[2];
//    }
//    if (argv[3][0] == '-' && argv[3][1] == 's') {
//        srcfilename = argv[4];
//    }
//    if (argv[3][0] == '-' && argv[3][1] == 'd') {
//        twfilename = argv[4];
//    }
//    if (argv[3][0] == '-' && argv[3][1] == 'b') {
//        k = (int)argv[4];
//    }
//    if (argv[5][0] == '-' && argv[5][1] == 's') {
//        srcfilename = argv[6];
//    }
//    if (argv[5][0] == '-' && argv[5][1] == 'd') {
//        twfilename = argv[6];
//    }
//    if (argv[5][0] == '-' && argv[5][1] == 'b') {
//        k = (int)argv[6];
//    }
//    if (k < 0)
//        return 1;
//    cout << srcfilename << twfilename;
//    if (srcfilename == nullptr || twfilename == nullptr)
//    {
//        return 1;
//    }
//
//    fstream srcfs;
//    srcfs.open(srcfilename, ios_base::in | ios_base::binary);
//    fstream dstfs;
//    dstfs.open(twfilename, ios_base::out | ios_base::trunc | ios_base::binary);
//    if (srcfs.is_open() && dstfs.is_open()) {
//        int size = 1;
//        int count = 0;
//        srcfs.seekg(0, ios_base::end);
//        int sizef = srcfs.tellg();
//        srcfs.seekg(0);
//        char* c = new char[k];
//        while (1) {
//
//
//            if (0 < sizef - count && sizef - count < k)
//            {
//                srcfs.read(c, sizef - count);
//            }
//            else
//            {
//                srcfs.read(c, k);
//            }
//            count += k;
//            /*  cout << size << " ";
//              bool k = srcfs.fail();
//              bool g = srcfs.bad();
//              cout << k << " " << g;*/
//            if (srcfs.eof()) break;
//            if (0 < sizef - count && sizef - count < k)
//            {
//                dstfs.write(c, sizef - count);
//            }
//            else
//            {
//                dstfs.write(c, k);
//            }
//            dstfs.flush();
//        }
//        delete[] c;
//        srcfs.close();
//        dstfs.close();
//        return 0;
//    }
//    else
//    {
//        cout << "File isnt open";
//    }
//    return 1;
//
//
//    /*
//    fstream fs;
//    fs.open("sample.txt",ios_base::trunc|ios_base::out);
//    if (fs.is_open()){
//        fs << "Hello" << endl;
//        fs << 1234567;
//        int k = 1234567;
//        fs.write((char*)&k,sizeof(k));
//        cout << " Now at write marker " << fs.tellp() << endl;
//        fs.seekp(0);
//        fs << "olleH";
//        fs.close();
//    }
//    fs.open("sample.txt",ios_base::in);
//    if (fs.is_open()){
//        char c = fs.get();
//        cout << "read c " << c << endl;
//        cout << " Now at " << fs.tellg() << endl;
//        fs.seekg(4);
//        c = fs.get();
//        cout << "read c " << c << endl;
//        cout << " Now at " << fs.tellg() << endl;
//        fs.seekg(4,ios_base::cur);
//        c = fs.get();
//        cout << "read c " << c << endl;
//        cout << " Now at " << fs.tellg() << endl;
//        fs.seekg(0,ios_base::beg);
//        c = fs.get();
//        cout << "read c " << c << endl;
//        cout << " Now at " << fs.tellg() << endl;
//        fs.seekg(0,ios_base::end);
//        cout << " Now at " << fs.tellg() << endl;
//        cout << " file size " << fs.tellg() << endl;
//            }
//            */
//    return 0;
//    //Указывать размер буфера в лбом месте в командной строке. Проверять корректность значения(например -1 0).readsome найти в чём проблема.
//}
