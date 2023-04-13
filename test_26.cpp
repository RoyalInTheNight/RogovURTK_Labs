//
// Created by MikoG on 13.04.2023.
//

#include "I26lab.h"

core::int32_t main() {
    ILab26 lab26 (2, 5);
    ILab26 lab262(2, 6);

    lab26 = lab26 + lab262;
    lab26.display();
    lab26 = lab26 - lab262;
    lab26.display();
    lab26 = lab26 / lab262;
    lab26.display();
    lab26 = lab26 * lab262;
    lab26.display();

    lab26 = lab262;


    std::cout << "lab26.d(): " << std::endl; lab26.display(); std::cout << std::endl << "lab262.d(): " << std::endl; lab262.display(); std::cout << std::endl;

    switch (lab26 == lab262) {
        case -1:
            std::cout << "lab26 < lab262" << std::endl;
            break;
        case 0:
            std::cout << "lab26 == lab262" << std::endl;
            break;
        case 1:
            std::cout << "lab26 > lab262" << std::endl;
            break;
    }
}