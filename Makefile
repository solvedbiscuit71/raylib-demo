CC=clang
FLAGS=-framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/libraylib.a

build:
	$(CC) $(FLAGS) my_app.c helper.c -o bin/my_app

debug-build:
	$(CC) $(FLAGS) my_app.c helper.c -o -g bin/my_app

run: build
	./bin/my_app

debug:
	lldb ./bin/my_app

