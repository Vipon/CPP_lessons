CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++14 -O3

BINDIR=bin
VPATH=$(BINDIR)
EXAMPLES=auto

all: prep $(EXAMPLES)


.PHONY: prep
.SILENT: prep
prep:
	if [ ! -d $(BINDIR) ]; then \
		mkdir $(BINDIR); \
	fi;


$(EXAMPLES): $(EXAMPLES).cpp
	$(CXX) $(CXXFLAGS) $< -o $(BINDIR)/$@

$(EXAMPLES)/exec: $(EXAMPLES)
	./$(BINDIR)/$(EXAMPLES)

clean:
	rm -f $(addprefix $(BINDIR)/,$(EXAMPLES))