# ex00
## man strcpy
- strcpy: copy a string
- The strcpy() function copies the string pointed to by src, including the terminating
       null byte ('\0'), to the buffer pointed to by dest.  
- The strings  may  not  overlap,
       and the destination string dest must be large enough to receive the copy.  Beware of
       buffer overruns!  (See BUGS.
- return value: The  strcpy()  function  returns a pointer to the destination string
       dest.
-  A simple implementation of strncpy() might be:

           char *
           strncpy(char *dest, const char *src, size_t n)
           {
               size_t i;

               for (i = 0; i < n && src[i] != '\0'; i++)
                   dest[i] = src[i];
               for ( ; i < n; i++)
                   dest[i] = '\0';

               return dest;
           }
- Bugs
  - If  the  destination  string  of a strcpy() is not large enough, then anything might
       happen.  Overflowing fixed-length string buffers is a favorite cracker technique for
       taking  complete  control  of  the machine.  Any time a program reads or copies data
       into a buffer, the program first needs to check that there's enough space.  This may
       be unnecessary if you can show that overflow is impossible, but be careful: programs
       can get changed over time, in ways that may make the impossible possible.
  - If you pass a NULL pointer as the source argument to strcpy, it will dereference the NULL pointer, which is undefined behavior and will likely crash the program. It is an error to pass NULL for either of the parameters to strcpy
- code 
char    *ft_strcpy(char *dest, char *src)
{
  int  i;

  i = 0;

    while (src[i] != '\0')
    {  
      dest[i] = src[i];
      i++;
    }
    dest[i] = '\0';
    return (dest);
  
}oi

#include <stdio.h>
int main(void)
{
  char src[] = "42borntocode";
  char dest[] = "";
  ft_strcpy(dest, src);
  printf("Copied string: %s\n", dest);
}

# ex01
- strncpy
  - The strncpy() function is similar, except that at most n  bytes  of  src  are  copied.
       Warning: If there is no null byte among the first n bytes of src, the string placed in
       dest will not be null-terminated.
  - If the length of src is less than n, strncpy() writes additional null bytes to dest to
       ensure that a total of n bytes are written.

- difference between int and unsigned int
  - int: negative and postive int, 
  - unsigned int: only positive int, 

- code 
char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
  unsigned int i;

  i = 0;
  while ( i < n && src[i] != '\0')
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return (dest);
}

#include <stdio.h>
int     main(void)
{
        char src[] = "42borntocode";
        char dest[] = "";
        unsigned int n = 7;
        ft_strncpy(dest, src, n);
        printf("Copied string: %s\n", dest);
}

# ex02
- code 
       int ft_str_is_alpha(char *str)
  14   │ {
  15   │     int i;
  16   │ 
  17   │     i = 0;
  18   │     while (str[i] != '\0')
  19   │     {
  20   │         if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
  21   │         {
  22   │             return (0);
  23   │         }
  24   │         i++;
  25   │     }
  26   │     return (1);
  27   │ }
  28   │ /*
  29   │ #include <stdio.h>
  30   │ int main(void)
  31   │ {
  32   │     printf("%d\n", ft_str_is_alpha("abdABCEd"));
  33   │     printf("%d\n", ft_str_is_alpha("abxdsef5"));
  34   │     printf("%d\n", ft_str_is_alpha(""));
  35   │ }*/

# ex03
        int ft_str_is_numeric(char *str)
  14   │ {
  15   │     int i;
  16   │ 
  17   │     i = 0;
  18   │     while (str[i] != '\0')
  19   │     {
  20   │         if (str[i] < '0' || str[i] > '9')
  21   │         {
  22   │             return (0);
  23   │         }
  24   │         i++;
  25   │     }
  26   │     return (1);
  27   │ }
  28   │ /*
  29   │ #include <stdio.h>
  30   │ int main(void)
  31   │ {
  32   │     printf("%d\n", ft_str_is_numeric("12334236"));
  33   │     printf("%d\n", ft_str_is_numeric("1235563a"));
  34   │     printf("%d\n", ft_str_is_numeric(""));
  35   │ }*/


# ex04


# ex07



-Wall -Wextra -Werror













