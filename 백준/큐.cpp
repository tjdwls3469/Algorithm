#include <iostream>
using namespace std;

#define MAXSIZE 10   // 큐의 크기 
// 원형 큐라서 데이터 9개 넣으려면 완충지대 포함한 10개의 공간 필요하다

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
	if ((rear + 1) % MAXSIZE == front) {    // 큐가 꽉 찼는지 확인
		cout << "큐가 꽉 찼습니다." << '\n';
		return -1;
	}
	queue[rear] = val;                    // rear가 큐의 끝 다음의 빈공간이므로 바로 저장
	rear = ++rear % MAXSIZE;             // rear를 다음 빈공간으로 변경
	return val;
}



int pop() {
	int result;
	if (front == rear) {                  // 큐가 비어 있는지 확인
		cout << "큐가 비어있습니다." << '\n';
		return (-1);
	}
	result = queue[front];    // front의 값을 가져옴
	front = ++front%MAXSIZE;   // front를 다음 데이터 요소로
	return result;
}

void print_queue() {
	int i;
	cout << "Front에서 Rear까지 출력" << '\n';
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
	cout << "pop 결과 : " << result << '\n';


	cout << '\n' << "push 3, 2, 5, 7" << '\n';
	push(3);
	push(2);
	push(5);
	push(7);
	print_queue();


	
	cout << "큐 꽉 찾니? ";
	push(3);
	print_queue();
	cout << "큐 비었니? ";
	cout << empty() << '\n';


	
	cout << "큐 초기화" << '\n';
	clear_queue();
	print_queue();


	cout << "큐 비었니? ";
	cout << empty() << '\n';
	result = pop();
	print_queue();
	cout << "pop 데이터 : " << result << '\n';

	return 0;
}