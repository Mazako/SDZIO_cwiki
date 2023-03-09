#include <iostream>
#include <string>
using namespace std;

template <class T>
class ArrayQueue
{
public:
    void push(T data)
    {
        if (N == maxLen)
        {
            resize(N * 2);
        }
        array[lastIndex++] = data;
        if (lastIndex == maxLen)
        {
            lastIndex = 0;
        }
        N++;
    }

    T *pop()
    {
        if (N == 0)
        {
            return nullptr;
        }
        T *data = &array[firstIndex++];
        N--;
        if (firstIndex == maxLen)
        {
            firstIndex = 0;
        }
        if (N > 0 && N <= maxLen / 4)
        {
            resize(maxLen / 2);
        }
        return data;
    }

    void printQueue()
    {
        for (int i = 0; i < N; i++)
        {
            cout << array[(i + firstIndex) % maxLen] << " ";
        }
        cout << endl;
    }

private:
    T *array = new T[1];
    int N = 0;
    int firstIndex = 0;
    int lastIndex = 0;
    int maxLen = 1;
    void resize(int newLen)
    {
        T *newArray = new T[newLen];
        for (int i = 0; i < N; i++)
        {
            newArray[i] = array[(firstIndex + i) % maxLen];
        }
        delete[] array;
        array = newArray;
        firstIndex = 0;
        lastIndex = N;
        maxLen = newLen;
    }
};

int main()
{
    ArrayQueue<string> *queue = new ArrayQueue<string>();
    string msg = "";
    do
    {
        cin >> msg;
        if (msg == "/")
        {
            queue->pop();
        }
        else
        {
            queue->push(msg);
        }
        queue->printQueue();
    } while (msg != "exit");
}