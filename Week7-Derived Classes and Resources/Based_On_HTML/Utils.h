/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Data:27/11/2022
Section:NBB
*/
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include <iostream>

namespace sdds {
    class Utils {
    public:
        unsigned getFileLength(std::istream& is);
        char* alcpy(const char* cstr);
        char tolower(char ch)const;
        char* strcat(char* des, const char* src)const;
        int strcmp(const char* s1, const char* s2)const;
        int strcmp(const char* s1, const char* s2, int len)const;
        char* strcpy(char* des, const char* src)const;
        char* strcpy(char* des, const char* src, int len)const;
        char* strncpy(char* des, const char* src, int len)const;
        int strlen(const char* str)const;
        const char* strstr(const char* str, const char* find)const;
        int isalpha(char ch)const;
        int isspace(char ch)const;
        void trim(char word[])const;
        char* lowerstrcpy(char des[], const char source[])const;
        void read(char* cString, unsigned int maxSize, char delimiter = '\n')const;
        int getint(const char* prompt = nullptr, std::istream& istr = std::cin)const;
        std::istream& getint(int& num, const char* prompt = nullptr, std::istream& istr = std::cin)const;
        char* getDynCstr(std::istream& istr);
        char* getDynCstr(const char* prompt = nullptr);
    };
    extern Utils ut;
    extern bool sdds_debug;
}

#endif // !SDDS_UTILS_H