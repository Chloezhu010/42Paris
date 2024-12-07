# 42 Paris
## Piscine
<details>
<summary>Shell & C00 - C08</summary>

### Shell00
- echo
- file attributes
- SSH key
- midLS
- git commit
- gitignore
- diff
- clean

### Shell01
- print_groups
- find_sh
- count_files
- MAC
- create file name with \/"?*
- skip
- r_dwssap
- add_chelou

### C00 (print)
- ft_putchar
- ft_print_alphabet
- ft_print_reverse_alphabet
- ft_print_numbers
- ft_is_negative
- ft_print_comb
- ft_print_comb2
- ft_putnbr
- ft_print_combn

### C01 (pointer)
- ft_ft
- ft_ultimate_ft
- ft_swap
- ft_div_mod
- ft_ultimate_div_mod
- ft_putstr
- ft_strlen
- ft_rev_int_tab
- ft_sort_int_tab

### C02 (ascii)
- ft_strcpy
- ft_strncpy
- ft_str_is_alpha
- ft_str_is_numeric
- ft_str_is_lowercase
- ft_str_is_uppercase
- ft_str_is_printable
- ft_strupcase
- ft_strlowcase
- ft_strcapitalize
- ft_strlcpy
- ft_putstr_non_printable
- ft_print_memory

### C03 (string)
- ft_strcmp
- ft_strncmp
- ft_strcat
- ft_strncat
- ft_strstr
- ft_strlcat

### C04 (char <> nbr convert)
- ft_strlen
- ft_putstr
- ft_putnbr
- ft_atoi
- ft_putnbr_base
- ft_atoi_base

### C05 (maths)
- ft_iterative_factorial
- ft_recursive_factorial
- ft_iterative_power
- ft_recursive_power
- ft_fibonacci
- ft_sqrt
- ft_is_prime
- ft_find_next_prime
- ft_ten_queens_puzzle

### C06 (argc, argv)
- ft_print_program_name
- ft_print_params
- ft_rev_params
- ft_sort_params

### C07 (malloc)
- ft_strdup
- ft_range
- ft_ultimate_range
- ft_strjoin
- ft_convert_base
- ft_split

### C08 (header file)
- ft.h
- ft_boolean.h
- ft_abs.h
- ft_point.h
- ft_strs_to_tab
- ft_show_tab

</details>

## Libft
<details>

</details>

## ft_printf
<details>

- Description
  - Recreate the function printf() in C
- Functions allowed to use
  - malloc, free, write, va_start, va_arg, va_copy, va_end
- Resources
  - Build a mini printf: https://www.youtube.com/watch?v=byRw36Y3Hjs
  - Explanation on variadic functions: https://www.youtube.com/watch?v=7Sph8JlRo0g
  - Build a printf part 1 format parser: https://www.youtube.com/watch?v=kM-DOhKR080
  - Build a printf part 2 render chars & strings: https://www.youtube.com/watch?v=7Cpqc6I9E9M
  - Build a printf part 3 render int & binary extra feature: https://www.youtube.com/watch?v=WPiZ9rZBllk
- my_prinf.c
  - Good starting point to understand what it takes to recreate the printf function
- File structure
  - Header file
    - ft_printf.h
  - Source file
    - ft_printf.c: main function
    - ft_word.c: helper function, to print char, string, % sign, normal word
    - ft_num.c: helper function, to print decimal, integer, unsigned int, hexadecimal, pointer
  - Makefile

</details>
