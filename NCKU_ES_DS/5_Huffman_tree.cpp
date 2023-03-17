#include <iostream>
#include <queue>
#include <fstream>
#include <string>
using namespace std;

// ofstream wr;

class Node
{
    public:
        char key;
        unsigned freq;
        Node *leftchild = nullptr, *rightchild = nullptr;
        Node(char key, unsigned freq): key(key), freq(freq) {}
};
class cmp
{
    public:
        bool operator()(Node *A, Node *B)
        {
            return A->freq > B->freq;
        }
};

void Print_Code(Node *current, string str)
{
    if (current == nullptr)
        return;
    if (current->key != '$')
        cout << current->key << ": " << str << endl;
    else
    {
        Print_Code(current->leftchild, str + "0");
        Print_Code(current->rightchild, str + "1");
    }
}

void Huffman(char *arr, unsigned *freq_arr, int size)
{
    priority_queue<Node *, vector<Node *>, cmp> pq;
    for (int i = 0; i < size; i++)
        pq.push(new Node(arr[i], freq_arr[i]));
    Node *Left, *Right;
    while (pq.size() != 1)
    {
        Left = pq.top();
        pq.pop();
        Right = pq.top();
        pq.pop();
        Node *temp = new Node('$', Left->freq + Right->freq);
        temp->leftchild = Left;
        temp->rightchild = Right;
        pq.push(temp);
    }
    Print_Code(pq.top(), "");
}

int main()
{
    // char arr[] = {'a', 'b', 'c', 'd', 'e'};
    // unsigned freq[] = {15, 7, 6, 6, 5};
    ifstream f;
    f.open("huff.txt");
    // wr.open("huffw.txt");
    int size;
    f >> size;
    char *arr = new char[size];
    unsigned *freq = new unsigned[size];
    for (int i = 0; i < size; i++)
    {
        f >> arr[i] >> freq[i];
    }
    Huffman(arr, freq, 5);
    f.close();
    return 0;
}