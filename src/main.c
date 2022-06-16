/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:13:47 by lnicosia          #+#    #+#             */
/*   Updated: 2022/06/16 18:14:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int			ft_puts(const char *s);
size_t		ft_strlen(const char *s);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *s, int c, size_t n);
char		*ft_strcat(char *dest, const char *src);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isdigit(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_strdup(const char *s);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		ft_cat(int fd);
ssize_t		ft_write(int fd, const void* buf, size_t count);
void		ft_call_convention(int a, int b, int c, int d, int e, int f, int g, int h);
char		*ft_strcpy(char *dest, const char *src);
int			ft_strcmp(const char* s1, const char* s2);
ssize_t		ft_read(int fd, void *buf, size_t count);


int		main(int ac, char **av)
{

	//	CALLING CONVENTION

	//ft_call_convention(1, 2, 3, 4, 5, 6, 7, 8);

	//	STRLEN

	/*if (ac < 2)
		return 1;
	int		ret = 0;
	printf("av[1] = %p\n", av[1]);
	printf("---------------\nstrlen = %lu\n", strlen(av[1]));
	printf("---------------\nft_strlen = %lu\n", ft_strlen(av[1]));
	printf("---------------\nputs:\n");
	ret = puts(av[1]);
	printf("Ret value = %d\n", ret);
	printf("---------------\nft_puts:\n");
	ret = ft_puts(av[1]);
	printf("Ret value = %d\n", ret);*/


#define SIZE 10
	//	MEMCPY

	/*if (ac < 2)
		return 1;
		
	size_t	i = 0;
	char	test1[SIZE];
	char	test2[SIZE];
	char	test12[SIZE];
	char	test22[SIZE];
	while (i < SIZE)
	{
		test1[i] = 4;
		test2[i] = 4;
		test12[i] = 7;
		test22[i] = 7;
		i++;
	}
	test1[SIZE / 2] = 0;
	test2[SIZE / 2] = 0;
	printf("Test ptr = %p\n", test2);
	printf("Test before = |");
	i = 0;
	while (i < SIZE)
	{
		printf("%-4d", test1[i]);
		i++;
	}
	printf("|\n----------------------\n");
	memcpy(test1, test12, atoi(av[1]));
	printf("bzero     = |");
	i = 0;
	while (i < SIZE)
	{
		printf("%-4d", test1[i]);
		i++;
	}
	printf("|\n-----------------------\n");
	ft_memcpy(test2, test22, atoi(av[1]));
	printf("ft_bzero  = |");
	i = 0;
	while (i < SIZE)
	{
		printf("%-4d", test2[i]);
		i++;
	}
	printf("|\n");*/

	// STRCAT
	
	/*if (ac < 3)
		return 1;
		
	ft_strcat(av[1], av[2]);
	char	*str1 = strdup(av[1]);
	char	*str2 = strdup(av[1]);
	printf("dst = %p\n", str2);
	printf("src = %p\n", av[2]);
	printf("str2 = %s\n", str2);
	printf("strcat:		|%s|\n", strcat(str1, av[2]));
	printf("ft_strcat:	|%s|\n", ft_strcat(str2, av[2]));*/
	
	/*if (ft_isalnum(atoi(av[1])))
		printf("alnum\n");
	else
		printf("Not alnum\n");*/

	/*printf("av[1] addrr = %p\n", av[1]);
	printf("strlen = %lu\n", strlen(av[1]));
	printf("ft_strlen = %lu\n", ft_strlen(av[1]));
	char *avcpy = strdup(av[1]);
	printf("addrr = %p\n", avcpy);
	printf("strdup =	|%s|\n", avcpy);
	free(avcpy);
	char *str = ft_strdup(av[1]);
	printf("addrr = %p\n", str);
	//printf("ft_strdup =	|%s|\n", str);
	for (size_t i = 0; i < strlen(av[1]); i++)
		printf("%c", str[i]);
	printf("\n");
	for (size_t i = 0; i < strlen(av[1]); i++)
		printf("%d ", str[i]);
	printf("\n");
	free(str);*/
	//for (size_t i = 0; i < strlen(av[1]) + 2; i++)
	//{
	//	printf("%d(%c) ", str[i], str[i]);
	//}
	//printf("|\n");
	

	/*printf("%c tolower =	%c (%d)\n", av[1][0], tolower(av[1][0]), tolower(av[1][0]));
	printf("%c ft_tolower =	%c (%d)\n", av[1][0], ft_tolower(av[1][0]), ft_tolower(av[1][0]));
	printf("%c toupper =	%c (%d)\n", av[1][0], toupper(av[1][0]), toupper(av[1][0]));
	printf("%c ft_toupper =	%c (%d)\n", av[1][0], ft_toupper(av[1][0]), ft_toupper(av[1][0]));
*/

	/*int fd;

	fd = open(av[1], O_RDONLY);

	ft_cat(0);
	close(fd);*/

	//	WRITE 

	/*ssize_t ret_1 = write(4, av[1], strlen(av[1]));
	if (ret_1 == -1)
	{
		printf("errno = %d\n", errno);
		perror("'write(4, av[1], strlen(av[1])'");
	}
	ssize_t ret0 = ft_write(4, av[1], strlen(av[1]));
	if (ret0 == -1)
	{
		printf("errno = %d\n", errno);
		perror("'ft_write(4, av[1], strlen(av[1]))'");
	}

	ssize_t ret_2 = write(STDOUT_FILENO, 0, 4);
	if (ret_2 == -1)
	{
		printf("errno = %d\n", errno);
		perror("'write(STDOUT_FILENO, 0, strlen(av[1])'");
	}
	ssize_t ret_3 = ft_write(STDOUT_FILENO, 0, 4);
	if (ret_3 == -1)
	{
		printf("errno = %d\n", errno);
		perror("'ft_write(STDOUT_FILENO, 0, strlen(av[1]))'");
	}

	ssize_t ret1 = write(STDOUT_FILENO, av[1], strlen(av[1]));
	ssize_t ret2 = write(STDOUT_FILENO, "\n", 1);
	printf("ret1 = %ld ret2 = %ld\n", ret1, ret2);
	ssize_t ret3 = ft_write(STDOUT_FILENO, av[1], strlen(av[1]));
	ssize_t ret4 = ft_write(STDOUT_FILENO, "\n", 1);
	printf("ret3 = %ld ret4 = %ld\n", ret3, ret4);*/

	//	STRCPY

	/*printf("--Test with src = av[1]--\n");
	char* str1 = (char*)malloc(sizeof(char) * strlen(av[1]) + 1);
	char* str2 = (char*)malloc(sizeof(char) * ft_strlen(av[1]) + 1);
	strcpy(str1, av[1]);
	printf("strcpy of av[1] = '%s'\n", str1);
	ft_strcpy(str2, av[1]);
	printf("ft_strcpy of av[1] = '%s'\n", str2);
	free(str1);
	free(str2);*/

	//	Uncomment to test but strcpy crashes
	/*printf("--Test with src = null--\n");
	str1 = (char*)malloc(sizeof(char) * strlen(av[1]) + 1);
	str2 = (char*)malloc(sizeof(char) * ft_strlen(av[1]) + 1);
	strcpy(str1, NULL);
	printf("strcpy of null = '%s'\n", str1);
	ft_strcpy(str2, NULL);
	printf("ft_strcpy of  = '%s'\n", str2);
	free(str1);
	free(str2);*/

	/*printf("--Test with src = \"\"--\n");
	str1 = (char*)malloc(sizeof(char) * 1);
	str2 = (char*)malloc(sizeof(char) * 1);
	strcpy(str1, "");
	printf("strcpy of null = '%s'\n", str1);
	ft_strcpy(str2, "");
	printf("ft_strcpy of  = '%s'\n", str2);
	free(str1);
	free(str2);

	printf("--Test with dest too big--\n");
	str1 = (char*)malloc(sizeof(char) * strlen(av[1]) * 2);
	str2 = (char*)malloc(sizeof(char) * ft_strlen(av[1]) * 2);
	strcpy(str1, av[1]);
	printf("strcpy of av[1] = '%s'\n", str1);
	ft_strcpy(str2, av[1]);
	printf("ft_strcpy of av[1] = '%s'\n", str2);
	free(str1);
	free(str2);*/

	//	STRCMP

	/*if (ac < 3)
		return 0;

	printf("strcmp(av[1], av[2]) = %d\n", strcmp(av[1], av[2]));
	printf("ft_strcmp(av[1], av[2]) = %d\n", ft_strcmp(av[1], av[2]));*/

	//	READ
	
	printf("----VALID INPUT TEST----\n\n");
	int ret, fd;
	fd = open("test_file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open error:");
		return -1;
	}
