#include <iostream>

class MaxHeap
{
private:
    int maxLen;
    int size = 0;
    int *array;

    inline int leftChild(int i) { return 2 * i + 1; }

    inline int rightChild(int i) { return 2 * i + 2; }

    inline int parent(int i) { return (i - 1) / 2; }

    void swap(int *a, int *b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }

    // COMPLEXITY: O(n)
    void buildWithFloyd(int *arr, int arrLen)
    {
        this->maxLen = arrLen;
        this->array = arr;
        for (int i = arrLen / 2; i >= 0; i--)
        {
            heapify(i);
        }
    }

    // COMPLEXITY: O(nlogN)
    void buildStandard(int *arr, int arrLen)
    {
        this->maxLen = arrLen;
        this->array = new int[arrLen];
        for (int i = 0; i < arrLen; i++)
        {
            insert(arr[i]);
        }
    }

    // COMPLEXITY: O(logN)
    void heapify(int n)
    {
        int left = leftChild(n);
        int right = rightChild(n);
        int largest = n;

        if (left <= size && array[largest] < array[left])
        {
            largest = left;
        }
        if (right <= size && array[largest] < array[right])
        {
            largest = right;
        }

        if (largest != n)
        {
            swap(&array[n], &array[largest]);
            heapify(largest);
        }
    }

public:
    MaxHeap()
    {
        this->maxLen = 15;
        this->array = new int[maxLen];
    }

    MaxHeap(int *arr, int arrLen, bool isFloyd)
    {
        if (isFloyd)
        {
            buildWithFloyd(arr, arrLen);
        }
        else
        {
            buildStandard(arr, arrLen);
        }
    }

    inline int getMax() { return array[0]; }

    void insert(int n)
    {
        array[size] = n;
        int i = size++;
        while (i != 0 && array[parent(i)] < array[i])
        {
            swap(&array[parent(i)], &array[i]);
            i = parent(i);
        }
    }

    // COMPLEXITY: O(logN)
    int remove()
    {
        int max = array[0];
        size--;
        array[0] = array[size];
        heapify(0);
        return max;
    }

    void printHeap()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};

void excercise1And2();
void excercise3();

int main()
{
    excercise1And2();
    excercise3();
}

void excercise1And2()
{
    int array[] = {7, 5, 9, 6, 7, 8, 10, 1, 11};
    MaxHeap *heap = new MaxHeap(array, 9, false);
    heap->remove();
    heap->printHeap();
}

void excercise3()
{
    int array[] = {7, 5, 9, 6, 7, 8, 10, 1, 11};
    MaxHeap *heap = new MaxHeap(array, 9, false);
    heap->printHeap();
}
