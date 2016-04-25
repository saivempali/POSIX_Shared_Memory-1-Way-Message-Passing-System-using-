programs: sharedLib writer reader

sharedLib: sharedLib.c
	gcc -c -fpic sharedLib.c -pthread
	gcc -shared -o libsharedLib.so sharedLib.o -pthread

writer: writer.cpp
	g++ -L/home/RA_Assignment -o writer writer.cpp -lsharedLib
	$ export LD_LIBRARY_PATH=/home/RA_Assignment:$LD_LIBRARY_PATH

reader: reader.cpp
	g++ -L/home/RA_Assignment -o reader reader.cpp -lsharedLib
	$ export LD_LIBRARY_PATH=/home/RA_Assignment:$LD_LIBRARY_PATH
	@echo Compilation Successful!

clean: 
	@rm writer reader
	@echo All programs are cleaned. Compile again.