#define BUFF_SIZE 512
	printf("----read----\n");
	char buf1[BUFF_SIZE + 1];
	while ((ret = read(fd, buf1, BUFF_SIZE)))
	{
		buf1[ret] = 0;
		printf("%s", buf1);
	}
	close(fd);
	fd = open("test_file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open error:");
		return -1;
	}
	printf("---ft_read----\n");
	char buf2[BUFF_SIZE + 1];
	while ((ret = ft_read(fd, buf2, BUFF_SIZE)))
	{
		buf2[ret] = 0;
		printf("%s", buf2);
	}
	close(fd);
	printf("\n----CLOSED FD TEST----\n\n");
	if (read(fd, buf1, BUFF_SIZE) == -1)
	{
		printf("errno = %d\n", errno);
		perror("read");
	}
	if (ft_read(fd, buf2, BUFF_SIZE) == -1)
	{
		printf("errno = %d\n", errno);
		perror("ft_read");
	}

	printf("\n----FD OPEN IN WRONLY TEST----\n\n");
	fd = open("test_file.txt", O_WRONLY);
	if (read(-1, buf1, BUFF_SIZE) == -1)
	{
		printf("errno = %d\n", errno);
		perror("read");
	}
	if (ft_read(-1, buf2, BUFF_SIZE) == -1)
	{
		printf("errno = %d\n", errno);
		perror("ft_read");
	}
	close(fd);

	printf("\n----DIRECTORY FD TEST----\n\n");
	fd = open("src", O_RDONLY | O_DIRECTORY);
	if (read(-1, buf1, BUFF_SIZE) == -1)
	{
		printf("errno = %d\n", errno);
		perror("read");
	}
	if (ft_read(-1, buf2, BUFF_SIZE) == -1)
	{
		printf("errno = %d\n", errno);
		perror("ft_read");
	}
	close(fd);

	printf("\n----INVALID BUFFER TEST----\n\n");
	fd = open("test_file.txt", O_RDONLY);
	if (read(fd, NULL, BUFF_SIZE) == -1)
	{
		printf("errno = %d\n", errno);
		perror("read");
	}
	if (ft_read(fd, NULL, BUFF_SIZE) == -1)
	{
		printf("errno = %d\n", errno);
		perror("ft_read");
	}
	close(fd);

	return (0);
}