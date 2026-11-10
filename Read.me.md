# DaysGone-Havana-Menu (PS4 / GoldHEN)

Projeto de pesquisa, engenharia reversa e desenvolvimento experimental focado em adaptar a estrutura visual de mod menus de PS4 (baseados no ecossistema OpenOrbis / GoldHEN) para o jogo **Days Gone** (Unreal Engine 4 - CUSA08966).

> **Aviso de Isenção / Disclaimer:** Este repositório destina-se estritamente a fins educacionais, de pesquisa de software e estudo de arquitetura de homebrew para o PlayStation 4.

---

## 🎯 Objetivos do Projeto

- [ ] Mapear ponteiros de memória (*offsets*) do Days Gone (CUSA08966 - Versão US).
- [ ] Implementar gancho de renderização (*hook*) compatível com o ecossistema GoldHEN Plugins (`.prx`).
- [ ] Adaptar a interface gráfica de navegação de menus abertos (como a base OpenOrbis/2much4u).
- [ ] Desenvolver rotinas em C/C++ para alteração de atributos do jogador (Saúde, Munição, Créditos de Acampamento).

---

## 📁 Estrutura de Pastas

```text
├── docs/               # Documentação técnica e tabelas de ponteiros (offsets)
├── src/                # Código-fonte principal do plugin (C/C++)
│   ├── gui/            # Interface visual e navegação
│   ├── hooks/          # Injeção de memória no processo do jogo
│   └── game/           # Funções de cheats (God Mode, Ammo, etc.)
├── include/            # Headers do SDK (OpenOrbis / GoldHEN)
└── Makefile            # Script de compilação do plugin .prx
