#include <stdio.h>

namespace DaysGoneMenuUI {

    const char* menuItems[] = {
        "-> Vida Infinita (God Mode)",
        "-> Munição Infinita",
        "-> [Spawn] Galão de Gasolina",
        "-> [Spawn] Horda de Freakers",
        "-> Fechar Menu"
    };

    const int totalOptions = 5;

    void DrawMenu(bool isOpen, int selectedIndex) {
        if (!isOpen) return;

        // Renderização visual dos elementos do menu na tela do PS4
        for (int i = 0; i < totalOptions; i++) {
            if (i == selectedIndex) {
                // Item destacado / selecionado pelo D-Pad
            } else {
                // Item normal
            }
        }
    }
}
