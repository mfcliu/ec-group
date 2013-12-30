CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		ec-group.o

LIBS =

TARGET =	ec-group

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
