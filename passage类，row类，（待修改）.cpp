class Passage{
public:
list<Text> texts;
vector<row> rows; 
sortRow(){
int n=ls.size();
for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
if(ls[j]<ls[i]){
Row s=ls[j];
ls[j]=ls[i];
ls[i]=s;
}
}
}
}
input(Text){
    vector<int>temp;
    string n,m;
    p=text;
    while(p->next!=NULL){//这里假定p是空头结点
        p=p->next;
        list=p->data;//这里对p的数据域暂定为data
        do{scanf("%s",m);m.puh_back(temp)}while(scanf("%s",&n)!=EOF);
    }
}
toStr(vector<Row>ls){
vector<string>tmp;
for(int i=0;i<ls.size();i++){
Row temp=ls[i];
tmp.push_back(temp);
}
tmp=toStr(tmp);
return tmp;
}
}
class Row{
list order;
Text textPrototype;
void operator<(Row a,Row b){
int num(char s){
int n=int(s);
if('A'<=s&&s<='Z'){return 2*(n-64)}
else if('a'<=s&&s<='z'){return 2*(n-97)-1}
else{return 0};
}
str1=toStr(a);str2=toStr(b);
int A=0,B=0;
for(int i=0,i<string.length();i++){
    A+=num(str1[i]);B+=num(str2[i]);
    A*=100;B*=100;
}//构造了一个可以比较大小的转化方法
if(A<B){return 1};
else if (A==B){RaiseException(they are of the same size!);}
else return 0;
}
string toStr(Row a){
/*return std::string str(a.textPrototype.words.begin(),a.textPrototype.words.end());*/
vector<word>list=a.textPrototype.words;
vector<string>temp;
for(int i=0;i<list.size();i++){
    temp.push_back(list.words[order[i]].comtent);
}//按照order，嵌套很多，不知道对不对qwq
return std::string str(temp.begin(),temp.end());
}