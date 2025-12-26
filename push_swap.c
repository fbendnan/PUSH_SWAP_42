#include "push_swap.h"

static void	free_split(char **args)
{
	int k = 0;
	if (!args)
		return;
	while (args[k])
		free(args[k++]);
	free(args);
}

static t_stack	*new_lst(int nb)
{
	t_stack	*next_node;

	next_node = malloc(sizeof(t_stack));
	if (!next_node)
		return (NULL);
	next_node->value = nb;
	next_node->next = NULL;
	return (next_node);
}

static void	ft_lstadd_back(t_stack **head, t_stack *new_node)
{
	t_stack	*tmp;

	if (!head || !new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

int fill_stack_a(char *argv[], t_stack **head_a)
{
	int	i,	j;
	char **args;
	long tmp;
	t_stack	*a;

	i = 1;
	while (argv[i])
	{
		j = 0;
		args = ft_split(argv[i], ' ');
		if (!args)
			return (0);
		while (args[j])
		{
			if (check_error(args, j, &tmp, head_a))
				return (0);
			a = new_lst((int)tmp);
			if (!a)
				return (free_split(args), 0);
			ft_lstadd_back(head_a, a);
			j++;
		}
		free_split(args);
		i++;
	}
	return (1);
}
