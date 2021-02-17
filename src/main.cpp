#include <iostream>
#include "tools/ledmatrix.hpp"
#include "tools/ledcolor.hpp"
#include "tools/debugprint.hpp"

int main() {
    LedMatrix m(false);
    m.all(COLOR_BLACK);
    DebugPrint::print(m);
    m.all(COLOR_WHITE);
    DebugPrint::print(m);

    return 0;
}
