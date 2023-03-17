#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

class Te
{
        
    public:
        int x = 1;
        void pri() {cout << x << endl;}
        virtual void tes() {cout << 10 + x << endl;}
        virtual void TTes() = 0;
        
};

class De : public Te
{
    public:
        void PP() {x = 10;}
        virtual void TTes() {cout << 20 + x << endl;}
        // virtual void tes() {cout << "go\n";}
        void pri() {cout << "good\n";}
};

int main()
{   
    // 整數跟字元讀取混用
    // int temp;
    // cin >> temp;
    // cout << temp << endl;
    // // string str;
    // // getline(cin, str, '\n');
    // // cout << str;
    // char ch;
    // // cin >> ch;
    // cin.get(ch);
    // cout << ch << endl;
    // cin >> temp;
    // cout << endl << temp;

    // 讀檔
    // ifstream inp ("input.txt");
    // int num, sum = 0;
    // while (inp >> num)
    // {
    //     sum += num;
    //     cout << num << endl;
    // }
    // cout << sum << endl;
    // inp.close();

    // 讀一排整數直到換行
    // int temp;
    // while (cin >> temp)
    // {
    //     cout << temp << ' ';
    //     char c;
    //     cin.get(c);
    //     if (c == '\n')
    //         break;
    // }

    // De D;
    // D.PP();
    // D.tes();
    // D.pri();
    // return 0;

    int A = 248419, B = 41537;
    int temp;
    while (B != 0)
    {
        temp = A % B;
        A = B;
        B = temp;
        cout << A << ' ' << B << endl;
    }
    cout << A;
}