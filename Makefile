# Compilers 
CCC = g++  
CXX = g++  
# Flags
BASICOPTS = -g -Wall -Werror -std=c++14 
CCFLAGS = $(BASICOPTS)
CXXFLAGS = $(BASICOPTS)
CCADMIN = 

.PHONY: pre_compile all clean

# Target directory
TARGETDIR = server
#
EXEC = $(TARGETDIR)/server
# Directory for object files `.o`
OBJS = $(TARGETDIR)/ofiles
# Paths to Boost library
INCLUDES = -L/usr/local/include -L/usr/local/lib
INCLUDES_LIB = -I/usr/local/include
SOURCES = src
LDFLAGS = -lboost_system -lboost_thread -lpthread
OFILES = $(OBJS)/main.o \
	 $(OBJS)/server.o \
	 $(OBJS)/connection.o \
	 $(OBJS)/connection_manager.o 
	
LD_PATH = /usr/local/lib

all: pre_compile compile end 

# Fix the error "while loading shared library"
pre_compile: 
	export LD_LIBRARY_PATH=LD_PATH

# Compile all the sources files
compile: $(EXEC)


$(EXEC): $(TARGETDIR) $(OBJS) $(OFILES)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OFILES) $(INCLUDES) $(LDFLAGS)

$(OBJS)/main.o: 
	$(CXX) -c $(CXXFLAGS) $(INCLUDES_LIB) $(SPECFLAGS) -o $(OBJS)/main.o main.cpp
	
$(OBJS)/server.o: 
	$(CXX) -c $(CXXFLAGS) $(INCLUDES_LIB) $(SPECFLAGS) -o $(OBJS)/server.o $(SOURCES)/server.cpp

$(OBJS)/connection.o: 
	$(CXX) -c $(CXXFLAGS) $(INCLUDES_LIB) $(SPECFLAGS) -o $(OBJS)/connection.o $(SOURCES)/connection.cpp
	
$(OBJS)/connection_manager.o: 
	$(CXX) -c $(CXXFLAGS) $(INCLUDES_LIB) $(SPECFLAGS) -o $(OBJS)/connection_manager.o $(SOURCES)/connection_manager.cpp



clean:
	rm -r -f $(OBJS)

end:
	rm $(OBJS)/main.o
	rm -rf $(OBJS)
	

$(TARGETDIR):
	mkdir -p $(TARGETDIR)

$(OBJS):
	mkdir -p $(OBJS)
