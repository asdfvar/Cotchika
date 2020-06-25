BASE_DIR = ../

include $(BASE_DIR)/directives.mk

CC = g++

INC = -I $(BASE_DIR)

FLAGS = -g

OBJDIR = objdir

OBJS = \
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

LIBNAME = libsociety.a

all: directories $(OBJS)
	ar rcs $(LIBNAME) $(OBJS)

directories:
	@mkdir -p $(OBJDIR)

clean:
	rm -r $(OBJDIR) $(LIBNAME)

$(OBJDIR)/%.o: %.cpp
	$(CC) $(INC) $(FLAGS) $^ $(DIRECTIVES) -c -o $@
