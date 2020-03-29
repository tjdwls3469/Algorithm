#include <iostream>
using namespace std;

#define MAXSIZE 10   // ť�� ũ�� 
// ���� ť�� ������ 9�� �������� �������� ������ 10���� ���� �ʿ��ϴ�

int queue[MAXSIZE];
int front, rear;

void init_queue() {
	front = rear = 0;
}

void clear_queue() {
	front = rear;
}

bool empty() {
	return front == rear;
}

int push(int val) {
	if ((rear + 1) % MAXSIZE == front) {    // ť�� �� á���� Ȯ��
		cout << "ť�� �� á���ϴ�." << '\n';
		return -1;
	}
	queue[rear] = val;                    // rear�� ť�� �� ������ ������̹Ƿ� �ٷ� ����
	rear = ++rear % MAXSIZE;             // rear�� ���� ��������� ����
	return val;
}



int pop() {
	int result;
	if (front == rear) {                  // ť�� ��� �ִ��� Ȯ��
		cout << "ť�� ����ֽ��ϴ�." << '\n';
		return (-1);
	}
	result = queue[front];    // front�� ���� ������
	front = ++front%MAXSIZE;   // front�� ���� ������ ��ҷ�
	return result;
}

void print_queue() {
	int i;
	cout << "Front���� Rear���� ���" << '\n';
	for (i = front; i != rear; i = ++i%MAXSIZE) {
		cout << queue[i] << ' ';
	}
	cout << '\n';
}

int main() {
	init_queue();
	printf("push 5, 4, 7, 8, 2, 1");
	cout << '\n';
	push(5);
	push(4);
	push(7);
	push(8);
	push(2);
	push(1);
	print_queue();


	cout << '\n' << "pop" << '\n';
	int result;
	result = pop();
	print_queue();
	cout << "pop ��� : " << result << '\n';


	cout << '\n' << "push 3, 2, 5, 7" << '\n';
	push(3);
	push(2);
	push(5);
	push(7);
	print_queue();


	
	cout << "ť �� ã��? ";
	push(3);
	print_queue();
	cout << "ť �����? ";
	cout << empty() << '\n';


	
	cout << "ť �ʱ�ȭ" << '\n';
	clear_queue();
	print_queue();


	cout << "ť �����? ";
	cout << empty() << '\n';
	result = pop();
	print_queue();
	cout << "pop ������ : " << result << '\n';

	return 0;
}