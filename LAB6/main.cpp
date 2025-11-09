#include "Transformer.h"
#include <windows.h>
#include <cstddef>
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef byte  


int main() {
    SetConsoleOutputCP(65001);  
    SetConsoleCP(65001);
    Transformer tr;

    tr.addTransformer(2.5, 220, 500);
    tr.addTransformer(1.8, 380, 750);
    tr.addTransformer(-2, 400, 900); 

    tr.showData();

    return 0;
}
