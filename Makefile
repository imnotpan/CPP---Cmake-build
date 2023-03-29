CC = x86_64-conda-linux-gnu-c++
PROJECT = activity
SRC = main.cpp 
CFLAGS = -g -Wall
LIBS = `pkg-config --cflags --libs opencv4`
$(PROJECT):$(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(PROJECT) $(LIBS)
clean:
	rm $(PROJECT)
