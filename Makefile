CXX ?= clang++
CXXFLAGS := -Og -fsanitize=address -fsanitize=undefined
SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:src/%.cpp=o/%.o)
OUT := cute_string

o/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $(CWD)$@ -c

cute:
	mkdir -p o/
	$(MAKE) compile

compile: $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(OUT)

clean:
	rm -rf ./o $(OUT)

install: cute
