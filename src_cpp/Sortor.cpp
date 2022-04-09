#include "Sortor.h"

void Sortor1::sort(std::list<Row *> &rows) {
    //降序，*a<*b则为升序
    rows.sort([](Row *a, Row *b) -> bool { return (*b < *a); });
}

void Sortor2::sort(std::list<Row *> &rows) {
    std::list<Row *>::iterator it = rows.begin();
    std::vector<Row *> v;
    for (; it != rows.end(); it++) {
        v.push_back(*it);
    }
    //降序，*a<*b则为升序
    std::sort(v.begin(), v.end(), [](Row *a, Row *b) { return *b < *a; });
    rows.clear();
    for (auto i : v) {
        rows.push_back(i);
    }
}