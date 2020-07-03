BASE_DIR = ./
include $(BASE_DIR)/directives.mk

CC       = g++
FLAGS    = -g -Wno-unused-function
LIBS     = -lm -pthread -lGL -lGLU -lglut -lgraphics -lmenu_system
LIBPATHS = -L./kernel/ -L./graphics/ -L./menu_system/
INC      = -I./kernel/ -I./graphics/ -I./menu_system/
OBJDIR   = objdir

OBJS = $(OBJDIR)/main.o             \
       $(OBJDIR)/facade.o           \
       $(OBJDIR)/container.o        \
       $(OBJDIR)/derivative_units.o \
       $(OBJDIR)/draw_unit.o        \
       $(OBJDIR)/graphics.o         \
       $(OBJDIR)/job_manager.o      \
       $(OBJDIR)/jobs.o             \
       $(OBJDIR)/map.o              \
       $(OBJDIR)/math_utils.o       \
       $(OBJDIR)/pathfinding.o      \
       $(OBJDIR)/timer.o            \
       $(OBJDIR)/unit.o             \
       $(OBJDIR)/society.o          \
#

EXE = whee

.NOTPARALLEL: all

all: directories $(OBJS)
	cd graphics &&    $(MAKE) -f graphics.mk
	cd menu_system && $(MAKE) -f menu_system.mk
	$(CC) $(OBJS) $(FLAGS) $(LIBPATHS) $(LIBS) -o $(EXE)

directories:
	mkdir -p $(OBJDIR)

clean:
	$(MAKE) -C graphics    -f graphics.mk    clean
	$(MAKE) -C menu_system -f menu_system.mk clean
	rm $(OBJS) $(EXE)

$(OBJDIR)/%.o: %.cpp
	$(CC) $(INC) $(FLAGS) $^ $(DIRECTIVES) -c -o $@
