test: clean main.o
	bash test.sh "im not dog no" "im not dog no"
	
main.o:
	gcc main.c -o main.o

clean:
	rm -rf *.o *~ main
	
