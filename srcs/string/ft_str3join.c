//
// Created by pde-bakk on 1/18/23.
//

#include <stddef.h>
#include "libft.h"

char* ft_str3join(const char* const a, const char* const b, const char* const c) {
	char* out;
	const size_t len_a = ft_strlen(a),
			len_b = ft_strlen(b),
			len_c = ft_strlen(c);
	const size_t total_length = len_a + len_b + len_c + 1;

	out = ft_calloc(total_length, sizeof(char));
	if (out == NULL)
		return (NULL);
	ft_strlcpy(out, a, len_a + 1);
	ft_strlcpy(out + len_a, b, len_b + 1);
	ft_strlcpy(out + len_a + len_b, c, len_c + 1);
	return (out);
}
