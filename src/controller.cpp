#include <stdint.h>

namespace DaysGoneInput {

    // IDs dos botões do DualShock no ecossistema Orbis / PS4
    enum PS4Buttons {
        BUTTON_UP     = 0x0001,
        BUTTON_DOWN   = 0x0002,
        BUTTON_LEFT   = 0x0004,
        BUTTON_RIGHT  = 0x0008,
        BUTTON_CROSS  = 0x0100, // Botão X
        BUTTON_CIRCLE = 0x0200, // Botão Bola
        BUTTON_L1     = 0x0400,
        BUTTON_R1     = 0x0800
    };

    // Estado atual do menu
    bool isMenuOpen = false;
    int currentSelectedIndex = 0;
    const int maxMenuItems = 5; // Exemplo: 5 opções no menu

    // Função para detetar os comandos do controle durante o jogo
    void ProcessControllerInput(uint32_t buttonState) {
        
        // Exemplo: Atalho para abrir/fechar o menu (Ex: R1 + Quadrado / ou L1 + R1)
        // Se a combinação for pressionada:
        // isMenuOpen = !isMenuOpen;

        if (!isMenuOpen) return;

        // Navegação para cima no menu
        if (buttonState & BUTTON_UP) {
            currentSelectedIndex--;
            if (currentSelectedIndex < 0) {
                currentSelectedIndex = maxMenuItems - 1; // Dá a volta para o final
            }
        }

        // Navegação para baixo no menu
        if (buttonState & BUTTON_DOWN) {
            currentSelectedIndex++;
            if (currentSelectedIndex >= maxMenuItems) {
                currentSelectedIndex = 0; // Dá a volta para o início
            }
        }

        // Confirmação com o botão X (Cross)
        if (buttonState & BUTTON_CROSS) {
            // Executa a função do item selecionado (ex: ativar God Mode)
        }
    }
}
