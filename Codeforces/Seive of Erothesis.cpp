#include<iostream>
using namespace std;


template<class T>
class Queue
{
	int rear;
	int front;
	int capacity;
	int noOfElements;
	T* data;
	void reSize(int);
public:
	Queue();
	~Queue();
	Queue(const Queue<T>&);
	Queue<T>& operator=(const Queue<T>&);
	void enQueue(T);
	T deQueue();
	T getElementAtFront() const;
	bool isEmpty() const;
	bool isFull() const;
	int getNoOfElements() const;
	int getCapacity() const;
};

template<class T>
Queue<T>::Queue()
{
	rear = 0;
	front = 0;
	capacity = 0;
	noOfElements = 0;
	data = nullptr;
}
template<class T>
Queue<T>::~Queue()
{
	if (data)
		delete[] data;
	noOfElements = 0;
	capacity = 0;
	front = 0;
	rear = 0;
}
template<class T>
bool Queue<T>::isEmpty() const
{
	return rear == front && noOfElements == 0;

}

template<class T>
bool Queue<T>::isFull() const
{
	return noOfElements == capacity;
}

template<class T>
int Queue<T>::getNoOfElements() const
{
	return noOfElements;
}

template<class T>
int Queue<T>::getCapacity() const
{
	return capacity;
}

template<class T>
T Queue<T>::getElementAtFront() const
{
	if (!isEmpty())
		return data[front];
}

template<class T>
void Queue<T>::enQueue(T val)
{
	if (isFull())
		reSize(capacity == 0 ? 1 : capacity * 2);
	data[rear] = val;
	rear = (rear + 1) % capacity;
	noOfElements++;
}
template<class T>
T Queue<T>::deQueue()
{
	if (isEmpty())
		exit(0);
	T temp = data[front];
	front = (front + 1) % capacity;
	noOfElements--;
	if (noOfElements > 0 && noOfElements == capacity / 4)
	{
		reSize(capacity / 2);
	}
	return temp;
}

template<class T>
void Queue<T>::reSize(int newCap)
{
	T* arr = new T[newCap];
	int temp;
	for (int i = front; i < front + noOfElements; i++)
	{
		temp = i % capacity;
		arr[i - front] = data[temp];
	}
	int tempNoOFElement = noOfElements;
	this->~Queue();
	noOfElements = tempNoOFElement;
	rear = noOfElements;
	front = 0;
	capacity = newCap;
	data = arr;
	arr = nullptr;
}

template<class T>
Queue<T>::Queue(const Queue<T>& tempQueue)
{
	if (tempQueue.data == nullptr)
	{
		data = nullptr;
		rear = 0;
		capacity = 0;
		noOfElements = 0;
		front = 0;
		return;
	}
	capacity = tempQueue.capacity;
	front = tempQueue.front;
	rear = tempQueue.rear;
	data = new T[capacity];
	for (int i = front; i < rear; i++)
	{
		data[i] = tempQueue.data[i];
	}
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& tempQueue)
{
	if (this == &tempQueue)
		return *this;
	if (tempQueue.data == nullptr)
	{
		data = nullptr;
		rear = 0;
		capacity = 0;
		noOfElements = 0;
		front = 0;
		return *this;
	}
	capacity = tempQueue.capacity;
	front = tempQueue.front;
	rear = tempQueue.rear;
	data = new T[capacity];
	for (int i = front; i < rear; i++)
	{
		data[i] = tempQueue.data[i];
	}
	return *this;
}



int main()
{
	Queue<int> q1;
	Queue<int> q2;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		q1.enQueue(i);
	}
	int size = sqrt(n);
	while (size--)
	{
		q2.enQueue(q1.getElementAtFront());
		int temp = q1.getElementAtFront();
		q1.enQueue(q1.deQueue());
		while (q1.getElementAtFront() != temp)
		{
			if (q1.getElementAtFront() % temp != 0)
				q1.enQueue(q1.deQueue());
			else
				q1.deQueue();
		}
		q1.deQueue();
	}
	while (!q1.isEmpty())
	{
		q2.enQueue(q1.deQueue());
	}
	int i = 0;
	while (!q2.isEmpty())
	{
		i++;
		cout << q2.deQueue() << " ";
	}
	cout << endl << i << endl;

}