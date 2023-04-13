//
// Created by MikoG on 13.04.2023.
//

#ifndef ROGOVURTK_LABS_I26LAB_H
#define ROGOVURTK_LABS_I26LAB_H

#include <iostream>
#include "core.h"

class ILab26 {
private:
    core::int32_t  first;
    core::int32_t second;

public:
    ILab26() : first(0), second(0) {}
    ILab26(core::int32_t first, core::int32_t second)
                       : first(first), second(second) {}

    ILab26&       operator+ (const ILab26&);
    ILab26&       operator- (const ILab26&);
    ILab26&       operator* (const ILab26&);
    ILab26&       operator/ (const ILab26&);
    core::int32_t operator==(const ILab26&);

    ILab26&            reduction_fraction();
    core::empty_t                 display();
};

#endif //ROGOVURTK_LABS_I26LAB_H
