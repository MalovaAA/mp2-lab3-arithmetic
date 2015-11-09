#ifndef STACK_H
#define STACK_H

#include <cassert> // ��� assert
#include <iostream>

#include <iomanip> // ��� setw

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
	void printStack();         // ����� ����� �� �����
	int getStackSize() const;  // �������� ������ �����
	bool IsEmpty(void);         //����?
	bool IsFull(void);          //�����?
	int getTop() const;        // �������� ����� �������� �������� � �����
};

// ���������� ������� ������� ������ STack

// ����������� �����
template <typename T>
Stack<T>::Stack(int _size,int _top) 
{	size = _size; // ������������� ���������

	stackPtr = new T[size]; // �������� ������ ��� ����
	top = _top; // �������������� ������� ������� �����;
	for (int i = 0; i < size; i++)
		stackPtr[i] = T();
}

// ����������� �����������
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) 
{
	size = otherStack.size;// ������������� ���������
	stackPtr = new T[size]; // �������� ������ ��� ����� ����
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
	assert(top < size); // ����� �������� �������� ������ ���� ������ ������� �����

	stackPtr[top++] = value; // �������� ������� � ����
}

// ������� �������� �������� �� �����
template <typename T>
 T Stack<T>::pop()
{
	// ��������� ������ �����
	assert(top > 0); // ����� �������� �������� ������ ���� ������ 0
		top--;
	T temp = stackPtr[top];
	stackPtr[top] = T();
	return temp;// ������� ������� �� �����
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
	 if (top + 1 == size)
		 return true;
	 else
		 return false;
 }

 template <class T>
 bool Stack<T>::IsEmpty(void)
 {
	 if (top == NULL)
		 return true;
	 else
		 return false;
 }
#endif // STACK_H
