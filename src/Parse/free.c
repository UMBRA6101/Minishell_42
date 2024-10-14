void	killer_request(t_data_rule *request)
{
	if (!request)
		return ;
	
	free(request);
}
