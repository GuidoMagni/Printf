This project has been created as part of the 42 curriculum by gumagni.

## Description

ft_printf is a reimplementation of the standard C library function `printf()`. The goal of this project is to understand variadic functions, format string parsing, and output formatting while recreating one of the most widely used functions in C programming. This project teaches fundamental concepts about type conversion, buffer management, and handling multiple argument types dynamically.

The function must handle various conversion specifiers and produce output identical to the original `printf()` for the implemented conversions.

## Instructions

### Compilation

The project includes a Makefile with the following rules:

```bash
make        # Compiles the library
make clean  # Removes object files
make fclean # Removes object files and the library
make re     # Recompiles the entire project
```

### Usage

Include the header in your C file:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
gcc your_file.c libftprintf.a -o your_program
```

### Function Prototype

```c
int ft_printf(const char *format, ...);
```

### Supported Conversions

- `%c` - Print a single character
- `%s` - Print a string
- `%p` - Print a pointer address in hexadecimal format
- `%d` - Print a decimal (base 10) number
- `%i` - Print an integer in base 10
- `%u` - Print an unsigned decimal number
- `%x` - Print a number in hexadecimal (lowercase)
- `%X` - Print a number in hexadecimal (uppercase)
- `%%` - Print a percent sign

### Return Value

The function returns the total number of characters printed, or -1 on error (matching the behavior of the original `printf()`).

## Algorithm and Data Structure

### Parsing Strategy

The implementation uses a **sequential parser** that iterates through the format string character by character. When a `%` is encountered, the parser identifies the conversion specifier and dispatches to the appropriate handler function.

**Why this approach:**
- Simple and efficient for single-pass parsing
- Minimal memory overhead (no need to build an intermediate representation)
- Easy to extend with new conversion specifiers
- Matches the linear nature of format strings

### Dispatcher Function Strategy

The implementation uses a **dispatcher function** (`ft_symbol`) that uses conditional statements (if-else chain) to identify the conversion specifier and call the appropriate handler function.

**Justification:**
- Simple and straightforward implementation
- No additional memory overhead for lookup tables
- Easy to understand and debug
- Sufficient performance for the limited number of conversions (9 cases)
- Direct mapping between specifier character and handler function

### Memory Management

No dynamic memory allocation is used. All output is written directly using `write()` system call, avoiding the overhead and potential failures of malloc/free operations. This design choice ensures:
- Predictable performance
- No memory leaks
- Simpler error handling
- Better suited for systems programming contexts

### Main Loop Structure

The main function (`ft_printf`) uses a **sequential scanning approach**:
1. Iterate through the format string character by character
2. When `%` is encountered, check if there's a next character
3. Call the dispatcher function with the conversion specifier
4. Skip both `%` and the specifier (advance by 2)
5. For regular characters, write directly to stdout

This approach handles the format string in a single pass with O(n) complexity, where n is the length of the format string.

### Variadic Arguments Handling

The implementation uses `<stdarg.h>` macros:
- `va_start()` - Initialize argument list
- `va_arg()` - Retrieve next argument with proper type
- `va_end()` - Clean up argument list

Each conversion handler extracts the appropriate type from the argument list and formats it accordingly.

### Helper Functions Architecture

The implementation delegates actual formatting to specialized helper functions:
- `ft_pint()` - Handles signed integers (`%d`, `%i`)
- `ft_pchar()` - Handles single characters (`%c`, `%%`)
- `ft_pstring()` - Handles strings (`%s`)
- `ft_pu()` - Handles unsigned integers (`%u`)
- `ft_phexa()` - Handles lowercase hexadecimal (`%x`)
- `ft_phexa_upper()` - Handles uppercase hexadecimal (`%X`)
- `ft_pptr()` - Handles pointer addresses (`%p`)

Each helper function returns the number of characters printed, which are accumulated in the main counter. This modular design separates concerns and makes each conversion handler independently testable.

## Resources

### Documentation
- [printf man page](https://man7.org/linux/man-pages/man3/printf.3.html) - Official documentation for printf
- [C Variadic Functions](https://en.cppreference.com/w/c/variadic) - Reference for stdarg.h macros
- [ASCII Table](https://www.asciitable.com/) - Character encoding reference

### Articles & Tutorials
- [How printf works](https://www.cypress.com/file/54441/download) - Technical deep-dive into printf internals
- [Variadic Functions in C](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html) - GNU C Library documentation

### AI Usage

AI assistance was used for the following tasks:

- **Code review and debugging**: Identifying edge cases in pointer formatting and unsigned integer handling
- **Documentation generation**: Creating clear explanations of algorithmic choices
- **README structure**: Organizing project documentation according to 42 requirements
- **Testing strategy**: Generating comprehensive test cases for various format combinations

AI was **not** used for writing the core implementation logic, algorithm design, or solving the fundamental programming challenges of the project.