#include <stdio.h>

namespace DaysGoneMenuUI {

    // Lista de opções que aparecerão no ecrã do Days Gone
    const char* menuItems[] = {
        "-> Vida Infinita (God Mode)",
        "-> Estamina Infinita",
        "-> Munição Infinita",
        "-> Créditos de Acampamento (+1000)",
        "-> Fechar Menu"
    };

    const int totalOptions = 5;

    // Função conceitual para renderizar o menu na tela do PS4
    void DrawMenu(bool isOpen, int selectedIndex) {
        if (!isOpen) return;

        // Aqui entrariam as chamadas de desenho gráfico (OpenOrbis / GNM)
        // Exemplo de representação visual do cabeçalho:
        // "--- DAYS GONE HAVANA MENU (CUSA08966) ---"

        for (int i = 0; i < totalOptions; i++) {
            if (i == selectedIndex) {
                // Desenha a linha destacada (item selecionado com o D-Pad)
                // Ex: Fundo marcado ou cor diferente
            } else {
                // Desenha a linha normal
            }
        }
    }
}
