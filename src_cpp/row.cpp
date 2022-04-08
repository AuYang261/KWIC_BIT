// Row.cpp
#include "Row.h"
bool Row::operator<(Row &a)  //�ڴ˴�����ѡ��ʹ������
{
    auto num = [](char s) {
        int n = int(s);
        if ('A' <= s && s <= 'Z') {
            return 2 * (n - 64);
        } else if ('a' <= s && s <= 'z') {
            return 2 * (n - 96) - 1;
        } else {
            return 0;
        }
    };
    std::string str1 = this->toStr();
    std::string str2 = a.toStr();
    for (int i = 0; i < str1.size(); i++) {
        if (i == str2.size()) {
            return false;
        }
        if (str1[i] == str2[i]) {
            continue;
        }
        if (num(str1[i]) < num(str2[i])) {  // str1[i] 的序更小，故str1更大
            return false;
        } else {
            return true;
        }
    }
}
std::string Row::toStr(bool format) {  // default false
    std::string temp;
    auto i = pos;
    do {
        if (i == _text.getWordsList().end()) {
            continue;
        }
        auto w = (*i)->getContent();
        if (format && (*i)->isFound()) {
            w = "*" + w + "*";
        }
        temp += w + ' ';
    } while (++i != pos);

    return temp;
};