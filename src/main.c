#include "simulation.h"

char    **intro_prompt(void)
{
    char    **prompts;
    char    **responses;

    prompts = make_prompts(1, "1. Introduction\n0. Exit\n");
    responses = interactive_mode(prompts, 1);

    return (responses);
}

int main(void)
{
    char    **information;

    information = intro_prompt();

    for (size_t i = 0; i < 1; i++)
        ft_putstr(information[i]);
    
    return (0);
}
