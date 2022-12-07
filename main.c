#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


//############--sample file--###########

//this is a test
//file 1233454

/*
first read the file based on buffer_size until i encounter a newline or null 
(BUFFER_size=7)
1st read = "this is" 
2nd read = " a test" 
3rd read = "\nfile 1"
Joining => this is a test\nfile 1\0
current line => "this is a test\n"
next line (saved for next func call) => "file 1\0"
*/
int main()
{
	int fd = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	char *str = get_next_line(fd);
	char *str2 = get_next_line(123);
	if (!str)
		printf("%s", str);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);

	if (!str2)
		printf("%s", str2);
	while (str2)
	{
		printf("%s", str2);
		free(str2);
		str2 = get_next_line(123);
	}
	free(str2);
	return (0);
}