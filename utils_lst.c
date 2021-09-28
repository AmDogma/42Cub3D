#include "head_main.h"

void	del_one_lst(t_list **lines)
{
	t_list	*temp;

	temp = *lines;
	*lines = (*lines)->next;
	free(temp->content);
	free(temp);
}
