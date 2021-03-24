#pragma once
#include <iostream>
#include <cstring>

class String
{
private:
    char *string;
    int size;
    int capacity;

    void copy(const String &_String);
    void erase();
    void resize();

public:
    String();
    String(const String &_String);
    String &operator+=(const String &_String);
    String &operator+(const String &_String);
    bool operator==(const String &_String);
    bool operator!=(const String &_String);
    int operator[](const int& index);
    String(const char *_str, const int size, const int capacity);
    ~String();

    void add(const char &symb);
    void insertAt(const char &symb, int index);
    void removeAt(int index);
    void trimStart();
    void trimEnd();
    void trimStart(int num);
    void trimEnd(int num);

    const int getLength() const;
    const char* getString() const;
    const int getCapacity() const;

    void setString(const char* _string);
    void setSize(const int _size);
    void setCapacity(const int _capacity);

    const void print() const;
};