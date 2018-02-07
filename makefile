out/envsort: envsort.c
	gcc --std=c11 -g -Wall -O3 $^ -o $@

clean:
	rm -rfv out/*
