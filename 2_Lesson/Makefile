CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++14 -O3
INCLUDE=../include

BINDIR=bin
VPATH=$(BINDIR)

EXAMPLES=simpleClass testNamespace String
EXEC_EXAMPLES=$(addprefix exec/,$(EXAMPLES))

all: prep $(EXAMPLES)


.PHONY: prep
.SILENT: prep
prep:
	if [ ! -d $(BINDIR) ]; then \
		mkdir $(BINDIR); \
	fi;


$(EXAMPLES): %: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $(BINDIR)/$@ -I $(addprefix -I,$(INCLUDE))


$(EXEC_EXAMPLES): exec/%: %
	./$(BINDIR)/$(notdir $<)


.PHONY: exec_all
exec_all: $(EXEC_EXAMPLES)


clean:
	rm -f $(addprefix $(BINDIR)/,$(EXAMPLES))
