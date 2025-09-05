#include <stdio.h>
char st[100000];
int top = -1;
int ok(char c)
{
  return (c == ')' && st[top] == '(') || (c == ']' && st[top] == '[') || (c == '}' && st[top] == '{');
}
int main()
{
  int ch;
  while ((ch = getchar()) != EOF && ch != '\n')
  {
    if (ch == '(' || ch == '[' || ch == '{')
      st[++top] = ch;
    else if (ch == ')' || ch == ']' || ch == '}')
    {
      if (top < 0 || !ok(ch))
      {
        puts("NO");
        return 0;
      }
      top--;
    }
  }
  puts(top == -1 ? "YES" : "NO");
}
