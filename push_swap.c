#include "push_swap.h"

t_stack	*new_lst(char *str)
{
	t_stack	*next_node;

	next_node = malloc(sizeof(t_stack));
	if (!next_node)
		return (NULL);
	next_node->value = atoi(str);
	next_node->next = NULL;
	return (next_node);
}

t_stack *fill_stack_a(int argc, char *argv[], t_stack **head_a)
{
	t_stack	*a;
	int	i;

	if (argc == 1)
		return NULL;
	a = new_lst(argv[1]);
	*head_a = a;
	if (!a)
		return NULL;
	i = 2;
	while (argc > i)
	{
		a->next = new_lst(argv[i]);
		a = a->next;
		i++;
	}
	return (*head_a);
}

void push_swap(int argc, char *argv[])
{
	t_stack	*head_a;

	head_a = fill_stack_a(argc, argv, &head_a);
	t_stack	*head_b =  malloc(sizeof(t_stack));
	head_b = NULL;
}

int main(int argc, char *argv[])
{   
	// char *str1 = "1111";
	// char *str2 = "2222";
	// char *str3 = "3333";
	// char *str4 = "4444";
	// char *str[5] = {&str1[0], &str2[0], &str3[0], &str4[0]};
	push_swap(argc, argv);
}