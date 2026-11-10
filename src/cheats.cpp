#include <stdint.h>

namespace DaysGoneCheats {
    // Endereço base do jogo na memória RAM do PS4
    uintptr_t gameBaseAddress = 0x0;[span_11](start_span)[span_11](end_span)

    // Estrutura de Offsets para o CUSA08966 (Days Gone US)
    struct PlayerOffsets {
        uintptr_t health = 0x0;    // A preencher após mapeamento da Unreal Engine[span_12](start_span)[span_12](end_span)
        uintptr_t stamina = 0x0;[span_13](start_span)[span_13](end_span)
        uintptr_t ammo = 0x0;[span_14](start_span)[span_14](end_span)
    };

    PlayerOffsets offsets;

    void ApplyGodMode(bool enable) {
        if (gameBaseAddress == 0) return;[span_15](start_span)[span_15](end_span)
        
        // Exemplo conceitual de escrita direta na RAM
        // uintptr_t* healthPtr = (uintptr_t*)(gameBaseAddress + offsets.health);
        // if (healthPtr) {
        //     *(float*)healthPtr = enable ? 99999.0f : 100.0f;
        // }
    }
}
