test: clean main.o
	bash test.sh "dog2.txt" "163 164 0 114 13 101 21 7 4 139"
	
main.o:
	gcc main.c -o main.o

clean:
	rm -rf *.o *~ main
	
