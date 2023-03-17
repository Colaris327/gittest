#include <iostream>
#include <string>
#include <queue>
using std::string;
using std::endl;
using std::cout;

class BST;

class TreeNode
{
    private:
        TreeNode *leftchild;
        TreeNode *rightchild;
        TreeNode *parent;
        int key;
        string element;
    public:
        TreeNode(): leftchild(0), rightchild(0), parent(0), key(0), element("") {}
        TreeNode(int a, string b): leftchild(0), rightchild(0), parent(0), key(a), element(b) {}
        friend class BST;
        int GetKey() {return key;}
        string GetElement() {return element;}
};

class BST
{
    private:
        TreeNode *root;
        TreeNode * LeftMost(TreeNode *currentNode);
        TreeNode * Successor(TreeNode *currentNode);
    public:
        void Print_root() {cout << root->key << " " << root->element << endl;}
        TreeNode * Give_root() {return root;}
        BST(): root(0) {}
        TreeNode * Search(int key);
        void InsertBST(int key, string element);
        void InorderPrint();
        void Levelorder();
        void DeleteBST(int key);
        void Inorder_rec(TreeNode *current);
};

TreeNode * BST::Search(int KEY)
{
    TreeNode *current = root;
    while (current != NULL && KEY != current->key)
    {
        if (KEY < current->key)
            current = current->leftchild;
        else
            current = current->rightchild;
    }
    return current;
}

void BST::InsertBST(int key, string element)
{
    TreeNode *insertNode = new TreeNode(key, element);
    TreeNode *y = 0; // prospective parent
    TreeNode *x = 0; // pathfinder, searching for insertion point

    x = root;
    while (x != NULL) // search
    {
        y = x;
        if (insertNode->key < x->key)
            x = x->leftchild;
        else
            x = x->rightchild;
    }

    insertNode->parent = y;
    if (y == NULL)
        this->root = insertNode;
    else if (insertNode->key < y->key)
        y->leftchild = insertNode;
    else
        y->rightchild = insertNode;
}

// TreeNode * BST::LeftMost(TreeNode *current)
// {
//     TreeNode *temp = current;
//     while (temp->leftchild != NULL)
//         temp = temp->leftchild;
//     return temp;
// }

TreeNode * BST::LeftMost(TreeNode *current)
{
    while (current->leftchild != NULL)
        current = current->leftchild;
    return current;
}

TreeNode * BST::Successor(TreeNode *current)
{
    if (current->rightchild != NULL)
        return LeftMost(current->rightchild);

    TreeNode *newNode = current->parent;
    while (newNode != NULL && current == newNode->rightchild)
    {
        current = newNode;
        newNode = newNode->parent;
    }
    return newNode;
}

void BST::InorderPrint()
{
    TreeNode *current = LeftMost(root);
    while (current)
    {
        cout << current->element << "(" << current->key << ") ";
        current = Successor(current);
    }
}

void BST::Inorder_rec(TreeNode *current)
{
    if (current == nullptr)
        return;
    Inorder_rec(current->leftchild);
    cout << current->element << '(' << current->key << ')' << ' ';
    Inorder_rec(current->rightchild);
}

void BST::Levelorder()
{
    std::queue<TreeNode *> q;
    q.push(this->root);

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        cout << current->element << "(" << current->key << ") ";

        if (current->leftchild != NULL)
            q.push(current->leftchild);
        if(current->rightchild != NULL)
            q.push(current->rightchild);
    }
}

void BST::DeleteBST(int KEY)
{
    TreeNode *deleteNode = Search(KEY);
    if (deleteNode == NULL)
    {
        cout << "data not found.\n";
        return;
    }

    TreeNode *y = 0; // deleted node
    TreeNode *x = 0; // deleted node's child

    if (deleteNode->leftchild == NULL || deleteNode->rightchild == NULL)
        y = deleteNode;
    else
        y = Successor(deleteNode);

    if (y->leftchild != NULL)
        x = y->leftchild;
    else
        x = y->rightchild; // may be NULL

    if (x != NULL)
        x->parent = y->parent; // before delete y, link x to BST
    
    if (y->parent == NULL) // if we delete root
        this->root = x;
    else if (y == y->parent->leftchild)
        y->parent->leftchild = x;
    else
        y->parent->rightchild = x;

    if (y != deleteNode) // case 3, we copy the deleted node's successor's data to deleted node
    {                   // and then delete deleted node's successor
        deleteNode->key = y->key;
        deleteNode->element = y->element;
    }

    delete y;
    y = 0;
}

int main()
{
    BST tree;
    tree.InsertBST(12, "candy");
    tree.InsertBST(10, "test");
    tree.InsertBST(30, "orange");
    tree.InsertBST(20, "apple");
    tree.InorderPrint();
    cout << endl;
    tree.InorderPrint();
    cout << endl;
    tree.Print_root();
    cout << endl;
    tree.Inorder_rec(tree.Give_root());
    return 0;
}