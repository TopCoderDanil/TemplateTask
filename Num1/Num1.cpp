
#include <iostream>
using namespace std;
template<typename T>
class Turn
{
public:
    int n = 0;
    T* value;
    int N;
    Turn(int N)
    {
        value = new T[N];
        this->N = N;
    }
    /*Функция добовления элемента*/
    void push(T importance)
    {
        if (n == N)
        {
            cout << "Переполнение очереди" << endl;
        }
        else
        {
            value[n] = importance;
            n++;
        }
    }
    /*Функция удаления элемента*/
    void pop()
    {
        for (int i = 0; i < n; i++)
        {
            value[i] = value[i + 1];
        }
        n--;
    }
    /*Функция вывода очереди*/
    void Show()
    {
        for (int i = 0; i < n; i++)
        {
            cout << value[i] << " ";
        }
        cout << endl;
    }
    /*Функция объеденения очередей*/
    void Union(Turn op)
    {
        T* arr = new T[N];
        for (int i = 0; i < n; i++)
        {
            arr[i] = value[i];
        }
        int y = n;
        n = n + op.n;
        N = N + op.N;
        value = new T[N];
        int j = 0;
        for (int i = y; i < n; i++)
        {
            value[i] = op.value[j];
            j++;
        }
        for (int i = 0; i < y; i++)
        {
            value[i] = arr[i];
        }
    }
};
int main()
{
    setlocale(LC_ALL, "ru");
    Turn<int> Ob(4);
    Ob.push(10);
    Ob.push(20);
    Ob.push(30);
    Ob.push(40);
    Ob.Show();
    Ob.pop();
    Ob.Show();
    Turn<int> Bob(4);
    Bob.push(300);
    Bob.push(400);
    Bob.Show();
    Bob.Union(Ob);
    Bob.Show();
}