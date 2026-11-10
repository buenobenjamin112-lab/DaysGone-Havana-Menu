#include <stdint.h>
#include <math.h>

namespace DaysGoneHavana {

    // Estruturas de dados da Unreal Engine 4
    struct Vector3 {
        float x, y, z;
    };

    struct Rotator {
        float pitch, yaw, roll;
    };

    struct UE4Offsets {
        uintptr_t gWorld          = 0x0;
        uintptr_t localPlayer     = 0x0;
        uintptr_t actorLocation   = 0x0; // Offset do FVector de Posição (X, Y, Z)
        uintptr_t actorRotation   = 0x0; // Offset do FRotator (Pitch, Yaw, Roll)
        uintptr_t hordeDirector   = 0x0;
    };

    uintptr_t gameBaseAddress = 0x0;
    UE4Offsets offsets;

    // Obtém a posição exata (X, Y, Z) do Deacon no mapa
    Vector3 GetPlayerPosition() {
        if (gameBaseAddress == 0 || offsets.gWorld == 0) return { 0.0f, 0.0f, 0.0f };

        uintptr_t gWorldPtr = *(uintptr_t*)(gameBaseAddress + offsets.gWorld);
        if (!gWorldPtr) return { 0.0f, 0.0f, 0.0f };

        uintptr_t playerPawn = *(uintptr_t*)(gWorldPtr + offsets.localPlayer);
        if (!playerPawn) return { 0.0f, 0.0f, 0.0f };

        return *(Vector3*)(playerPawn + offsets.actorLocation);
    }

    // Obtém a rotação para onde o jogador está virado
    Rotator GetPlayerRotation() {
        if (gameBaseAddress == 0 || offsets.gWorld == 0) return { 0.0f, 0.0f, 0.0f };

        uintptr_t gWorldPtr = *(uintptr_t*)(gameBaseAddress + offsets.gWorld);
        if (!gWorldPtr) return { 0.0f, 0.0f, 0.0f };

        uintptr_t playerPawn = *(uintptr_t*)(gWorldPtr + offsets.localPlayer);
        if (!playerPawn) return { 0.0f, 0.0f, 0.0f };

        return *(Rotator*)(playerPawn + offsets.actorRotation);
    }

    // 1. Spawnar Galão de Gasolina exatamente à frente do jogador
    void SpawnGasCanolineAtPlayer() {
        if (gameBaseAddress == 0) return;

        Vector3 pos = GetPlayerPosition();
        Rotator rot = GetPlayerRotation();

        // Converte o Yaw (ângulo horizontal) para radianos para calcular o vetor de frente
        float radYaw = rot.yaw * (3.14159265f / 180.0f);
        
        // Coloca o galão 150 unidades (aprox. 1.5 metros) à frente do olhar do Deacon
        Vector3 spawnTarget;
        spawnTarget.x = pos.x + (cosf(radYaw) * 150.0f);
        spawnTarget.y = pos.y + (sinf(radYaw) * 150.0f);
        spawnTarget.z = pos.z; // Mesma altura dos pés do jogador

        // Aqui é feita a chamada de Spawn da classe da gasolina usando as coordenadas 'spawnTarget'
    }

    // 2. Spawnar Horda de Freakers ao redor da localização do jogador
    void SpawnHordeAtPlayerLocation(int count) {
        if (gameBaseAddress == 0 || count <= 0) return;

        Vector3 pos = GetPlayerPosition();

        // Passa a posição exata (pos.x, pos.y, pos.z) para o Horde Director acionar o evento
        uintptr_t hordeDirectorPtr = *(uintptr_t*)(gameBaseAddress + offsets.hordeDirector);
        if (hordeDirectorPtr != 0) {
            // Força a injeção da posição e quantidade no spawner de Freakers
        }
    }
}
