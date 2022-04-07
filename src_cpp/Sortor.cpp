#include "Sortor.h"

void Sortor1::sort(std::list<Row *> &rows) {
    rows.sort([](Row *a, Row *b) -> bool { return (*a < *b); });
}

void Sortor2::sort(std::list<Row *> &rows) {
    //
}