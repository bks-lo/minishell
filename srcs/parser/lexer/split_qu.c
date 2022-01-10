/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_qu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeelbored <ifeelbored@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:01:04 by wlo               #+#    #+#             */
/*   Updated: 2022/01/10 13:59:30 by ifeelbored       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	sep(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

int		count_len(char *s)
{
	int len;
	int dq;
	int	sq;

	len = 0;
	dq = 0;
	sq = 0;
	while(*s)
	{
		//年再一起的引號算同一個字
		if (*s == '\"')
			dq++;
		if (*s == '\'')
			sq++;
		if (*s == ' ' && dq%2 == 0 && sq%2 == 0)//沒有引號
			break;
		if (*s == ' ' && dq%2 == 1 && sq%2 == 2)
		 	break;
		if (*s == ' ' && dq%2 == 2 && sq%2 == 1)
		 	break;
		len++;
		//printf("s:%s, %d: sq:%d, dq:%d\n", s, len, sq, dq);
		s++;
	}
	return (len);
}

int if_quote_close(int *start, int len, char *s)
{
	//是誰先關了？
	int sq;
	int dq;
	int status;

	sq = 0;
	dq = 0;
	status = 0;
	while((*start) < len)
	{
		//"iuh'jio'" 不是引號先結束作為判斷...如果不是“‘”’這種情況
		if (s[(*start)] == '\'')
			sq++;
		else if (s[(*start)] == '\"')
			dq++;
		if (sq == 1 && !status)
			status = 1;
		else if (dq == 1 && !status)
			status = 2;
		(*start) = (*start) + 1;
		if (sq == 2 && status == 1)
			return (1);
		else if (dq == 2 && status == 2)
			return (2);
		if ((sq == 2 && dq == 2) || sq > 2 || dq > 2) //為什麼是＆＆不是｜｜
			break ;
	}
	if (sq >= 2 && status == 2)
		return (1);
	else if (dq >= 2 && status == 1)
		return (2);
	return (0);
}

int	check_envvar_qu(char *arr, char *new, int begin, int end,int *i_new)
{
	//如果是有引號的 引號裡面所有的var都要check
	int len_var;

	printf("QU:%s\n", arr);
	while (arr[begin] && begin < end)
	{
		if (arr[begin] == '$' && arr[begin + 1])
		{
			printf("chech env in qu:|%s|, %d, %d, %d\n", new, begin, end, *i_new);
			len_var = replace_var(&arr[begin + 1], new, i_new);
			printf("chech env in quafter:|%s|, %d, %d, %d\n", new, begin, end, *i_new);
			begin = begin + len_var;
		} 
		else if (arr[begin] != '\"')
		{
			printf("chech env in quother:|%s|, %d, %d, %d\n", new, begin, end, *i_new);
			new[*i_new] = arr[begin];
			begin++;
			(*i_new) = (*i_new) + 1;
		}
		else
			printf("chech env in qNOTHING:|%s|, %d, %d, %d\n", new, begin, end, *i_new);
			begin++;
	}
	(*i_new) = ft_strlen(new);
	return (begin);
}
int	check_envvar(char *arr, char *new, int *i_arr, int *i_new)
{
	int temp;
	int len_var;

	temp = (*i_arr);
	len_var = 0;
	printf("Check_env:%s,|%s|,%d,%d\n",arr, new, *i_arr,*i_new);
	while(arr[temp] != '$')
		temp++;
	if (arr[temp + 1])
		len_var = replace_var(&arr[(temp) + 1], new, i_new);
	(*i_new) = ft_strlen(new);
	printf("replace :|%s|, %d, %d, %d\n", new, (*i_new), (*i_arr), temp);
	return (len_var);
}
int ft_strchr_do(char *arr, int start, int end)
{
	while(arr[start] && start <= end)
	{
		if (arr[start] == '$')
			return (1);
		start++;
	}
	return (0);
}

//當有quote
void	replace_quote(char *arr, char *new,int *i_arr, int *i_new)
{
	int	quote;
	int temp;
	int	start;
	int temp2;

	temp = (*i_arr);//哪裡開始 check 引號
	temp2 = 0;
	start = (*i_new);//哪裡開始取代var
	quote = if_quote_close(i_arr, ft_strlen(arr) , arr);
	printf("QOUTE:|%d|,|%s|, |%s|, |%d|,|%d|\n", quote, arr, new, *i_arr, *i_new);
	while(temp < (*i_arr))
	{
		if (quote == 1 && arr[temp] != '\'')
		{
			printf("1\n");
			new[(*i_new)] = arr[temp];
			(*i_new) = (*i_new) + 1;
		}
		else if (quote == 2 && arr[temp] == '\"')
		{
			printf("1.5, %d, %d\n", temp, (*i_arr));
			if (ft_strchr_do(arr, temp, (*i_arr)))
			{
				temp = check_envvar_qu(arr, new, temp, *i_arr, i_new);
				//(*i_arr) = temp + 2; //$"
				printf("temp:%d, %s\n", temp, new);
			}
		}
		else if (quote == 2 && arr[temp] != '\"')
		{
			printf("2:%d, %c, %d\n", *i_new, arr[temp], temp);
			new[(*i_new)] = arr[temp];
			(*i_new) = (*i_new) + 1;
		}
		else if (quote == 0)
		{
			printf("3\n");
			new[(*i_new)] = arr[temp];
			(*i_new) = (*i_new) + 1;
		}
		printf("NEW in loop:%s, %d\n", new, (*i_new));
		temp++;
	}
	printf("NEW1:%s, %d\n", new ,(*i_new));
	new[(*i_new)+1] = '\0';
	printf("NEW2:%s, %d\n", new ,(*i_new));
	// if (quote == 2)
	// {
	// 	if (ft_strchr(new, '$'))
	// 		check_envvar(arr, new, &temp2, &start);
	// }
	(*i_new) = ft_strlen(new);
	printf("NEW3:%s, %d\n", new ,(*i_new));
}

void initial(char *new)
{
	int	i;

	i = -1;
	while(++i < 1000)
		new[i] = '\0';
}
char	*check_quote(char *arr, int len)
{
	char new[1000];
	int i_arr;
	int i_new;
	char *try;

	(void)len;
	i_arr = 0;
	i_new = 0;
	initial(new);
	printf("OUT LOOP:|%s|,|%s|, |%d|, |%d|\n",arr, new, i_arr, i_new);
	while(arr[i_arr])
	{
		//如果需要重新malloc不要忘記加後面的cmd
		if (arr[i_arr] == '\"' || arr[i_arr] == '\'')
		{
			printf("checkquote:%d\n", i_new);
			replace_quote(arr, new, &i_arr,&i_new);
			//i_new++;
		}
		else if (arr[i_arr] == '$')
		{
			check_envvar(arr, new, &i_arr, &i_new);
			i_arr++;
		}
		else
			new[i_new++] = arr[i_arr++];
		new[i_new] = '\0';
		printf("IN LOOP:|%s|, |%d|, |%d|\n", new, i_arr, i_new);
		//i_arr++;
	}
	new[i_new] = '\0';
	try =ft_strdup(new);
	return (try);
}
int		check_each(char ***arr, int len, char *s, int index)
{
	int i;

	i = 0;
	(*arr)[index] = (char *)malloc((len + 1) * sizeof(char));
	if (!(*arr)[index])
		return (0);
	//複製字 判斷quote需要複製？
	//要一起處理quote跟var嗎？
	while (i < len)
	{		
		(*arr)[index][i++] = *s;
		s++;
	}
	(*arr)[index][i] = '\0';
	(*arr)[index] = check_quote((*arr)[index], len);
	printf("(*arr)[index][i]:%s\n", (*arr)[index]);
	//free((*arr)[index]);
	return (len);//???

}

void	ft_split_2_qu(char ***arr, char *s, int count_ws)
{
	int	index;
	int	state;
	int	len;

	index = 0;
	state = 0;
	while (index < count_ws)
	{
		while (*s == ' ')
				s++;
		len = count_len(s);
		printf("len for word:%d\n", len);
		check_each(arr, len, s, index);
		s = s + len + 1;
		//printf("arr[index]:%s\n", (*arr)[index]);
		index++;
	}
	(*arr)[index] = 0;
}

char	**ft_split_qu(char *s, char c)
{
	char	**arr;
	int		count_ws;

	(void)c;
	if (!s)
		return (0);
	count_ws = count_w_qu(s);
	printf("count words:%d\n", count_ws);
	arr = (char **)malloc((count_ws + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	ft_split_2_qu(&arr, s, count_ws);
	return (arr);
}