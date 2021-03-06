#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void cifrar(string, int);

int main(int argc, string argv[])
{
  if (argc == 2) {
    int k = atoi(argv[1]);

    string s = GetString();

    cifrar(s, k);
    printf("\n");
  } else if (argc > 2) {
    int k = atoi(argv[1]);

    for (int i = 2; i < argc; i++) {
      cifrar(argv[i], k);
    }
    printf("\n");
  } else {
    printf("Usage: ./cipher <key> [opt]message\n");
    return 1;
  }
    
}

void cifrar(string s, int k)
{
  for (int i = 0, n = strlen(s); i < n; i++) {
    if (isalpha(s[i])) {
      if (isupper(s[i])) {
	printf("%c", 'A' + (s[i] - 'A' + k) % 26);
      } else {
	printf("%c", 'a' + (s[i] - 'a' + k) % 26);
      }
    } else {
      printf("%c", s[i]);
    }
  }
  printf(" ");
}
