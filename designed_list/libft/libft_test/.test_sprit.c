/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_sprit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 21:41:51 by skazama           #+#    #+#             */
/*   Updated: 2025/11/04 04:19:47 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
/*
static size_t	ft_count_row(const char c, const char *s)
{
	size_t	i;
	size_t	row;
	int isword;

	i = 0;
	row = 0;
	isword = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (isword == 0)
				++row;
			isword = 1;
		}
		else if (s[i] == c)
			isword = 0;
		
		++i;
	}
	return (row);
}*/
int main(void)
{
//	printf("%d", ft_count_row(' ', "    "));
	char **s = ft_split("", 'z');
//	char **s1 = ft_split("      ", ' ');
	char **s2 = ft_split("    A  ", ' ');
	char **s3 = ft_split("a b c", ' ');
	char **s4 = ft_split("        ", ' ');//RETURN s4[0] = ""
	int i = 0;
    	if (!s)
      		printf("NULL");
	else if (!s[0])
		printf("ok\n");
	else
		printf("s:%p\n", s[0]);

	while (s2[i] != NULL){
		printf("##in tmain: s2[%d]:%p(%s)\n",i, s2[i],s2[i]);//must be abc
		++i;
	}
	
	i = 0;
	while (s3[i] != NULL){
		printf("##in tmain: s3[%d]:%p(%s)\n",i, s3[i],s3[i]);//must be abc
		++i;
	}
	
	i = 0;
	if (!s4)
        	printf("NULL");

	while (s4[i] != NULL){
		printf("##in tmain: s4[%d]:%p(%s)\n",i, s4[i],s4[i]);//must be abc
		++i;
	}
	char	**s5 = ft_split("hello!", ' ');
	char	**s6 = ft_split("xxxxxxxxhello!", 'x');
	char	**s7 = ft_split("hello!zzzzzzzz", 'z');
	char	**s8 = ft_split("\11\11\11\11hello!\11\11\11\11", '\11');
	char	**s9 = ft_split("", 'a');
	char	**t1 = ft_split("ggggggggggg", 'g');
	char	**t2 = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
	char	**t3 = ft_split("nonempty", '\0');
	/*
##in tmain: s5[0]:0x18dd7e0(hello!) ok
##in tmain: s6[0]:0x18dd820(hello!) ok
##in tmain: s7[0]:0x18dd860(hello!) ok
##in tmain: s8[0]:0x18dd8a0(hello!) ok
##in tmain: t2[0]:0x18dd930(1)
##in tmain: t2[1]:0x18dd950(2a,)
##in tmain: t2[2]:0x18dd970(3)
##in tmain: t2[3]:0x18dd990(--h)　　ok
##in tmain: t3[0]:0x18dd9d0(nonempty)ok

	*/
	i = 0;
	if (!s5)	printf("NULL");
	while (s5[i] != NULL){	printf("##in tmain: s5[%d]:%p(%s)\n",i, s5[i],s5[i]);	++i;};
	i = 0;
	if (!s6)	printf("NULL");
	while (s6[i] != NULL){	printf("##in tmain: s6[%d]:%p(%s)\n",i, s6[i],s6[i]);	++i;};
	i = 0;
	if (!s7)	printf("NULL");
	while (s7[i] != NULL){	printf("##in tmain: s7[%d]:%p(%s)\n",i, s7[i],s7[i]);	++i;};
	i = 0;
	if (!s8)
        	printf("NULL");
	while (s8[i] != NULL){	printf("##in tmain: s8[%d]:%p(%s)\n",i, s8[i],s8[i]);	++i;};
	i = 0;
	if (!s9)
        	printf("NULL");
	while (s9[i] != NULL){	printf("##in tmain: s9[%d]:%p(%s)\n",i, s9[i],s9[i]);	++i;};
	i = 0;
	if (!t1)
        	printf("NULL");
	while (t1[i] != NULL){	printf("##in tmain: t1[%d]:%p(%s)\n",i, t1[i],t1[i]);	++i;};
	i = 0;
	if (!t2)
        	printf("NULL");
	while (t2[i] != NULL){	printf("##in tmain: t2[%d]:%p(%s)\n",i, t2[i],t2[i]);	++i;};
	i = 0;
	if (!t3)
        	printf("NULL");
	while (t3[i] != NULL){	printf("##in tmain: t3[%d]:%p(%s)\n",i, t3[i],t3[i]);	++i;};
	

	i = 0;
	while (s[i]){free(s[i]);++i;};
	free(s);
	printf("SCD:free(s)\n");
	i = 0;
	while (s2[i]){free(s2[i]);++i;};
	free(s2);
	printf("SCD:free(2)\n");

	i = 0;
	while (s3[i]){free(s3[i]);++i;};
	free(s3);
	printf("SCD:free(3)\n");

	i = 0;
	while (s4[i]){free(s4[i]);++i;};
	free(s4);
	i = 0;
	printf("SCD:free(4)\n");
	while (s5[i]){free(s5[i]);++i;};
	free(s5);
	printf("SCD:free(5)\n");
	i = 0;
	while (s6[i]){free(s6[i]);++i;};
	free(s6);
	printf("SCD:free(6)\n");
	i = 0;
	while (s7[i]){free(s7[i]);++i;};
	free(s7);
	printf("SCD:free(7)\n");
	i = 0;
	while (s8[i]){free(s8[i]);++i;};
	free(s8);
	printf("SCD:free(8)\n");
	i = 0;
	while (s9[i]){free(s9[i]);++i;};
	free(s9);
	printf("SCD:free(9)\n");
	i = 0;
	while (t1[i]){free(t1[i]);++i;};
	free(t1);
	printf("SCD:free(t1)\n");
	i = 0;
	while (t2[i]){free(t2[i]);++i;};
	free(t2);
	printf("SCD:free(t2)\n");
	i = 0;
	while (t3[i]){free(t3[i]);++i;};
	free(t3);
	printf("SCD:free(t3)\n");

	return (0);
}
