
class MyCircularDeque {
public:
    int *deque;
    int front, rear;
    int size, count;

    MyCircularDeque(int k) {
        size = k;
        deque = new int[size];

        front = -1;
        rear = -1;
        count = 0;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            front = (front - 1 + size) % size;
        }

        deque[front] = value;
        count++;

        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }

        deque[rear] = value;
        count++;

        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % size;
        }

        count--;

        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            rear = (rear - 1 + size) % size;
        }

        count--;

        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return deque[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }

        return deque[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }
};
