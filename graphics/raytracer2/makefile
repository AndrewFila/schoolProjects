raytracer: raytracer.o
	gcc -g -Wall -Wextra -std=gnu99 raytracer.o -o ray2 -lm

raytracer.o: raytracer.c
	gcc -std=gnu99 -c raytracer.c

clean:
	rm *.o *.png ray2
