################################################################################
# These are variables for the GBA toolchain build
# You can add others if you wish to
# ***** YOUR NAME HERE *****
################################################################################

# The name of your desired GBA game
# This should be a just a name i.e MyFirstGBAGame
# No SPACES AFTER THE NAME.
# Program Name
# Makefile for Brick Breaker GBA Game

# Makefile for Brick Breaker GBA Game

# DevKitPro Paths
DEVKITPRO = /opt/devkitpro
DEVKITARM = $(DEVKITPRO)/devkitARM

# Toolchain - use full paths
CC = $(DEVKITARM)/bin/arm-none-eabi-gcc
OBJCOPY = $(DEVKITARM)/bin/arm-none-eabi-objcopy

# Program Name
PROGNAME = BrickBreaker

# Object Files
OFILES = game.o myLib.o titlescreen.o text.o font.o image.o ball.o paddle.o winScreen.o loseScreen.o

# Header Files
HFILES = myLib.h titlescreen.h text.h ball.h paddle.h winScreen.h loseScreen.h

# Include and Library Paths
INCLUDE = $(DEVKITPRO)/libgba/include
LIB = $(DEVKITPRO)/libgba/lib

# Compiler Flags
CFLAGS = -mthumb -mthumb-interwork -mcpu=arm7tdmi 
CFLAGS += -Wall -O2 -fno-pic -std=c99
CFLAGS += -fno-strict-aliasing -fno-inline
CFLAGS += -I$(INCLUDE) -I.

# Linker Flags
LDFLAGS = -mthumb -mthumb-interwork -mcpu=arm7tdmi 
LDFLAGS += -L$(LIB)

# Output Binaries
ELF = $(PROGNAME).elf
GBA = $(PROGNAME).gba

# Default target
all: $(GBA)

# Create .gba file from .elf
$(GBA): $(ELF)
	$(OBJCOPY) -v -O binary $< $@

# Link object files into .elf
$(ELF): $(OFILES)
	$(CC) $(LDFLAGS) -specs=$(DEVKITARM)/arm-none-eabi/lib/gba.specs $^ -lgcc -lc -o $@

# Compile source files into object files
%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f *.o $(ELF) $(GBA)

# Optional emulator targets
vba: $(GBA)
	open -a VisualBoyAdvance $<

mgba: $(GBA)
	mgba $<

# Debugging target
info:
	@echo "DEVKITPRO: $(DEVKITPRO)"
	@echo "DEVKITARM: $(DEVKITARM)"
	@echo "Compiler: $(CC)"
	@$(CC) --version

# Phony targets
.PHONY: all clean vba mgba info