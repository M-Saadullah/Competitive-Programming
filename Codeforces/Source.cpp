#include<iostream>
#include<queue>
using namespace std;
template<class T>
class Queue
{
	T* data;
	int noOfElements;
	int capacity;
	int rear;
	int front;
	void reSize(int newCap)
	{
		T* arr = new T[newCap];
		int tempindex;
		for (int i = front; i < rear + noOfElements; i++)
		{
			tempindex = i % capacity;
			arr[i - front] = data[i];
		}
		int temp = noOfElements;
		this->~Queue();
		capacity = newCap;
		noOfElements = temp;
		rear = noOfElements;
		front = 0;
		data = arr;
	}
public:
	Queue();
	~Queue();
	Queue(const Queue<T>&);
	Queue<T>& operator=(const Queue<T>&);
	void enQueue(T);
	T deQueue();
	T getElementAtFront()const;
	bool isEmpty()const;
	bool isFull()const;
	int getNoOfElements() const;
	int getCapacity()const;
};
template<class T>
Queue<T>::Queue()
{
	capacity = 0;
	data = 0;
	noOfElements = rear = front = 0;
}
template<class T>
Queue<T>::~Queue()
{
	if (data)
		delete[] data;
	noOfElements = 0;
	capacity = 0;
	rear = 0;
	front = 0;
}
template<class T>
T Queue<T>::getElementAtFront()const
{
	if (!isEmpty())
		return data[front];
}
template<class T>
Queue<T>::Queue(const Queue<T>& cop)
{
	if (data == nullptr)
	{
		cop.data = nullptr;
		capacity = 0;
		noOfElements = 0;
		front = 0;
		rear = 0;
		return;
	}
	front = cop.front;
	rear = cop.rear;
	capacity = cop.capacity;
	data = new T[capacity];
	for (int i = front; i < rear; i++)
	{
		data[i] = cop.data[i];
	}

}
template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& cop)
{
	if (this == &cop)
	{
		return *this;
	}
	else
	{
		~Queue;
		front = cop.front;
		rear = cop.rear;
		capacity = cop.capacity;
		data = new T[capacity];
		for (int i = front; i < rear; i++)
		{
			data[i] = cop.data[i];
		}
	}
	return *this;
}
template<class T>
bool Queue<T>::isEmpty()const
{
	if (rear == front && noOfElements == 0)
		return true;
	else
		return false;
}
template<class T>
int Queue<T>::getNoOfElements()const
{
	return noOfElements;
}
template<class T>
int Queue<T>::getCapacity() const
{
	return capacity;
}
template<class T>
bool Queue<T>::isFull()const
{
	if (noOfElements == capacity)
		return true;
	else
		return false;

}
template<class T>
void Queue<T>::enQueue(T val)
{
	if (isFull())
	{
		if (capacity == 0)
			reSize(capacity + 1);
		else
		{
			reSize(capacity * 2);
		}
	}
	if (rear == capacity)
	{
		rear = 0;
	}
	data[rear] = val;
	noOfElements++;
	rear++;
}
template<class T>
T Queue<T>::deQueue()
{
	if (isEmpty())
		exit(0);
	if (front == capacity)
		front = 0;
	T temp = data[front];
	front = front + 1;
	noOfElements--;
	if (noOfElements > 0 && noOfElements == capacity / 4)
		reSize(capacity / 2);
	return temp;
}

