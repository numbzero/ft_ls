#include "ft_ls.h"

char 	*concatenate1(char *a, char *b)
{
	char 	*res;
    size_t	alen;
    size_t	blen;

    alen = strlen(a);
	blen = strlen(b);
    res = (char *)malloc((alen + blen + 1) * sizeof(char));
    memcpy(res, a, alen);
    memcpy(res + alen, b, blen + 1);
    return (res);
}

char 	*concatenate2(char *a, char *b, char *c)
{
	char 	*res;
    size_t	alen;
    size_t	blen;
    size_t	clen;

    alen = strlen(a);
	blen = strlen(b);
	clen = strlen(c);
    res = (char *)malloc((alen + blen + clen + 1) * sizeof(char));
    memcpy(res, a, alen);
    memcpy(res + alen, b, blen);
    memcpy(res + alen + blen, c, clen + 1);
    return (res);
}