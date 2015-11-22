#ifndef STACK_H
#define STACK_H


#include <iostream>


template <typename T>
class Stack
{
private:
	T *stackPtr;                      // ��������� �� ����
	int size;                   // ������������ ���������� ��������� � �����
	int top;                          // ����� �������� �������� �����
public:
	Stack(int _size = 10, int _top = 0);                  // �� ��������� ������ ����� ����� 10 ���������
	Stack(const Stack<T> &);          // ����������� �����������
	~Stack();                         // ����������

	void push(const T &);     // ��������� ������� � ������� �����
	T pop();                   // ������� ������� �� ������� ����� � ������� ���
	int Peek() ;
	void printStack();         // ����� ����� �� �����
	int getStackSize() const;  // �������� ������ �����
	bool IsEmpty(void);         //����?
	bool IsFull(void);          //�����?
	int getTop() const;        // �������� ����� �������� �������� � �����
	Stack<T>& operator=(const Stack& s);//�������� �����
	bool operator!=(const Stack<T> &s) const ;//��������� 1
	bool operator==(const Stack<T> &s) const ;//��������� 1
	void SetSize(int n);//��������� �������

};

// ���������� ������� ������� ������ STack

// ����������� �����
template <typename T>
Stack<T>::Stack(int _size,int _top) 
{	size = _size; 

	stackPtr = new T[size]; 
	top = _top; // �������������� ������� ������� �����;
	for (int i = 0; i < size; i++)
		stackPtr[i] = T();
}

// ����������� �����������
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) 
{
	size = otherStack.size;
	stackPtr = new T[size]; 
	top = otherStack.top;
	for (int i = 0; i < size; i++)
		stackPtr[i] = T();
	for (int i= 0; i < top; i++)
		stackPtr[i] = otherStack.stackPtr[i];
}

// ������� ����������� �����
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr; // ������� ����
}

// ������� ���������� �������� � ����
template <typename T>
void Stack<T>::push(const T &value)
{
	// ��������� ������ �����
	if (top >= size) // ����� �������� �������� ������ ���� ������ ������� �����
		throw ("stek zapolnen");

	stackPtr[top++] = value; // �������� ������� � ����
}

// ������� �������� �������� �� �����
template <typename T>
 T Stack<T>::pop()
{
	// ��������� ������ �����
	if (top <= 0)
	throw ("stek pust");// ����� �������� �������� ������ ���� ������ 0
		top--;
	T temp = stackPtr[top];
	stackPtr[top] = T();
	return temp;// ������� ������� �� �����
}
template <typename T>
 int Stack<T>::Peek()
{
	if (top == 0)
	{
		throw ("stek pust!");
	}
	return stackPtr[top-1];
}


// ����� ����� �� �����
template <typename T>
 void Stack<T>::printStack()
{
	for (int i = top-1; i >=0; i--)
		cout << "| "	<<stackPtr[i]<<endl;
}

// ������� ������ �����
template <typename T>
 int Stack<T>::getStackSize() const
{
	return size;
}

// ������� ����� �������
template <typename T>
 int Stack<T>::getTop() const
{
	return top;
}

 template <class T>
 bool Stack<T>::IsFull(void)
 {
	 if (top == size)
		 return true;
	 else
		 return false;
 }

 template <class T>
 bool Stack<T>::IsEmpty(void)
 {
	 if (top == 0)
		 return true;
	 else
		 return false;
 }
  template <class T>
 Stack<T>& Stack<T>::operator=(const Stack& s)
{
	if (stackPtr == s.stackPtr)
	{
		return *this;
	}
	size = s.size;
	top = s.top;
	delete[]stackPtr;
	stackPtr = new int[size];
	for (int i = 0; i < size; i++)
	{
		stackPtr[i] = s.stackPtr[i];
	}
	return *this;
}
  template <class T>

bool Stack<T>::operator==(const Stack<T>& s) const
{
	if ((size == s.size)&&(top == s.top))
	{
		for (int i = 0; i < size; i++)
		{
			if (stackPtr[i] != s.stackPtr[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
 template <class T>
bool Stack<T>::operator!=(const Stack<T> &s) const 
{
	if ((*this)==s)
	{
		return false;
	}
	return true;
}
 template <class T>
void Stack<T>::SetSize(int n)
{
	if (n<0) 
	{
		throw ("new size < 0");
	}
	if (n<top)
	{
		throw ("new size < Top");
	}

	int *p = new int[top];
	for (int i = 0; i < top; i++)
	{
		p[i] = stackPtr[i];
	}

	size = n;
	delete []stackPtr;
	stackPtr = new int[size];
	for (int i = 0; i < top; i++)
	{
		stackPtr[i] = p[i];
	}
	for (int i = top; i < size;i++)
	{
		stackPtr[i] = 0;
	}
}
#endif // STACK_H
