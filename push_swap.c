#include "push_swap.h"

t_stack *new_lst(char *str)
{
    t_stack *next_node;

    next_node = malloc(sizeof(t_stack));
    if (!next_node)
        return (NULL);
    next_node->value = ft_atoi(str);
    next_node->next = NULL;
    return (next_node);
}

void push_swap(int argc, char *argv[])
{
    t_stack *head_a;
    t_stack *a;
    int i;

    if (argc == 1)
        return ;
    a = new_lst(argv[1]);
    head_a = a;
    if (!a)
        return ;
    i = 2;
    while (argc > i)
    {
        a->next = new_lst(argv[i]);
        a = a->next;
        i++;
    }
}

int main()
{   
    char *str1 = "1111";
    char *str2 = "2222";
    char *str3 = "3333";
    char *str4 = "4444";
    char *str[5] = {&str1[0], &str2[0], &str3[0], &str4[0]};
    push_swap(4, str);
}