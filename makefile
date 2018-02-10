out/treenv: treenv.o
	gcc --std=c11 -g -Wall $^ -o $@

treenv.o: treenv.c terminal_colors.h

clean:
	rm -rfv out/*
	rm *.o
