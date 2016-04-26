#all: dynamic_array test

dynamic_array.o: dynamic_array.c
	gcc -c dynamic_array.c -fPIC -o dynamic_array.o 
	gcc -shared -Wl,-soname,libdynarry.so -o libdynarry.so.1.0.1 dynamic_array.o
	ln -s libdynarry.so.1.0.1 libdynarry.so

test: test.c
	gcc test.c -ldynarry -L . -o test

clean:
	rm *.o
	rm *.so
	rm *.so.*
