CC       := g++
SRCDIR   := src
BUILDDIR := obj
CFLAGS   := -O3 -march=native -g -std=c++11 -Wall -Wextra
LDFLAGS  := -O3 -march=native -g -lgmpxx -lgmp
TARGET   := euler

SRCEXT   := cpp
SOURCES  := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS  := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
DEPS     := $(OBJECTS:.o=.deps)
P         = 0

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(addprefix $(BUILDDIR)/,util math euler)
	$(CC) -I $(SRCDIR) $(CFLAGS) -MD -MF $(@:.o=.deps) -c -o $@ $<

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)

problem:
	$(eval PNUM  := $(shell printf "%3d"  $(P)))
	$(eval PFILL := $(shell printf "%03d" $(P)))
	cp -n templates/eulerXXX.cpp $(SRCDIR)/euler/$(PFILL).cpp
	sed -i "s/XXX/$(PFILL)/g; s/SXX/$(PNUM)/g" $(SRCDIR)/euler/$(PFILL).cpp
	geany $(SRCDIR)/euler/$(PFILL).cpp &

-include $(DEPS)

.PHONY: clean problem
