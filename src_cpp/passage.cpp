#include "passage.h"

#include "Factory.h"

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

void Passage::sortRow(std::string strategy) {
    if (!sortor->isMe(strategy)) {
        setSortor(SortorFactory::Singleton().create(strategy));
    }
    sortor->sort(rows);
}

std::string Passage::input(std::string filePath) {  //�˴��õ����ļ���,���ظ��Լ�
    for (auto &i : texts) {
        delete i;
    }
    for (auto &i : rows) {
        delete i;
    }
    texts.clear();
    rows.clear();
    std::ifstream mapFile(filePath);
    if (mapFile) {
        std::string mapStr((std::istreambuf_iterator<char>(mapFile)),
                           std::istreambuf_iterator<char>());
        std::list<std::string> lines = split(mapStr, "\n");
        for (auto &i : lines) {
            texts.push_back(new Text(i));
        }
        for (auto &t : texts) {
            auto _rows = t->shift();
            rows.insert(rows.end(), _rows.begin(), _rows.end());
        }
        mapFile.close();
        return mapStr;
    }
    return "Read file failed!";
}

std::string Passage::toStr() {
    std::string temp;
    for (auto &i : rows) {
        if (findMode && !i->isMatch()) {
            continue;
        }
        temp += i->toStr(true) + '\n';
    }
    return temp;
}

void Passage::findWords(std::string words) {
    if (words == "") {  // words == ""则取消查找模式
        findMode = false;
        for (auto &i : texts) {
            i->cleanFound();
        }
    } else {
        auto wordsList = split(words, " ");
        for (auto &i : texts) {
            for (auto &word : wordsList) {
                i->find(word);
            }
        }
    }
}
