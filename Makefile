include maketools/common_config.mk
include maketools/source_list.mk
include maketools/add_library.mk

NAME := cub3d

SRC := $(call source_list,src)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)

LDLIBS += -lm -lz -lXext -lX11

export FT_OPTIONS := FT_MALLOC_EXIT

ifdef DEBUG_MODE
    export FT_OPTIONS := FT_MALLOC_ABORT
    FT_TARGET := debug
endif

define .LIBRARIES
    lib/libft/libft.a:lib/libft/include:$(FT_TARGET)
    lib/libmlx/libmlx.a:lib/libmlx
endef

include maketools/add_libraries.mk

include maketools/common_rules.mk

-include $(OBJ:.o=.d)
