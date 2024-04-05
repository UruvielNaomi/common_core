#include "push_swap.h"

void	ft_search_top(t_list **stack_a, t_list **stack_b, t_track *track)
{
	t_list	*temp;
	int		i;

	temp = *stack_b;
	i = 1;
	track->dif_top = (*stack_a)->value - temp->value;
	if (track->dif_top < 0)
		track->dif_top *= -1;
	track->close_top = i;
	track->value_top = temp->value;
	while (i <= track->j)
	{
		if ((*stack_a)->value - temp->value < track->dif_top)
		{
			track->dif_top = (*stack_a)->value - temp->value;
			if (track->dif_top < 0)
				track->dif_top *= -1;
			track->close_top = i;
			track->value_top = temp->value;
		}
		temp = temp->next;
		i++;
	}
	ft_printf("Found number top: %d\n", track->value_top);
	ft_printf("Difference: %d\n", track->dif_top);
	ft_printf("Location: %d\n", track->close_top);
}

void	ft_search_bottom(t_list **stack_a, t_list **stack_b, t_track *track)
{
	t_list	*temp;
	int		i;

	i = 1;
	temp = *stack_b;
	while (i <= track->j)
	{
		temp = temp->next;
		i++;
	}
	track->dif_bot = (*stack_a)->value - temp->value;
	if (track->dif_bot < 0)
		track->dif_bot *= -1;
	track->close_bot = i;
	track->value_bot = temp->value;
	while (i <= track->k && temp != NULL)
	{
		if ((*stack_a)->value - temp->value < track->dif_bot)
		{
			track->dif_bot = (*stack_a)->value - temp->value;
			if (track->dif_bot < 0)
				track->dif_bot *= -1;
			track->close_bot = i;
			track->value_bot = temp->value;
			ft_printf("current element: %d\n", temp->value);
		}
		temp = temp->next;
		i++;
	}
	ft_printf("Found number bottom: %d\n", track->value_bot);
	ft_printf("Difference: %d\n", track->dif_bot);
	ft_printf("Location: %d\n", track->close_bot);
}
