# VEXcode makefile 2019_03_26_01

# show compiler output
VERBOSE = 0

# include toolchain options
include vex/mkenv.mk

# location of the project source cpp and c files
SRC_C  = $(wildcard src/*.cpp) 
SRC_C += $(wildcard src/*.c)
SRC_C += $(wildcard src/*/*.cpp) 
SRC_C += $(wildcard src/*/*.c)

OBJ = $(addprefix $(BUILD)/, $(addsuffix .o, $(basename $(SRC_C))) )

# location of include files that c and cpp files depend on
SRC_H  = $(wildcard include/*.h)

# additional dependancies
SRC_A  = Makefile

# project header file locations
INC_F  = include


# build targets
all: $(BUILD)/$(PROJECT).bin

########################

ALL_FILES = $(SRC_C)
ALL_FILES+= $(wildcard $(INC_F)/*.h)

.PHONY: format
format: $(ALL_FILES)
	clang-format -i $?

# include build rules
include vex/mkrules.mk
