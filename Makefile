
---

### 2. `Makefile`
Crie um arquivo chamado exatamente `Makefile` (sem extensão nenhuma) e cole isto dentro dele:

```makefile
TARGET = DaysGoneHavana
OBJS = src/main.o src/cheats.o

# Configurações do OpenOrbis SDK / PS4 Toolchain
CXX = clang++
CC = clang
LD = ld.lld

CFLAGS = -O3 -Wall -fPIC
CXXFLAGS = $(CFLAGS) -std=c++11

LDFLAGS = -shared

all: $(TARGET).prx

$(TARGET).prx: $(OBJS)
	$(LD) $(LDFLAGS) -o $(TARGET).elf $(OBJS)

clean:
	rm -f src/*.o $(TARGET).elf $(TARGET).prx
