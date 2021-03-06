/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymekraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 02:56:32 by ymekraou          #+#    #+#             */
/*   Updated: 2019/04/23 18:41:05 by ymekraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		quit_sdl(SDL_Window *window)
{
	if (window)
		SDL_DestroyWindow(window);
	SDL_Quit();
}

int			sdl_has_fcked_up(t_env *env)
{
	clean_lists(env->light, env->elem);
	ft_putendl("an SDL error occured .\n");
	quit_sdl(env->window);
	return (-1);
}

int			main_loop(t_env *env)
{
	SDL_Event		event;
	int				quit;

	if (!(access_surface_pixels(env)))
		return (sdl_has_fcked_up(env));
	if (SDL_UpdateWindowSurface(env->window) < 0)
		return (sdl_has_fcked_up(env));
	quit = 0;
	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				quit = 1;
			if (event.type == SDL_KEYDOWN)
			{
				key_event(env, event.key.keysym.sym);
				if (event.key.keysym.sym == SDLK_ESCAPE)
					quit = 1;
			}
		}
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_env	env;

	if (ac == 2)
	{
		file_parsing(av[1], &env);
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
			return (sdl_has_fcked_up(&env));
		else
		{
			if (!(env.window = SDL_CreateWindow("RTv1", 50, 50,
							(int)(SCREEN_WIDTH), (int)(SCREEN_HEIGHT),
							SDL_WINDOW_SHOWN)))
				return (sdl_has_fcked_up(&env));
			else
			{
				env.screen = SDL_GetWindowSurface(env.window);
				if (main_loop(&env) < 0)
					return (sdl_has_fcked_up(&env));
			}
		}
		quit_sdl(env.window);
	}
	else
		ft_putendl("invalid number of arguments");
	return (0);
}
