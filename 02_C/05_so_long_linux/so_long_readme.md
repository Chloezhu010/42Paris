
# Solong

## Project description

Create a basic 2D game, incl.
- Items: player, collectibles, wall, floor, exit
- Movements: player can move up/ down/ left/ right
- Game logic: player need to collect all the items, then exit

Skills practiced
- Learn & understand a new library (minilibx)
- Window management
- Texture loading & rendering
- Event handling
## Resources
- Minilibx Github repo: https://github.com/42Paris/minilibx-linux
- Minilibx Manual: https://harm-smits.github.io/42docs/libs/minilibx
- Game asset downloads: https://itch.io/
- Convert png to xpm: https://convertio.co/


## File structure

```markdown
solong/
├── incl/
│   └── so_long.h
├── src/
│   ├── init.c
│   ├── map.c
│   ├── map_floodfill.c
│   ├── map_validate.c
│   ├── render.c
│   ├── movement.c
│   ├── movement_key.c
│   ├── cleanup.c
│   └── main_solong.c
├── texture/
│   ├── player.xpm
│   ├── wall.xpm
│   ├── collectible.xpm
│   ├── exit.xpm
│   ├── exit_open.xpm
│   └── floor.xpm
├── maps/
│   ├── normal.ber
│   ├── invalid_wall.ber
│   ├── invalid_shape.ber
│   ├── isolated_exit.ber
│   └── etc.
├── minilibx-linux/
├── libft/
│   ├── libft.h
│   ├── ft_strlen.c
│   ├── ft_printf.c
│   └── get_next_line.c
└── Makefile
```

## Modules

### Map parsing & validation
- Parse the map: incl. 0, 1, P, C, E
- Validate the map
    - Map shape need to be rectangle
    - Surrounded by wall '1'
    - Only 1 player, 1 exit, and > 0 collectibles
- Check the accessibility of the exit & collectibles
    - Use flood fill algo
### Initialize the Window
- Set up the win with proper dimension based on map size
- Create connection to the display
- Handle window creation
### Load game texture
- Load xpm file for each game element: incl. player, collectible, exit, floor, wall
- Convert xpm files to images using mlx_xpm_file_to_image
- Error handling for image loading
### Render the texture
- Convert map characters (0, 1, P, C, E) to coresponding images, using mlx_put_image_to_window
- Draw each element in the correct position
### Handle player movement & Key events
- Implement key hook for WASD and arrow keys
- Validate the move (avoid out of scope or wall collision)
- Update player position based on key input
- Count move and display the Count
- Implement hook for exit by pressing ESC or clicking the cross
### Game logic
- Track collected collectibles
- Check win condition (all collectibles gathered && reach exit)
- Handle game completion
### Cleanup and exit
- Free all allocated Resources
- Destroy win and the connection

## Related files & notes
### Map parsing & validation
- map.c
    - int count_map_height(char *map)
    - int parse_map(t_game *game, char *map)
        - need to remove get_next_line's '\n' at the end, otherwise maps are always invalid
- map_validate.c
    - int	check_shape(t_game *game)
    - int	check_wall(t_game *game)
    - int	check_item(t_game *game)
    - int	item_helper(t_game *game, int *exit_count, int *player_count, int *collectible_count)
    - int	validate_map(t_game *game)
- map_floodfill.c
    - void	player_pos(t_game *game, int *player_x, int *player_y)
    - int	**duplicate_map(t_game *game)
    - void	free_tempmap(int **temp_map, int height)
    - void	flood_fill(t_game *game, int **temp_map, int x, int y)
    - int	check_accessibility(t_game *game, int **temp_map)

### Initialize the Window
- init.c
    - void	init_game(t_game *game)

### Load the textures
- init.c 
    - void	*load_single_texture(void *mlx, char *path, int *width, int *height)
    - void	load_texture(t_game *game)
    - void	cleanup_texture(t_game *game)

### Render the texture
- render.c 
    - void	render_texture(t_game *game, int i, int j)
        - helper function for render_map
    - void	render_map(t_game *game)
    - void	render_player(t_game *game)
    - int	render_frame(t_game *game)

### Handle player movement & Key events
- movement.c 
    - void	cal_newposition(t_game *game, int *new_x, int *new_y)
    - int	validate_move(t_game *game, int new_x, int new_y)
    - void	move_player(t_game *game, int dx, int dy)

### Game logic
- movemment.c 
    - void	handle_interactions(t_game *game, int new_x, int new_y)
    - void	update_gamestate(t_game *game, int new_x, int new_y)
- movement_key.c 
    - int	keypress(int keycode, t_game *game)
    - int	cross_close(t_game *game)

### Cleanup and exit
- cleanup.c 
    - void	free_map(t_game *game)
    - void	cleanup(t_game *game)

### Main function
- main_solong.c 
    - input validation: need a map first
    - initialize the struct with 0
    - map
        - parse the map
        - check items and validate the map
    - initialize the game
    - game
        - update player position
        - continously listen to key hook
        - continously render the frame 
        - handle exit
        - cleanup everything

