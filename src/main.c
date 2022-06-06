/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <lnicosia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 11:13:47 by lnicosia          #+#    #+#             */
/*   Updated: 2022/06/04 09:23:39 by lnicosia         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	if (ac < 1)
		return (0);

	//	CALLING CONVENTION

	//ft_call_convention(1, 2, 3, 4, 5, 6, 7, 8);

	/*int		ret = 0;
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
	printf("|\n");

	
	//ft_strcat(av[1], av[2]);
	/*char	*str1 = strdup(av[1]);
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

	/*printf("addrr = %p\n", av[1]);
	char *avcpy = strdup(av[1]);
	printf("strdup =	|%s|\n", avcpy);
	free(avcpy);
	char *str = ft_strdup(av[1]);
	printf("Yo\n");
	printf("addrr = %p\n", str);
	printf("ft_strdup =	|%s|\n", str);
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

	ssize_t ret_1 = write(4, av[1], strlen(av[1]));
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
	printf("ret3 = %ld ret4 = %ld\n", ret3, ret4);

	return (0);
}