MKOCTFILE=mkoctfile

# CXXFLAGS = -std=c++0x 

FILES = subs_spice_netlist.oct

all: $(FILES)

%.oct: %.cpp
	$(MKOCTFILE) $<

clean:
	rm *.o
	rm $(FILES)

