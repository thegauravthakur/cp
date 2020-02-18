#include <bits/stdc++.h>

using namespace std;

class maxHeap {
private:
    int buffer[100]{0};
    int size{0};


public:

    void insert(int n) {
        buffer[size] = n;
        int temp = size;
        while (temp > 0 && buffer[temp] > buffer[(temp - 1) / 2]) {
            swap(buffer[temp], buffer[(temp - 1) / 2]);
            temp = (temp - 1) / 2;
        }
        size++;
    }

    int top() {
        return buffer[0];
    }

    void pop() {
        buffer[0] = buffer[size - 1];
        buffer[size - 1] = -1;
        int temp = 0;
        while (buffer[temp] < max(buffer[(temp * 2) + 1], buffer[(temp * 2) + 2])) {
            swap(buffer[temp],
                 buffer[(temp * 2) + 1] > buffer[(temp * 2) + 2] ? buffer[(temp * 2) + 1] : buffer[(temp * 2) + 2]);
            temp = buffer[(temp * 2) + 1] > buffer[(temp * 2) + 2] ? (temp * 2) + 1 : (temp * 2) + 2;
        }
        size--;
    }

    bool isEmpty() {
        return size == 0;
    }

};

int main() {
    maxHeap heap;
    heap.insert(1);
    heap.insert(2);
    heap.insert(4);
    heap.insert(5);
    heap.insert(6);
    while (!heap.isEmpty()) {
        cout << heap.top() << endl;
        heap.pop();
    }
}
