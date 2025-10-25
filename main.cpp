#include "Transformer.h"

int main() {
    Transformer tr;

    tr.addTransformer(2.5, 220, 500);
    tr.addTransformer(1.8, 380, 750);
    tr.addTransformer(-2, 400, 900); 

    tr.showData();

    return 0;
}
