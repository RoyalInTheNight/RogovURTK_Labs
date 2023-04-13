//
// Created by MikoG on 13.04.2023.
//

#include <iostream>
#include "core.h"

class lab24 {
private:
    core::float32_t  first;
    core::float32_t second;

public:
    inline core::int32_t init(core::float32_t x, core::float32_t y) {
        if(x == y) {
            std::cout << "min == max" << std::endl;
            return 0;
        }

        else {
            if(x > y) {
                core::float32_t n;

                n = x;
                x = y;
                y = n;
            }

            this->first = x; this->second = y;

            std::cout << std::endl;
        }

        return 1;
    }

    core::empty_t read() {
        core::float32_t fs;
        core::float32_t sc;

        std::cout << "min - max" << std::endl;

        do {
            std::cin >> fs >> sc;

        } while((init(fs, sc)) == 0);
    }

    core::empty_t display() {
        std::cout << first << " ... " << second << std::endl << std::endl;
    }

    core::empty_t rangcheck(core::float32_t x) {
        if(x > first && x < second)
            std::cout << "[*]Values normally..." << std::endl;

        else
            std::cout << "[!]Num out of range..." << std::endl;
    }
};

core::int32_t main() {
    lab24 lab;

    core::int8_t   take;
    core::float32_t chk;

    std::cout << "Enter diapasone: " << std::endl;

    lab.read();

    do {
        std::cout
                << "\t1 - change diapasone"     << std::endl
                << "\t2 - check num"            << std::endl
                << "\t3 - view diapasone"       << std::endl
                << "\t0 - end"                  << std::endl;

        std::cin >> take;

        switch (take) {
            case '1':
                lab.read();

                break;

            case '2':
                std::cout << "Enter num: " << std::endl;
                std::cin >> take; lab.rangcheck(chk);

                break;

            case '3':
                lab.display();
                break;

            case '0':
                break;

            default:
                std::cout << "Repeat please" << std::endl;
                break;
        }

    } while(take != '0');
}