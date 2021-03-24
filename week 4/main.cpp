#include <iostream>
#include "String.h"
#include "Rational.h"

int main() {

    String message;
    message.setString("I am truly aware!");
    message.print();
    String message2("I am truly aware!", 18, 19);
    std::cout << (message == message2);
    message.insertAt('W', 4);
    message.add('c');
    message.add('c');
    message.add('c');
    message.add('c');
    message.print();
    message.insertAt('W', 4);
    message.insertAt('W', 25);
    message.print();
    message.trimStart();
    message.print();
    message.trimEnd(5);
    message.print();

    // Task 2
    Rational chislo(1, 3);
    Rational chislo2(3,9);
    chislo + chislo2;
    chislo.print();
    chislo - chislo2;
    chislo.print();
    chislo * chislo2;
    chislo.print();
    chislo /= chislo2;
    chislo.print();
    std::cout << (chislo <= chislo2);
    return 0;
}