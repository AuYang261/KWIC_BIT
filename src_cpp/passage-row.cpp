#include <algorithm>
#include <iostream>
#include <list>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;
class Word
{
public: // must be a public or it be private
    string content;
    bool flagFind;
    int id;
};

class Text
{
public:
    vector<Word> words;
};
class Row
{
    vector<Word>::iterator words;
    Text textPrototype;
};

class Passage
{
public:
    list<Text> texts;
    vector<Row> rows;
    sortRow()
    {
        sort(rows.begin(), rows.end(), [=](Row a, Row b) ->
             { return (a < b); });
    }
    void input(FILE *fp)
    { //此处用的是文件流,返回给自己
        if ((fp = fopen(filename, "r")) == NULL)
        {
            throw("ERROR");
        }
        string line;
        else while (getline(fp, line))
        { //这里这样子不知道能不能运行qwq
            string tmp;
            Text t;
            tmp = strok(line, " "); // strok 按照空格分开
            int i = 0;
            while (tmp)
            {
                Word temp;
                temp.content = tmp;
                temp.id = i;
                temp.flagFind = 0;
                t.words.push_back(temp);
                i++;
                tmp = strok(NULL, " ");
            }
            texts.push_back(t);
        }
    }
    string toStr()
    {
        string tmp;
        string temp;
        int n = (signed)rows.size();
        for (int i = 0; i < n; i++)
        {
            tmp = rows[i].toStr();
            temp += tmp;
            temp += '\n';
        }
        return temp;
    }
};

class Row
{
public:
    vector<Word>::iterator pos;
    Text textPrototype;
    bool operator<(const Row &a) const
    {
        int num(char s)
        {
            int n = int(s);
            if ('A' <= s && s <= 'Z')
            {
                return 2 * (n - 64)
            }
            else if ('a' <= s && s <= 'z')
            {
                return 2 * (n - 97) - 1
            }
            else
            {
                return 0
            };
        }
        str1 = this.toStr();
        str2 = a.toStr();
        int A = 0, B = 0;
        for (int i = 0, i < string.length(); i++)
        {
            A += num(str1[i]);
            B += num(str2[i]);
            A *= 100;
            B *= 100;
        } //构造了一个可以比较大小的转化方法
        if (A < B)
        {
            return 1
        };
        else if (A == B)
        {
            throw(ERROR !);
        }
        else
            return 0;
    }
    string toStr()
    {
        string temp;
        vector<Word> interator i;
        for (i = pos.begin(); i != pos.end(); i++)
        {
            temp += i.content;
        }
        return temp;
    };
}
