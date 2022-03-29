#include "passage.h" 
#include "row.h"
void Passage::sortRow()
{
    std::sort(rows.begin(), rows.end(), [](Row a, Row&b) -> bool{ return (a <&b); });
}//这里不对称但是不知道该怎么办 

void input(std::string)
{ //锟剿达拷锟矫碉拷锟斤拷锟侥硷拷锟斤拷,锟斤拷锟截革拷锟皆硷拷

    std::string line;
    if ((fp = fopen(filename, "r")) == NULL)
    {
        throw("ERROR");
    }
    
    else while (getline(fp, line))
    { //锟斤拷锟斤拷锟斤拷锟斤拷锟接诧拷知锟斤拷锟杰诧拷锟斤拷锟斤拷锟斤拷qwq
        string tmp;
        Text t;
        tmp = strok(line, " "); // strok 锟斤拷锟秸空革拷挚锟�
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