template<typename T>
class ArraybianryTree
{
	int maxheight;
	int maxNode;
	T* arr;
	bool* statusArray;
	void VLR(int i)
	{
		if (i < maxNode && statusArray[i])
			cout << arr[i] << ":";
		if ((2 * i) + 1 < maxNode && statusArray[(2 * i) + 1])
			VLR((2 * i) + 1);//leftChild
		if ((2 * i) + 2 < maxNode && statusArray[(2 * i) + 2])
			VLR((2 * i) + 2);//RightChild
	}
	int search(T p, int i)
	{
		int check = -1;
		if (arr[i] == p)
			return i;
		if (check == -1 && (2 * i) + 1 < maxNode && statusArray[(2 * i) + 1])
			check = search(p, (2 * i) + 1);//leftChild
		if (check == -1 && (2 * i) + 2 < maxNode && statusArray[(2 * i) + 2])
			check = search(p, (2 * i) + 2);//RightChild
		return check;
	}
	void removeNode(int i)
	{
		if (i > maxNode && statusArray[i] == 0)
		{
			return;
		}
		if ((2 * i) + 1 < maxNode && statusArray[i])
			removeNode((2 * i) + 1);
		if ((2 * i) + 2 < maxNode && statusArray[i])
			removeNode((2 * i) + 2);
		statusArray[i] = false;
		return;
	}
public:
	ArraybianryTree(int h)
	{
		maxheight = h;
		maxNode = (1 << h) - 1;//2^h-1
		arr = new T[maxNode];
		statusArray = new bool[maxNode];
		for (int i = 0; i < maxNode; i++)
		{
			statusArray[i] = false;//0
		}
	}
	void setRoot(T p)
	{
		arr[0] = p; statusArray[0] = true;
	}
	void preOder()
	{
		VLR(0);
	}
	void setLeftChild(T p, T d)
	{
		int i = search(p, 0);
		if (i == -1)
		{
			return;
		}
		if ((2 * i) + 1 < maxNode)
			arr[(2 * i) + 1] = d;
		statusArray[(2 * i) + 1] = 1;
	}
	void setRightChild(T p, T d)
	{
		int i = search(p, 0);
		if (i == -1)
		{
			return;
		}
		if ((2 * i) + 2 < maxNode)
		{
			arr[(2 * i) + 2] = d;
			statusArray[(2 * i) + 2] = 1;
		}
	}
	void displayDescendents(T node)
	{
		int i = search(node, 0);
		if (i == -1)
		{
			return;
		}
		VLR((2 * i) + 1);
		VLR((2 * i) + 2);
	}
	T getparent(T node)
	{
		int i = search(node, 0);
		if (i == -1 || i == 0)
		{
			exit(0);
		}
		return arr[(i - 1) / 2];
	}
	int getHeight(int i)
	{
		if (!(i < maxNode && statusArray[i]))
		{
			return 0;
		}
		int l = 0, r = 0;
		if ((2 * i) + 1 < maxNode && statusArray[(2 * i) + 1])
			l = getHeight((2 * i) + 1);//leftChild
		if ((2 * i) + 2 < maxNode && statusArray[(2 * i) + 2])
			r = getHeight((2 * i) + 2);//RightChild
		if (l > r)
		{
			return l + 1;
		}
		return r + 1;
	}
	void remove(T p)
	{
		int index = search(p, 0);
		if (index == -1)
		{
			exit(0);
		}
		removeNode(index);
	}
	void displayAncestor(T node)
	{
		int i = search(node, 0);
		if (i == -1 || i == 0)
		{
			return;
		}
		i = (i - 1) / 2;
		while (i)
		{
			cout << arr[i] << ":";
			i = (i - 1) / 2;
		}
		cout << arr[i] << endl;
	}
	void displayLevel(int i)// using BFS Q
	{
		queue<int>q;
		q.push(i);
		while (!q.empty())
		{
			cout << arr[i] << " ";
			i = q.front();
			q.pop();
			if (((2 * i) + 1) < maxNode && statusArray[(2 * i) + 1])
			{
				q.push((2 * i) + 1);
			}
			if (((2 * i) + 2) < maxNode && statusArray[(2 * i) + 2])
			{
				q.push((2 * i) + 2);
			}
		}
		cout << endl;
	}
};
int main(void)
{
	ArraybianryTree<int> bt(5);
	bt.setRoot(1);
	bt.setLeftChild(1, 2);
	bt.setRightChild(1, 3);
	bt.setLeftChild(2, 4);
	bt.setRightChild(2, 5);
	bt.setLeftChild(3, 6);
	bt.setRightChild(3, 7);
	bt.setLeftChild(5, 10);
	bt.setLeftChild(10, 11);
	cout << "Tree: ";
	bt.preOder(); cout << endl;
	cout << "Parent of 11 Node: " << bt.getparent(11) << endl;
	cout << "Height of tree: " << bt.getHeight(0) << endl;
	cout << "Descendat: ";
	bt.displayDescendents(1); cout << endl;
	cout << "Ancestor: ";
	bt.displayAncestor(6);
	bt.displayLevel(0);
	/*bt.remove(2);
	cout << "Tree: ";
	bt.preOder(); cout << endl;*/


}