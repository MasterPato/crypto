#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

void cifrar(string s, string k);
int check(string s);

int main(int argc, string argv[])
{
  if (argc > 2) {
    string k = check(argv[1]) ? argv[1] : NULL;
    
    if (k) {
      int j = 0;
      for (int i = 2; i < argc; i++) {
        for (int e = 0, n = strlen(argv[i]); e < n; e++) {
	  char key = isupper(k[j % strlen(k)]) ? 'A' : 'a';
	  if (isalpha(argv[i][e])) {
	    if (islower(argv[i][e])) {
	      printf("%c", 'a' + (argv[i][e] - 'a' + k[j % strlen(k)] - key) % 26);
	      j++;
	    } else {
	      printf("%c", 'A' + (argv[i][e] - 'A' + k[j % strlen(k)] - key) % 26);
	      j++;
	    }
	  } else {
	    printf("%c", argv[i][e]);
	    j--;
	  }
	}
	printf(" ");
      }
      printf("\n");
    } else {
      return 2;
    }
  } else if (argc == 2) {
    string k = check(argv[1]) ? argv[1] : NULL;

    if (k) {
      string s = GetString();

      cifrar(s, k);
      printf("\n");
    } else {
      return 2;
    }
  } else {
    printf("Usage: ./vigenere key\n");
    return 1;
  }
}

void cifrar(string s, string k)
{
  
  for (int i = 0, n = strlen(s), j = 0; i < n; i++, j++) {
    char key = isupper(k[j % strlen(k)]) ? 'A' : 'a';
    if (isalpha(s[i])) {
      if (islower(s[i])) {
	printf("%c", 'a' + (s[i] - 'a' + k[j % strlen(k)] - key) % 26);
        
      } else {
	printf("%c", 'A' + (s[i] - 'A' + k[j % strlen(k)] - key) % 26);

      }
    } else {
      printf("%c", s[i]);
      j--;
    }
  }
  printf(" ");
}

int check(string s)
{
  for (int i = 0, n = strlen(s); i < n; i++) {
    if (isalpha(s[i])) {
      continue;
    } else {
      printf("key must be alphabetical\n");
      return FALSE;
    }
  }
  return TRUE;
}
