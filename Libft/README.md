# LIBFT

:books: [Introduction](#introduction)

:ledger:[Little man](#little-man)

## INTRODUCTION
The Libft proyect aims to create your very own first library with usuful functions that will be used in future proyects. All this `libc` functions have been re-coded as defined in their man so they have the same prototype and behaviors as the originals.

## LITTLE MAN
|About... | Function | Description |
|:-------:|:--------:|:-----------:|
|int|`f_isdigit`|Checks if the given character is numeric: `0123456789`|
|int|`ft_itoa`|Converts integer to string|
|int|`ft_putnbr_fd`|Outputs a int to the given file descriptor|
|char|`ft_isalpha`|Checks if the given character is an alphabetic character `ABCDEFGHIJKLMNOPQRSTUVWXYZ`/`abcdefghijklmnopqrstuvwxyz`|
|char|`ft_isalnum`|*ft_isdigit* or *ft_isalpha*|
|char|`ft_isascii`|Check if the given character is in the ASCII table|
|char|`ft_isprint`|Check if the given character is printable or not|
|char|`ft_toupper`|Converts the given character to uppercase|
|char|`ft_tolower`|Converts the given character to lowercase|
|char|`ft_putchar_fd`|Outputs a char to the given file descriptor|
|str|`ft_strlen`|Returns the length of the givel null-terminated string|
|str|`ft_strlcpy`|Copies up to n-1 characters from a null-terminated string to another, null-terminatinf the result|
|str|`ft_strlcat`|Appends a null-terminated string to the end of another|
|str|`ft_strchr`|Finds the first occurrence of a character in the null-terminated string pointed to by a pointer|
|str|`ft_strrchr`|Finds the last occurrence of a character in the null-terminated string pointed to by a pointer|
|str|`ft_strncmp`|Compares at most n characters of two null-terminated strings|
|str|`ft_strnstr`|Locates the first ocurrence of a null-terminated string in another string where no more than n characters are searched|
|str|`ft_atoi`|Converts a string to a integer|
|str|`ft_strdup`|Allocates sufficient memory for a copy of a string|
|str|`ft_substr`|Returns the substring of the given string at a start position with the given length|
|str|`ft_strjoin`|Combines strings and puts the result into a dynamically allocated string|
|str|`ft_strtrim`|Removes all writespaces characters from the beginning and the end of a string|
|str|`ft_split`|Splits a string into substrings according to a given delimiter|
|str|`ft_strmapi`|Applies a function to every character of a string|
|str|`ft_putstr_fd`|Outputs a string to the given file descriptor|
|str|`ft_putendl_fd`|Outputs a string to the given file descriptor followed by a '\n'|
|memory|`ft_memset`|Copies a character into each of the first n characters of a void * |
|memory|`ft_bzero`|Erases the data in the n bytes of the memory starting at the location pointed to by a void * by writing zeros('\0')|
|memory|`ft_memcpy`|Copies n characters from a void * to another void * |
|memory|`ft_memmove`|Copies n characters from a void * to another void * , overlap may happen |
|memory|`ft_memchr`|Finds the first ocurrence of a character in the initial n characters of a void * |
|memory|`ft_memcmp`|Compares lexicographically the first n characters of two const void * |
|memory|`ft_calloc`|Allocates enough space for n objects that are size bytes of memory each, then the allocated memory is filled with bytes of value zero|
```
typedef	struct	s_list
{
	void		*content;
	struct	s_list	*next;
}			t_list;
```

|About... | Function | Description |
|:-------:|:--------:|:-----------:|
|list|`ft_lstnew`|Allocates a 'fresh' link|
|list|`ft_lstadd_front`|Adds a new link at the beginning of the linked list|
|list|`ft_lstsize`|Counts the numbers of links of a list|
|list|`ft_lstlast`|Returns the last link of a list|
|list|`ft_lstadd_back`|Adds a new link at the end of the linked list|
|list|`ft_lstdelone`|Frees the memory of the link's content using the function given as a parameter, then frees the link's memory using free|
|list|`ft_lstclear`|Eliminates and free each link of the list using the given funcion and free|
|list|`ft_lstiter`|Applies a given function to every link in the list|
|list|`ft_lstmap`|Applies *ft_lstiter* to a copy of the list|


