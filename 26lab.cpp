//
// Created by MikoG on 13.04.2023.
//
#include "I26lab.h"

ILab26& ILab26::operator+(const ILab26 &values) {
    this->first = this->first + values.first;

    if (this->second != values.second)
        this->second = ((this->first * values.second) +
                        (this->second * values.first));

    return *this;
}

ILab26& ILab26::operator-(const ILab26 &values) {
    this->first = this->first - values.first;

    if (this->second != values.second)
        this->second = ((this->first * values.second) +
                        (this->second * values.first));

    return *this;
}

ILab26& ILab26::operator*(const ILab26 &values) {
    ILab26 val = values;

    if (val.first > this->second && val.first % this->second == 0) {
        val.first = val.first / this->second;
        this->second = 1;
    }

    else if (val.first < this->second && this->second % val.first == 0) {
        this->second = this->second / val.first;
        val.first = 1;
    }

    if (this->first > val.second && this->first % val.second == 0) {
        this->first = this->first / val.second;
        val.second = 1;
    }

    else if (this->first < val.second && val.second % this->first == 0) {
        val.second = val.second / this->first;
        this->first = 1;
    }

    this->first  = this->first * val.first;
    this->second = this->second * val.second;

    return *this;
}

ILab26& ILab26::operator/(const ILab26 &values) {
    this->first = this->first * values.second;
    this->second = this->second * values.first;

    return *this;
}

ILab26& ILab26::reduction_fraction() {
    if (this->second > this->first) {
        core::int32_t count = this->first;

        while (count != 1) {
            if (this->second % count == 0) {
                this->second = this->second / count;
                this->first  = 1;
                count = 1;
            }

            else
                count--;
        }
    }

    else if (this->second < this->first) {
        core::int32_t count = this->second;

        while (count != 1) {
            if (this->first % count == 0) {
                this->first = this->first / count;
                this->second = 1;
                count = 1;
            }

            else
                count--;
        }
    }

    else {
        this->first = 1;
        this->second = 1;
    }

    return *this;
}

core::int32_t ILab26::operator==(const ILab26 &values) {
    this->reduction_fraction();

    if (this->first < values.first && this->second >= values.second)
        return -1;

    else if (this->first > values.first && this->second <= values.second)
        return 1;

    return 0;
}

core::empty_t ILab26::display() {
    std::cout << this->first  << std::endl
              << "---"        << std::endl
              << this->second << std::endl << std::endl;
}