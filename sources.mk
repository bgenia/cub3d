SRC@src := \
	src/render/renderer/renderer_create_frame.c \
	src/render/renderer/renderer_destroy.c \
	src/render/renderer/renderer_render_next_frame.c \
	src/render/renderer/renderer_init.c \
	src/render/image/image_create.c \
	src/render/image/image_destroy.c \
	src/render/image/image_load_xpm_file.c \
	src/render/image/image_get_pixel.c \
	src/render/window/window_create.c \
	src/render/window/window_draw_image.c \
	src/render/window/window_destroy.c \
	src/render/raycasting/cast_ray.c \
	src/render/raycasting/ray_cast.c \
	src/render/raycasting/ray_create_vertical.c \
	src/render/raycasting/ray_create_horizontal.c \
	src/render/graphics/brush_square.c \
	src/render/graphics/image_draw_rect.c \
	src/render/graphics/image_draw_line.c \
	src/render/graphics/image_draw_brush.c \
	src/render/graphics/image_draw_circle.c \
	src/render/graphics/image_fill_rect.c \
	src/render/graphics/image_fill_circle.c \
	src/render/graphics/image_fill.c \
	src/render/graphics/image_fill_pixel.c \
	src/render/graphics/brush_circle.c \
	src/render/color/color_create.c \
	src/render/color/color_parse.c \
	src/render/color/color_get_component.c \
	src/render/color/color_multiply_components.c \
	src/vecmath/vec_rotate.c \
	src/vecmath/vec_direction_to.c \
	src/vecmath/vec_length.c \
	src/vecmath/vec_cross.c \
	src/vecmath/vec_add.c \
	src/vecmath/vec_normalize.c \
	src/vecmath/vec_direction.c \
	src/vecmath/vec_dot.c \
	src/vecmath/vec_scale.c \
	src/vecmath/vec_distance.c \
	src/parser/parse_cub_file.c \
	src/parser/cub_file_destroy.c \
	src/parser/validate_map_char.c \
	src/parser/validate_file_extension.c \
	src/map/map_create.c \
	src/map/map_push_char.c \
	src/map/map_print.c \
	src/map/map_destroy.c \
	src/map/map_get.c \
	src/map/map_push_line.c \
	src/map/map_add_line.c \
	src/asset_manager/asset_manager_load_assets.c \
	src/asset_manager/asset_manager_create.c \
	src/asset_manager/asset_manager_free_assets.c \
	src/game/render/game_render_next_frame.c \
	src/game/render/game_render_column.c \
	src/game/render/pick_texture.c \
	src/game/hooks/handle_key_press.c \
	src/game/hooks/register_hooks.c \
	src/game/hooks/handle_exit.c \
	src/game/hooks/handle_frame.c \
	src/game/hooks/handle_key_release.c \
	src/game/game/game_display_destroy.c \
	src/game/game/game_init.c \
	src/game/game/game_loop.c \
	src/game/game/game_destroy.c \
	src/game/game/game_update.c \
	src/game/game/game_display_init.c \
	src/game/game/game_setup.c \
	src/main.c \
