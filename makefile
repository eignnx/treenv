out/envsort: envsort.c
	gcc --std=c11 -g -Wall $^ -o $@

clean:
	rm -rfv out/*
