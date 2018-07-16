#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

vector<string> strGiven;
queue<string> strCommand;
char* strItoa = new char[101];

void strStorage(const char* ch);
bool strProcess();
string commandOp();
string nyCopy(int n, int x, int l);
string nyAdd(string s1, string s2);
int nyFind(int n, string s);
int nyRFind(int n, string s);
void nyInsert(int n, int x, string s);
void nyReset(int n, string s);
void nyPrint(int n);
void nyPrintAll();

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        strGiven.push_back(str);
    }
    cin.get();

    char* ch = new char[501];
    while(1)
    {
        cin.getline(ch, 500, '\n');
        strStorage(ch);
        int t = strProcess();
        if (t == false)
        {
            break;
        }
    }
    delete ch;
    delete strItoa;
    return 0;
}
void strStorage(const char* ch)
{
    string str;
    for (int i = 0; ch[i] != '\0'; i++)
    {
        if (ch[i] != ' ')
        {
            str.push_back(ch[i]);
        }
        else
        {
            strCommand.push(str);
            str.clear();
        }
    }
    strCommand.push(str);
}
bool strProcess()
{
    string str = strCommand.front();
    strCommand.pop();
    if (str == "insert")
    {
        string s = commandOp();
        int n = atoi(commandOp().c_str());
        int x = atoi(commandOp().c_str());
        nyInsert(n, x, s);
    }
    else if (str == "reset")
    {
        string s = commandOp();
        int n = atoi(commandOp().c_str());
        nyReset(n, s);
    }
    else if (str == "print")
    {
        int n = atoi(commandOp().c_str());
        nyPrint(n);
    }
    else if (str == "printall")
    {
        nyPrintAll();
    }
    else if (str == "over")
    {
        return false;
    }
    return true;
}
string commandOp()
{
    string str = strCommand.front();
    strCommand.pop();
    if (str == "copy")
    {
        int n = atoi(commandOp().c_str());
        int x = atoi(commandOp().c_str());
        int l = atoi(commandOp().c_str());
        return nyCopy(n, x, l);
    }
    else if (str == "add")
    {
        string s1 = commandOp();
        string s2 = commandOp();
        return nyAdd(s1, s2);
    }
    else if (str == "find")
    {
        string s = commandOp();     
        int n = atoi(commandOp().c_str());
        sprintf(strItoa, "%d", nyFind(n, s));
        return strItoa;
    }
    else if (str == "rfind")
    {
        string s = commandOp();
        int n = atoi(commandOp().c_str());
        sprintf(strItoa, "%d", nyRFind(n, s));
        return strItoa;
    }
    else
    {
        return str;
    }

}
string nyCopy(int n, int x, int l)
{
    string str = strGiven.at(n-1);
    return str.substr(x, l);
}
string nyAdd(string s1, string s2)
{
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1.at(i) < '0' || s1.at(i) > '9')
        {
            return s1 + s2;
        }
    }
    for (int i = 0; i < s2.size(); i++)
    {
        if (s2.at(i) < '0' || s2.at(i) > '9')
        {
            return s1 + s2;
        }
    }
    long a = atoi(s1.c_str());  
    long b = atoi(s2.c_str());
    if (a >= 0 && a <= 99999 && b >= 0 && b <= 99999)
    {
        long c = a + b;
        sprintf(strItoa, "%ld", c);
        return strItoa;
    } 
    else
    {
        return s1 + s2;
    }
}
int nyFind(int n, string s)
{
    int pos = strGiven.at(n-1).find(s);
    if (pos == string::npos)
    {
        return s.size();
    }
    else
    {
        return pos;
    }
}
int nyRFind(int n, string s)
{
    int pos = strGiven.at(n-1).rfind(s);
    if (pos == string::npos)
    {
        return s.size();
    }
    else
    {
        return pos;
    }
}
void nyInsert(int n, int x, string s)
{
    strGiven.at(n-1).insert(x, s);
}
void nyReset(int n, string s)
{
    strGiven.at(n-1).swap(s);
}
void nyPrint(int n)
{
    cout << strGiven.at(n-1) << endl;
}
void nyPrintAll()
{
    for (unsigned int i = 0; i < strGiven.size(); i++)
    {
        cout << strGiven.at(i) << endl;
    }

}
