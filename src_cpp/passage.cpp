#include "Passage.h"

std::list<std::string> split(const std::string &str,
                             const std::string &pattern) {
    std::list<std::string> res;
    if (str == "") return res;
    //在字符串末尾也加入分隔符，方便截取最后一段
    std::string strs = str + pattern;
    size_t pos = strs.find(pattern);

    while (pos != strs.npos) {
        std::string temp = strs.substr(0, pos);
        res.push_back(temp);
        //去掉已分割的字符串,在剩下的字符串中进行分割
        strs = strs.substr(pos + 1, strs.size());
        pos = strs.find(pattern);
    }

    return res;
}

void Passage::sortRow() {
    rows.sort([](Row *a, Row *b) -> bool { return (*a < *b); });
}  //���ﲻ�ԳƵ��ǲ�֪������ô��

void Passage::input(std::string filePath) {  //�˴��õ����ļ���,���ظ��Լ�
    for (auto &i : texts) {
        delete i;
    }
    texts.clear();
    std::ifstream mapFile(filePath);
    if (mapFile) {
        std::string mapStr((std::istreambuf_iterator<char>(mapFile)),
                           std::istreambuf_iterator<char>());
        std::list<std::string> lines = split(mapStr, "\n");
        for (auto &i : lines) {
            auto words = split(i, " ");
            texts.push_back(new Text(words));
        }
        // 现在能成功读入文件
        // std::cout << mapStr << std::endl;
    }
}

std::string Passage::toStr() {
    std::string tmp;
    std::string temp;
    int n = (signed)rows.size();
    for (auto &i : rows) {
        tmp = i->toStr();
        temp += tmp;
        temp += '\n';
    }
    return temp;
}

void Passage::findWords(std::string words) {
    auto wordsList = split(words, " ");
    for (auto &i : texts) {
        for (auto &word : wordsList) {
            i->find(word);
        }
    }
}
