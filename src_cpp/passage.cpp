#include <passage.h>
sortRow()
{
    std::sort(rows.begin(), rows.end(), [](Row *a, Row *b) -> bool
              { return (*a < *b); });
}
void input(FILE *fp)
{ //�˴��õ����ļ���,���ظ��Լ�
    if ((fp = fopen(filename, "r")) == NULL)
    {
        throw("ERROR");
    }
    string line;
    else while (getline(fp, line))
    { //���������Ӳ�֪���ܲ�������qwq
        string tmp;
        Text t;
        tmp = strok(line, " "); // strok ���տո�ֿￄ1�7
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
