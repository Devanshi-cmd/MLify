# Detect OS
ifeq ($(OS),Windows_NT)
# Windows
LDFLAGS = -L../lib/windows -lSDL2
TARGET = Bresenham_circle_SDL.exe
RM = del
else
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
# Linux
LDFLAGS = -L../lib/linux -lSDL2 -Wl,-rpath,../lib/linux
TARGET = Bresenham_circle_SDL
RM = rm -f
else ifeq ($(UNAME_S),Darwin)
# Mac
LDFLAGS = -F../lib/mac -framework SDL2 -Wl,-rpath,@loader_path/../lib/mac
TARGET = Bresenham_circle_SDL
RM = rm -f
endif
endif

CFLAGS = -I../include

all: $(TARGET)

$(TARGET): Bresenham_circle_SDL.c
	gcc $(CFLAGS) Bresenham_circle_SDL.c $(LDFLAGS) -o $(TARGET)

clean:
	$(RM) $(TARGET)

run: all
	./$(TARGET)