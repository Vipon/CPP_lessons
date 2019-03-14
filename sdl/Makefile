CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++14 -O3
INCLUDE=../include
LIB=SDL2

BINS=drawLine
EXEC_BINS=$(addprefix exec/,$(BINS))
BINDIR=bin
VPATH=$(BINDIR)

MODULES=mediaApp window render drawLine event point2D
mediaApp_DEPS=mediaApp.h graphException.h
window_DEPS=window.h graphException.h
render_DEPS=render.h window.h point2D.h
event_DEPS=event.h point2D.h
point2D_DEPS=point2D.h

drawLine_DEPS=mediaApp.h window.h render.h event.h point2D.h
drawLine_OBJS=drawLine.o window.o render.o mediaApp.o event.o point2D.o

OBJDIR=obj
vpath %.o $(OBJDIR)
OBJECTS=$(addsuffix .o, $(MODULES))

define create_object =
$(1).o: $(1).cpp $$($(1)_DEPS)
	$(CXX) $(CXXFLAGS) $$< -c -o $$@ $(addprefix -I,$(INCLUDE))
endef

define create_exec_file =
$(1): $$($(1)_OBJS)
	$(CXX) $(CXXFLAGS) $$^ -o $(BINDIR)/$$@ $(addprefix -l,$(LIB))
endef

all: prep $(BINS)


.PHONY: prep
.SILENT: prep
prep:
	if [ ! -d $(OBJDIR) ]; then \
		mkdir $(OBJDIR); \
	fi;
	if [ ! -d $(BINDIR) ]; then \
		mkdir $(BINDIR); \
	fi;


$(foreach mod,$(MODULES),$(eval $(call create_object,$(mod))))
$(foreach bin,$(BINS),$(eval $(call create_exec_file,$(bin))))


$(EXEC_BINS): exec/%: %
	./$(BINDIR)/$(notdir $<)


.PHONY: exec_all
exec_all: $(EXEC_BINS)


.PHONE: clean
clean:
	@rm -rf $(OBJDIR)
	@rm -rf $(BINDIR)
	@rm -f *.o
