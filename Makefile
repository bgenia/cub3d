include maketools/common_config.mk
include maketools/source_list.mk
include maketools/add_library.mk

NAME := cub3d

SRC := $(call source_list,src)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)

LDLIBS += -lm -lz -lXext -lX11

$(call add_library,lib/libmlx/libmlx.a,lib/libmlx)

export FT_OPTIONS := FT_MALLOC_EXIT

ifdef DEBUG_MODE

export FT_OPTIONS := FT_MALLOC_ABORT

FT_TARGETS := debug

endif

$(call add_library,lib/libft/libft.a,lib/libft/include,,$(FT_TARGETS))

include maketools/common_rules.mk

-include $(OBJ:.o=.d)
