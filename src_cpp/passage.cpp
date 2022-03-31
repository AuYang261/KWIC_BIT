#include "passage.h"
#include "row.h"

std::vector<std::string> split(const std::string &str, const std::string &pattern)
{
    std::vector<std::string> res;
    if (str == "")
        return res;
    //在字符串末尾也加入分隔符，方便截取最后一段
    std::string strs = str + pattern;
    size_t pos = strs.find(pattern);

    while (pos != strs.npos)
    {
        std::string temp = strs.substr(0, pos);
        res.push_back(temp);
        //去掉已分割的字符串,在剩下的字符串中进行分割
        strs = strs.substr(pos + 1, strs.size());
        pos = strs.find(pattern);
    }

    return res;
}

void Passage::sortRow()
{
    std::sort(rows.begin(), rows.end(), [](Row *a, Row *b) -> bool
              { return (*a < *b); });
} //���ﲻ�ԳƵ��ǲ�֪������ô��

void Passage::input(std::string filePath)
{ //�˴��õ����ļ���,���ظ��Լ�
    std::ifstream mapFile(filePath);
    if (mapFile)
    {
        std::string mapStr((std::istreambuf_iterator<char>(mapFile)),
                           std::istreambuf_iterator<char>());
        std::vector<std::string> lines = split(mapStr, "\n");
        for (auto &i : lines)
        {
            auto words = split(i, " ");
            texts.push_back(new Text(words));
        }
    }
}

std::string Passage::toStr()
{
    std::string tmp;
    std::string temp;
    int n = (signed)rows.size();
    for (int i = 0; i < n; i++)
    {
        tmp = rows[i]->toStr();
        temp += tmp;
        temp += '\n';
    }
    return temp;
}
