#include "so_long.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dupped;

	i = 0;
	dupped = (char *) malloc(sizeof (char) * (ft_strlen(s) + 1));
	if (!dupped)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		dupped[i] = s[i];
		i++;
	}
	dupped[i] = '\0';
	return (dupped);
}