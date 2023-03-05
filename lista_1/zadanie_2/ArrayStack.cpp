#include <iostream>
#include <string>
using namespace std;

template <class T>
class ArrayStack
{
public:
    int n = 0;
    int maxLen = 1;

    T *array;

    ArrayStack()
    {
        this->array = new int[maxLen];
    }

    void printStack()
    {
        for (int i = 0; i < n; i++)
        {
            cout << array[i] << " ";
        }
        cout << "[MAX LEN: " << maxLen << "]" << endl;
    }

    void push(T data)
    {
        if (n == maxLen)
        {
            resize(maxLen * 2);
        }
        this->array[n++] = data;
    }

    T pop()
    {
        if (n == 0)
        {
            return NULL;
        }
        T data = array[--n];
        if (n > 0 && n <= maxLen / 4)
        {
            resize(maxLen / 2);
        }
        return data;
    }

private:
    void resize(int newSize)
    {
        T *newArr = new T[newSize];
        for (int i = 0; i < this->n; i++)
        {
            newArr[i] = this->array[i];
        }
        delete[] this->array;
        this->array = newArr;
        this->maxLen = newSize;
    }
};

int main()
{
    string option = "";
    ArrayStack<int> *stack = new ArrayStack<int>();
    do
    {
        cin >> option;
        if (option == "/")
        {
            stack->pop();
        }
        else
        {
            int item = stoi(option);
            stack->push(item);
        }
        stack->printStack();

    } while (option != "exit");

    return 0;
}