#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 100
typedef struct stack1{
	int top;
	int data[MAXLEN];
}SZ;
typedef struct stack2 {
	int top;
	char op[MAXLEN];
}FH;
void initSHUZI(SZ s1) {
	s1.top = -1;
}
void initFUHAO(FH s2) {
	s2.top = -1;
}
void pushSHUZI(SZ s1, int x) {
	
	s1.data[++s1.top] = x;
}
void pushFUHAO(FH s2, char y) {
	
	s2.op[++s2.top] = y;
}
int popSHUZI(SZ s1) {
	return s1.data[s1.top--];
}

char popFUHAO(FH s2) {
	return s2.op[s2.top--];
}
//

int main() {
	SZ s1;
	FH s2;
	s1.top = -1;
	s2.top = -1;
	initSHUZI(s1);
	initFUHAO(s2);
	
	int N, x;
	char op;
	scanf("%d",&N);
	for (int i = 0; i < N; i++) 
	{
		scanf("%d",&x);
		pushSHUZI(s1,x);
	}
	for (int i = 0; i < N - 1; i++) {
		scanf("%c",&op);
		pushFUHAO(s2,op);
	}
	//printf("%d",s1.top);
	while(s1.top>=-1){
		char c = popFUHAO(s2);
		int end, a, b;
		a = popSHUZI(s1);
		b = popSHUZI(s1);
		//printf("nihao");
		if (c == '+') 
			end = b + a;
		else if (c == '-') 
			end = b - a;
		else if (c == '/') {
			if (a == 0) {
				printf("ERROR: %d/0", b);
				return -1;
			}
			else {
				end = b / a;
			}
		}
		else
			end = b * a;
		if (s2.top == -1) {
			printf("%d",end);
			return -1;
		}
		else {
			pushSHUZI(s1, end);
		}

	}

	return 0;
}
