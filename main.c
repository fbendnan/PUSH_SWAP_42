#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_stack	*head_a;
	t_stack	*head_b;

    head_a = NULL;
    head_b = NULL;

    if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
        return (1);
    else if(argc == 2)
    argv = ft_split(argv[1], ' ');
	head_a = fill_stack_a(argc, argv, &head_a);

}