TARGET = enterBootloader
TYPE = ps-exe

SRCS = \
main.cpp

CPPFLAGS=-DPSYQO_RELEASE

include third_party/nugget/psyqo/psyqo.mk
