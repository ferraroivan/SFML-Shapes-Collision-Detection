all: compile link clean

compile:
	g++ -c -std=c++17 main.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include -DSFML_STATIC

link:
	g++ main.o -o main -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f *.o
