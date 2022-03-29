// row.cpp
#include "row.h"
bool Row::operator<(Row&a)//ÔÚ´Ë´¦»¹ÊÇÑ¡ÔñÊ¹ÓÃÒýÓÃ 
{
    auto num = [](char s)
    {
        int n = int(s);
        if ('A' <= s && s <= 'Z')
        {
            return 2 * (n - 64);
        }
        else if ('a' <= s && s <= 'z')
        {
            return 2 * (n - 96) - 1;
        }
        else
        {
            return 0;
        }
    };
    std::string str1 = this->toStr();
    std::string str2 = a.toStr();
    int A = 0, B = 0;
    for (int i = 0; i < (signed)str1.size(); i++)
    {
        A += num(str1[i]);
        B += num(str2[i]);
        A *= 100;
        B *= 100;
    } //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ò»ï¿½ï¿½ï¿½ï¿½ï¿½Ô±È½Ï´ï¿½Ð¡ï¿½ï¿½×ªï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
    if (A < B)
    {
        return 1;
    }
    else if (A == B)
    {
        throw("ERROR !");
    }
    else
        return 0;
}
std::string Row::toStr()
{
    std::string temp;
    for(auto i=pos;i!=pos.end();i++)
    {   auto tmp=std::string i.getcontent();
        temp += tmp;
        temp+=' ';
    }
    return temp;
};
