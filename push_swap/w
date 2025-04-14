this is my push swap so far how can i start implementing mechanical turk algorithm
typedef struct s_node
{
	long			value;
	struct s_node	*next;
}	t_node;
//represents the stack itself , 
//top is a pointer to a linked list tnode which is the top of the stack
typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	peek_val;

	if (stack_b->size > 0)
	{
		peek_val = peek(stack_b);
		push(stack_a, peek_val);
		pop(stack_b);
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	peek_val;

	if (stack_a->size > 0)
	{
		peek_val = peek(stack_a);
		push(stack_b, peek_val);
		pop(stack_a);
	}
	write(1, "pb\n", 3);
}
void	rra(t_stack *stack_a)
{
	t_node	*prev;
	t_node	*last;

	if (stack_a->size > 2)
	{
		prev = NULL;
		last = stack_a->top;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = stack_a->top;
		stack_a->top = last;
		write(1, "rra\n", 4);
	}
	else
		return ;
}

void	rrb(t_stack *stack_b)
{
	t_node	*prev;
	t_node	*last;

	if (stack_b->size > 2)
	{
		prev = NULL;
		last = stack_b->top;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = stack_b->top;
		stack_b->top = last;
		write(1, "rrb\n", 4);
	}
	else
		return ;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
void	ra(t_stack *stack_a)
{
	t_node	*first;	
	t_node	*temp;

	if (stack_a->size > 2)
	{
		first = stack_a->top;
		stack_a->top = stack_a->top->next;
		temp = stack_a->top;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = first;
		first->next = NULL;
		write(1, "ra\n", 3);
	}
	else
		return ;
}

void	rb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*temp;

	if (stack_b->size > 2)
	{
		first = stack_b->top;
		stack_b->top = stack_b->top->next;
		temp = stack_b->top;
		while (temp->next)
			temp = temp->next;
		temp->next = first;
		first->next = NULL;
		write(1, "rb\n", 3);
	}
	else
		return ;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
void	sa(t_stack *stack_a)
{
	t_node	*node_1;

	if (stack_a->size > 1)
	{
		node_1 = stack_a->top;
		stack_a->top = stack_a->top->next;
		node_1->next = stack_a->top->next;
		stack_a->top->next = node_1;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack	*stack_b)
{
	t_node	*node_1;

	if (stack_b->size > 1)
	{
		node_1 = stack_b->top;
		stack_b->top = stack_b->top->next;
		node_1->next = stack_b->top->next;
		stack_b->top->next = node_1;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

bool	is_empty(t_stack *stack)
{
	if (stack->top == NULL)
		return (true);
	else
		return (false);
}

void	push(t_stack *stack, long value)
{
	t_node	*new_node;

	if(!stack)
		return ;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

void	pop(t_stack *stack)
{
	t_node	*node;

	if (is_empty(stack))
		return ;
	node = stack->top;
	stack->top = stack->top->next;
	free(node);
	stack->size--;
}

int	peek(t_stack *stack)
{
	if (is_empty(stack))
		return (-1);
	return (stack->top->value);
}
void	print_stack(t_stack *stack)
{
	t_node	*copy;

	copy = stack->top;
	while (copy)
	{
		ft_printf("%d", copy->value);
		if (copy->next != NULL)
			ft_printf(", ");
		copy = copy->next;
	}
	ft_printf("\n");
}

bool	check_valid_chars(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9') && str[i][j] != '-' && str[i][j] != '+' && str[i][j] != ' ')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_valid_token(char *str)
{
	int	i;

	i = 0;
	if ((str[0] == '+' || str[0] == '-') && str[1] == '\0')
		return (false);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '\0')
		return (false);
	else if (str[i])
	{
		while (str[i])
		{
			if ((str[i] == '+' || str[i] == '-' ) && !ft_isdigit(str[i + 1]))
				return (false);
			i++;
		}
	}
	return (true);
}

bool	check_valid_operators(int ac, char **av)
{
	int	i;

	i = ac - 1;
	while (i > 0)
	{
		if (!is_valid_token(av[i]))
			return (false);
		i--;
	}
	return (true);
}

bool	check_dup(t_stack *stack)
{
	t_node	*ptr;
	int		*array;
	int		i;
	int		j;

	i = 0;
	array = (int *)malloc(stack->size * sizeof(int));
	if (!array)
		return (NULL);
	ptr = stack->top;
	while (ptr)
	{
		j = 0;
		while (j < i)
		{
			if (array[j++] == ptr->value)
				return (free_stack(stack), free(array), true);
		}
		array[i++] = ptr->value;
		ptr = ptr->next;
	}
	free(array);
	return (false);
}

t_stack	*build_stack(int ac, char **av)
{
	int		i;
	int		j;
	char	**splited;
	t_stack	*stack;

	i = ac;
	stack = create_stack();
	while (--i > 0)
	{
		j = 0;
		splited = ft_split(av[i]);
		while (splited[j])
			j++;
		while (--j >= 0)
		{
			push(stack, ft_atoi(splited[j]));
			if (!is_within_limits(stack->top->value))
				return (free_stack(stack), free_split(splited), NULL);
		}
		free_split(splited);
	}
	if (check_dup(stack))
		return (NULL);
	return (stack);
}

t_stack *parse_stack_a(int ac, char **av, t_stack *stack_a)
{
	if (ac == 1)
		exit(0);
	else if (!check_valid_chars(av) || !check_valid_operators(ac, av))
		print_message("Error\n");
	else if (check_valid_chars(av))
	{
		stack_a = build_stack(ac, av);
		if (!stack_a)
			print_message("Error\n");
	}
    return (stack_a);
}

int find_min_index(t_stack *stack) {
    t_node *current = stack->top;
    int min = current->value;
    int index = 0;
    int min_index = 0;

    current = current->next;
    while (current) {
        index++;
        if (current->value < min) {
            min = current->value;
            min_index = index;
        }
        current = current->next;
    }
    return min_index;
}

void rotate_min_to_top(t_stack *a) {
    int min_pos = find_min_index(a);
    int size = a->size;
    
    if (min_pos == 0) return;
    
    if (min_pos <= size/2)
    {
        while (min_pos-- > 0)
            ra(a);
    }
    else
    {
        min_pos = size - min_pos;
        while (min_pos-- > 0)
            rra(a);
    }
}

// Main Algorithm
void mechanical_turk(t_stack *a, t_stack *b) {
    if (is_sorted(a)) return;
    
    if (a->size == 2) {
        if (peek(a) > a->top->next->value)
            sa(a);
        return;
    }
    
    if (a->size == 3) {
        sort_three(a);
        return;
    }

    while (a->size > 0) {
        rotate_min_to_top(a);
        pb(a, b);
    }
    print_stack(b);
    while (b->size > 0)
        pa(a, b);
}

bool    is_sorted(t_stack *stack)
{
    t_node  *nodes;

    nodes = stack->top;
    while(nodes->next)
    {
        if(nodes->value > nodes->next->value)
            return (false);
        nodes = nodes->next;
    }
    return (true);
}

void    sort_three(t_stack *stack)
{
    int first;
    int middle;
    int last;

    first = peek(stack);
    middle = stack->top->next->value;
    last = stack->top->next->next->value;
    if (first > middle && middle < last && last > first)
        sa(stack);
    else if (first > middle && middle < last && last < first)
        ra(stack);
    else if (first < middle && middle > last && last < first)
        rra(stack);
    else if (first > middle && middle > last && last < first)
    {
        sa(stack);
        rra(stack);
    }
    else if (first < middle && middle > last && last > first)
    {
        sa(stack);
        ra(stack);
    }
}


int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = parse_stack_a(ac, av, stack_a);
	stack_b = create_stack();
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(0);
	}
	// print_stack(stack_a);
	// sort_three(stack_a);

	mechanical_turk(stack_a, stack_b);
	// print_stack(stack_a);
	if(is_sorted(stack_a))
		printf("stack is sorted\n");
	else
		printf("not sorted\n");
	// print_stack(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
}

