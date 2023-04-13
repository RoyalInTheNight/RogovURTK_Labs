//
// Created by MikoG on 13.04.2023.
//

#include <iostream>
#include "core.h"

class lab25 {
private:
    core::float32_t  first;
    core::float32_t second;

public:
    core::int32_t init(core::float32_t first, core::float32_t second) {
        if (this->first == 0 && this->second == 0)
            return 1;

        return 0;
    }

    core::float32_t get_first() {
        return this->first;
    }

    core::float32_t get_second() {
        return this->second;
    }

    core::empty_t read(core::float32_t first = 0, core::float32_t second = 0) {
        if (first == 0 && second == 0) {
            std::cin >> this->first >> this->second;

            if (init(this->first, this->second))
                this->read();
        }

        else {
            this->first  = first;
            this->second = second;
        }
    }

    core::empty_t display() {
        std::cout << "[INFO]First sum value: "  << this->first  << std::endl
                  << "[INFO]Second sum value: " << this->second << std::endl;
    }
};

lab25 sum(lab25 first_c, lab25 second_c) {
    lab25 object;

    object.read(first_c.get_first() + second_c.get_first(),
                first_c.get_second() + second_c.get_second());

    return object;
}

core::int32_t main() {
    lab25 object1;
    lab25 object2;
    lab25 object3;

    object1.read();
    object2.read();
    object3 = sum(object1, object2);

    object3.display();
}