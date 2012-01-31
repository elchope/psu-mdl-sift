CC=g++
CFLAGS=-c -Wall 
CFLAGS_OPENCV= -I /usr/global/opencv/2.2/include/opencv -I /usr/global/opencv/2.2/include/
LIBS_OPENCV= -L /usr/global/opencv/2.2/lib -lopencv_highgui -lopencv_core -lopencv_imgproc 

all: demo

demo: MySIFT.o SIFT.o stdafx.o
	$(CC) $(LIBS_OPENCV) MySIFT.o SIFT.o stdafx.o -o demo


MySIFT.o: MySIFT.cpp
	$(CC) $(CFLAGS) $(CFLAGS_OPENCV) MySIFT.cpp

SIFT.o: SIFT.cpp
	$(CC) $(CFLAGS) $(CFLAGS_OPENCV) SIFT.cpp

clean:
	rm -rf *.o demo
