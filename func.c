#include <stdio.h>
#include <string.h>
#if 0
struct mime_handler {
	void (*input)(int n);
};

int n = 0;
extern struct mime_handler mime_handlers[];
void func1(int n);
void func2(int n);
void func3(int n);
void func4(int n);
void func5(int n);

struct mime_handler mime_handlers[] = {
	{ func1},
	{ func2},
	{ func3},
	{ func4},
	{ func5},
	{ NULL}
};

void func1(int n) {
	printf("%s:%d\n", __FUNCTION__,n);
}

void func2(int n) {
	printf("%s:%d\n", __FUNCTION__,n);
}

void func3(int n) {
	printf("%s:%d\n", __FUNCTION__,n);
}

void func4(int n) {
	printf("%s:%d\n", __FUNCTION__,n);
}

void func5(int n) {
	printf("%s:%d\n", __FUNCTION__,n);
}


int main(int argc, char **argv)
{
	printf("%s:%d\n", __FUNCTION__, atoi(argv[1]));
	n = atoi(argv[1]);
	mime_handlers[n].input(n);

}
#endif
struct mime_handler {
	int value;
	void (*input)(int n);
};

int n = 0;
extern struct mime_handler mime_handlers[];
void func1(int n);
void func2(int n);
void func3(int n);
void func4(int n);
void func5(int n);

struct mime_handler mime_handlers[] = {
	{ 33, func1},
	{ 67, func2},
	{ 324, func3},
	{ 231, func4},
	{ 687, func5},
	{ 0, NULL}
};

void func1(int n) {
	printf("%s:%d\n", __FUNCTION__,n);
}

void func2(int n) {
	printf("%s:%d\n", __FUNCTION__,n);
}

void func3(int n) {
	printf("%s:%d\n", __FUNCTION__,n);
}

void func4(int n) {
	printf("%s:%d\n", __FUNCTION__,n);
}

void func5(int n) {
	printf("%s:%d\n", __FUNCTION__,n);
}


int main(int argc, char **argv)
{
	struct mime_handler *handler;
	printf("%s:%d\n", __FUNCTION__, atoi(argv[1]));
	n = atoi(argv[1]);
	for (handler = &mime_handlers[0]; handler->value; handler++) {
		printf("%s n = %d,  handler->value = %d\n", __FUNCTION__,  n, handler->value);
		if (handler->value == n)
				handler->input(n);
	}

}

