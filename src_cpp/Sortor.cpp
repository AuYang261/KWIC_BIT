#include "Sortor.h"

void Sortor1::sort(std::list<Row *> &rows) {
    //降序，*a<*b则为升序
    rows.sort([](Row *a, Row *b) -> bool { return (*b < *a); });
}

void Sortor2::sort(std::list<Row *> &rows) {
    //
}