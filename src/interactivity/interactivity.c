#include "interactivity.h"

char    **make_prompts(size_t nb_prompts, const char *first_prompt, ...)
{
    char **res;
    va_list ap;
    size_t i;

    res = malloc(sizeof(char *) * (nb_prompts + 1));
    if (!res)
    {
        ft_putendl("Error on malloc()");
        return (NULL);
    }

    res[0] = strdup(first_prompt); // Add the first prompt to the array
    if (!res[0]) // Check for strdup failure
    {
        free(res);
        return (NULL);
    }

    va_start(ap, first_prompt);
    i = 1;
    while (i < nb_prompts)
    {
        char *current_prompt = va_arg(ap, char *);
        res[i] = strdup(current_prompt);
        if (!res[i]) // Check for strdup failure
        {
            // Free already allocated memory
            while (i > 0)
                free(res[--i]);
            free(res);
            va_end(ap);
            return (NULL);
        }
        i++;
    }
    res[i] = NULL; // Correctly terminate the array
    va_end(ap);

    return (res);
}

char    **interactive_mode(char **prompts, size_t nb_prompts)
{
    char    **res;
    char    buff[256];
    size_t  i;

    res = malloc(sizeof(char *) * (nb_prompts + 1));
    if (!res)
    {
        ft_putendl("Error on malloc()");
        return (NULL);
    }

    i = 0;
    while (i < nb_prompts)
    {
        bzero(buff, sizeof(char) * 256);
        ft_putstr(prompts[i]);
        read(0, &buff, 256);
        res[i] = strdup(buff);
        i++;
    }
    res[i] = NULL;

    return (res);
}
