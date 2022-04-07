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

    int A = 0, B = 0;
    for (int i = 0; i < (signed)str1.size(); i++) {
        A += num(str1[i]);
        B += num(str2[i]);
        A *= 100;
        B *= 100;
    }  //������һ�����ԱȽϴ�С��ת������
    if (A < B) {
        return 1;
    } else if (A == B) {
        throw("ERROR !");
    } else
        return 0;
}
std::string Row::toStr() {
    std::string temp;
    auto i = pos;
    do {
        if (i == _text.getWordsList().end()) {
            continue;
        }

        temp += (*i)->getContent() + ' ';
    } while (++i != pos);

    return temp;
};