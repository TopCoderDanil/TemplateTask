
#include <iostream>
using namespace std;

template<typename T>
class Turn
{
public:
    Turn()
    {
        Push(1);
    }
    Turn(T n)
    {
        Push(n);
    } 
    /*Функция внесения элемента в бинарное дерево*/
    void Push(T n)
    {
        pushPr(n, &tree);
    }
    /*Функция вывода элементов бинарного дерева*/
    void Print()
    {
        printPr(tree, 0);
    }
    /*Функция удаления элемента из бинарного дерева*/
    void Delete_element(T n)
    {
        DeleteNode(tree, n);
    }
    /*Функция просмотра листьев бинарного дерева*/
    void Leaf_output()
    {
        printLeaf(tree);
    }
    /*Функция поиска элемента в бинарном дереве*/
    void Element_search(T n)
    {
        if (find(tree, n))
            cout << "Элемент найден" << endl;
        else
        {
            cout << "Элемент не найден" << endl;
        }
        
    }
private:

    struct node
    {
        T info;
        node* l, * r;
    };

    node* tree = NULL;

    void pushPr(T a, node** t)
    {
        if ((*t) == NULL)                  
        {
            (*t) = new node;               
            (*t)->info = a;               
            (*t)->l = (*t)->r = NULL;      
            return;                        
        }   
        if (a > (*t)->info) pushPr(a, &(*t)->r);
        else pushPr(a, &(*t)->l);        
    }
    void printPr(node* t, int u)
    {
        if (t == NULL) return;                
        else
        {
            printPr(t->l, ++u);                   
            for (int i = 0; i < u; ++i) cout << "|";
            cout << t->info << endl;           
            u--;
        }
        printPr(t->r, ++u);                      
    }
    node* DeleteNode(node* value,T val) {
        if (value == NULL)
            return value;

        if (val == value->info) {

            node* tmp;
            if (value->r == NULL)
                tmp = value->l;
            else {

                node* ptr = value->r;
                if (ptr->l == NULL) {
                    ptr->l = value->l;
                    tmp = ptr;
                }
                else {

                    node* pmin = ptr->l;
                    while (pmin->l != NULL) {
                        ptr = pmin;
                        pmin = ptr->l;
                    }
                    ptr->l = pmin->r;
                    pmin->l = value->l;
                    pmin->r = value->r;
                    tmp = pmin;
                }
            }

            delete value;
            return tmp;
        }
        else if (val < value->info)
            value->l = DeleteNode(value->l, val);
        else
            value->r = DeleteNode(value->r, val);
        return value;
    }
    void printLeaf(node* t)
    {
        if ((t->l == nullptr) && (t->r == nullptr))
            cout << t->info << "\n";
        else
        {
            if (t->l) printLeaf(t->l);
            if (t->r) printLeaf(t->r);
        }
    }
    bool find(node* r, T d)
    {
        if (r == NULL)
        {
            return false;  
        }
        if (r->info == d)
        {
            return true; 
        }
        if (d <= r->info)
        {
            if (r->l != NULL)
                return find(r->l, d); 
            else
            {
                return false; 
            }
        }
        else
        {
            if (r->r)
                return find(r->r, d);
            else
            {
                return false; 
            }
        }
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Turn<int> ob(10);
    ob.Push(100);
    ob.Push(70);
    ob.Push(60);
    ob.Push(77);
    ob.Push(44);
    ob.Push(1);
    ob.Print();
    ob.Delete_element(60);
    cout << endl;
    ob.Print();
    cout << endl;
    ob.Leaf_output();
    cout << endl;
    ob.Element_search(44);
    ob.Element_search(1000);
}
