CC=g++
CFLAGS=-c -Wall 
CFLAGS_OPENCV= -I /usr/global/opencv/2.2/include/opencv -I /usr/global/opencv/2.2/include/
LIBS_OPENCV= -L /usr/global/opencv/2.2/lib -lopencv_highgui -lopencv_core -lopencv_imgproc 

all: demo try

try: try.o cvShowManyImages.o
	$(CC) $(LIBS_OPENCV) try.o cvShowManyImages.o -o try 

cvShowManyImages.o: cvShowManyImages.cpp
	$(CC) $(CFLAGS) $(CFLAGS_OPENCV) cvShowManyImages.cpp

try.o: try.cpp
	$(CC) $(CFLAGS) $(CFLAGS_OPENCV) try.cpp 

demo: MySIFT.o SIFT.o cvShowManyImages.o 
	$(CC) $(LIBS_OPENCV) MySIFT.o SIFT.o cvShowManyImages.o -o demo

MySIFT.o: MySIFT.cpp
	$(CC) $(CFLAGS) $(CFLAGS_OPENCV) MySIFT.cpp

SIFT.o: SIFT.cpp
	$(CC) $(CFLAGS) $(CFLAGS_OPENCV) SIFT.cpp

clean:
	rm -rf *.o demo try
