#pragma once

#include "simulation.h"

char    **interactive_mode(char **prompts, size_t nb_prompts);
char    **make_prompts(size_t nb_prompts, const char *prompt, ...);
