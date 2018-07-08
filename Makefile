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
INCLUDES = -L/usr/local/include -L/usr/local/lib
INCLUDES_LIB = -I/usr/local/include
SOURCES = src
LDFLAGS = -lboost_system -lboost_thread -lpthread
OFILES = $(OBJS)/main.o 
	
LD_PATH = /usr/local/lib

all: pre_compile compile end 

pre_compile: 
	export LD_LIBRARY_PATH=LD_PATH

# Compile all the sources files
compile: $(EXEC)


$(EXEC): $(TARGETDIR) $(OBJS) $(OFILES)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OFILES) $(INCLUDES) $(LDFLAGS)

$(OBJS)/main.o: 
	$(CXX) -c $(CXXFLAGS) $(INCLUDES_LIB) $(SPECFLAGS) -o $(OBJS)/main.o main.cpp



clean:
	rm -r -f $(OBJS)

end:
	rm $(OBJS)/main.o
	rm -rf $(OBJS)
	

$(TARGETDIR):
	mkdir -p $(TARGETDIR)

$(OBJS):
	mkdir -p $(OBJS)
	
