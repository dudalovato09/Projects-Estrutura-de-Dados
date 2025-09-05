#include <stdio.h>
#include <ctype.h>
typedef struct
{
	int a[6];
	int top;
} Stack;

void init(Stack *s)
{
	s->top = -1;
}

void push(Stack *s, int v)
{
	s->a[++s->top] = v;
}

int popS(Stack *s)
{
	return s->a[s->top--];
}

int main()
{
	Stack s;
	init(&s);
	int c, inNum = 0, x = 0;
	while ((c = getchar()) != EOF)
	{
		if (isdigit(c))
		{
			x = x * 10 + (c - '0');
			inNum = 1;
		}
		else
		{
			if (inNum)
			{
				push(&s, x);
				x = 0;
				inNum = 0;
			}

			if (c == ' ' || c == '\n')
				continue;

			int b = popS(&s), a = popS(&s);
			switch (c)
			{
			case '+':
				push(&s, a + b);
				break;
			case '-':
				push(&s, a - b);
				break;
			case '*':
				push(&s, a * b);
				break;
			case '/':
				push(&s, a / b);
				break;
			}
		}
	}
	if (inNum)
		push(&s, x);
	printf("%d\n", popS(&s));
}
