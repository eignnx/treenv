out/envsort: envsort.o
	gcc --std=c11 -g -Wall $^ -o $@

envsort.o: envsort.c terminal_colors.h

clean:
	rm -rfv out/*
