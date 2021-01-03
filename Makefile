LIBRARIES = -lSDL2 -lSDL2_mixer 
NAME = SDL_Thing.output
FILES = source/main.cpp
#To change the output to, .exe, .AppImage or to .output when you're not on the right os change the var
OS = Windows_MT
#Windows_MT - for windows, Linux - for Linux, Anything else - .output

ifeq ($(OS), Linux)
	NAME = SDL_Thing.AppImage
endif
ifeq ($(OS), Windows_MT)
	NAME = SDL_Thing.exe
endif

create:
	@echo "Creating file"
	g++ $(FILES) $(LIBRARIES) -o $(NAME) 