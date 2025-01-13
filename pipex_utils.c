#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	char	*ss;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	ss = (char *)s;
	i = 0;
	while (i < len && ss[start])
	{
		substr[i++] = ss[start++];
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[i - i])
		{
			j = i + 1;
			while ((haystack[j] == needle[j - i]) && needle[j - i] && j < len)
				j++;
			if ((!needle[j - i]))
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joinstr;
	size_t	s1size;
	size_t	s2size;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1size = ft_strlen(s1);
	s2size = ft_strlen(s2);
	joinstr = (char *)malloc(s1size + s2size + 1);
	if (!joinstr)
		return (NULL);
	ft_memmove(joinstr, s1, s1size);
	ft_memmove(joinstr + s1size, s2, s2size);
	joinstr[s1size + s2size] = '\0';
	return (joinstr);
}

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	s2 = (char *)malloc(size + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
