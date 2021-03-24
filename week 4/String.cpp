#include "String.h"

void String::copy(const String &_String)
{
    setString(_String.string);
    setSize(_String.size);
    setCapacity(_String.capacity);
}

void String::erase()
{
    this->size = 0;
    this->capacity = 0;
    delete[] this->string;
}

String::String()
{
    this->size = 6;
    this->capacity = 6;
    this->string = new char[this->capacity];
    strcpy(this->string, "Empty");
}

void String::resize()
{
    this->capacity *= 2;
    char *biggerString = new char[this->capacity];
    for (int i = 0; i < size; i++)
    {
        biggerString[i] = this->string[i];
    }
    delete[] string;
    this->string = biggerString;
}

String::String(const String &_String)
{
    copy(_String);
}

String::String(const char *_str, const int size, const int capacity)
{
    setString(_str);
    setSize(size);
    setCapacity(capacity);
}

String::~String()
{
    erase();
}

String &String::operator+(const String &_String)
{
    for (int i = 0; i < _String.size; i++)
    {
        this->add(_String.string[i]);
    }
    return *this;
}

String &String::operator+=(const String &_String)
{
    return *this + _String;
}

bool String::operator==(const String &_String)
{
    if (this->size != _String.size)
        return false;
    for (int i = 0; i < this->size; i++)
    {
        if (this->string[i] != _String.string[i])
            return false;
    }
    return true;
}

bool String::operator!=(const String &_String)
{
    return !(*this == _String);
}

int String::operator[](const int &index)
{
    return this->string[index];
}

void String::add(const char &symb)
{
    if (capacity + 1 <= this->size)
        this->resize();

    this->string[this->size++] = symb;
    this->string[this->size] = '\0';
}

void String::insertAt(const char &symb, int index)
{
    if (capacity + 1 <= this->size)
        this->resize();
    if (index > this->size)
        index = this->size;
    int i = this->size;
    for (; i > index; i--)
    {
        this->string[i] = this->string[i - 1];
    }
    this->string[index] = symb;
}

void String::removeAt(int index)
{
    if (size <= 0)
        return;
    if (index > this->size)
        index = size;
    int i = index;
    for (; i < this->size; i++)
    {
        this->string[i] = string[i + 1];
    }
    this->size--;
}

void String::trimStart()
{
    if (size <= 0)
        return;
    int i = 0;
    for (; i < this->size; i++)
    {
        this->string[i] = string[i + 1];
    }
    this->size--;
}

void String::trimEnd()
{
    if (size > 0)
    {
        this->size--;
        this->string[size] = '\0';
    }
}

void String::trimStart(int num)
{
    if (size <= 0)
        return;
    for (int k = num; k > 0; k--)
    {
        for (int i = num; i < this->size; i++)
        {
            this->string[i] = string[i + 1];
        }
        num--;
        this->size--;
    }
}

void String::trimEnd(int num)
{
    if (size > 0)
    {
        this->size -= num;
        this->string[size] = '\0';
    }
}

const int String::getLength() const
{
    return this->size;
}

const char *String::getString() const
{
    return this->string;
}

const int String::getCapacity() const
{
    return this->capacity;
}

void String::setString(const char *_string)
{
    delete[] this->string;
    this->size = strlen(_string) + 1;
    this->capacity = this->size + 1;
    this->string = new char[size];
    strcpy(this->string, _string);
}

// Kinda not secure and deff not necessary but im gonna put it anyway
void String::setSize(const int _size)
{
    if (_size > this->size)
        this->size = _size;
}

void String::setCapacity(const int _capacity)
{
    if (_capacity > this->size)
        this->capacity = _capacity;
}

const void String::print() const
{
    std::cout << "String: " << this->string << std::endl;
    std::cout << "Size: " << this->size << std::endl;
    std::cout << "Capacity: " << this->capacity << std::endl;
}