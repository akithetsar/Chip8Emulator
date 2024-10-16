//
// Created by akith on 10/15/2024.
//

//todo: add rom extension checking(ex. .ch8)
#include <cstdint>
#include <fstream>
#include <iostream>

#ifndef CHIP8EMULATOR_CHIP8_H
#define CHIP8EMULATOR_CHIP8_H
class Chip8 {

public:

    static Chip8* Instance(){
        if(!m_instance){
            m_instance = new Chip8();
        }
        return m_instance;
    }

    void loadRom(char const* path){

        std::ifstream file(path, std::ios::binary | std::ios::ate);

        if (!file) {
            std::cerr << "Error: Could not open the file." << std::endl;
            return;
        }

        // Get the size of the file
        std::streamsize fileSize = file.tellg();
        file.seekg(0, std::ios::beg);

        // Ensure the ROM will fit into memory
        if (fileSize > (4096 - PROGRAM_START_ADDR)) {
            std::cerr << "Error: ROM size is too large to fit in memory." << std::endl;
            file.close();
            return;
        }

        // Read the ROM into memory
        if (file.read(reinterpret_cast<char *>(m_memory + PROGRAM_START_ADDR), fileSize)) {
            std::cout << "ROM loaded successfully. Size: " << fileSize << " bytes." << std::endl;
        } else {
            std::cerr << "Error: Could not read the entire ROM file." << std::endl;
        }


    }


protected:
    Chip8() : m_pc(PROGRAM_START_ADDR), m_sp(0) {

        // Load fonts into memory
        for (unsigned int i = 0; i < FONTSET_SIZE; ++i)
        {
            m_memory[FONTSET_START_ADDR + i] = fontset[i];
        }


    }

private:

    static Chip8 *m_instance;

    uint8_t m_memory[4096]{};
    uint8_t m_regs[16]{};
    uint16_t m_stack[16]{};
    uint16_t m_address_reg{};
    uint16_t m_pc;
    uint8_t m_sp;
    uint8_t m_delayTimer{};
    uint8_t m_soundTimer{};
    uint8_t m_keypad[16]{};
    uint32_t m_video[64 * 32]{};
    uint16_t m_opcode{};

    static constexpr char ROM_EXTENSION[8] = "ch8";
    static constexpr unsigned int PROGRAM_START_ADDR = 0x200;

    static constexpr unsigned int FONTSET_START_ADDR = 0x50;
    static constexpr unsigned int FONTSET_SIZE = 80;
    static constexpr uint8_t fontset[FONTSET_SIZE] =
            {
                    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
                    0x20, 0x60, 0x20, 0x20, 0x70, // 1
                    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
                    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
                    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
                    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
                    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
                    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
                    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
                    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
                    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
                    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
                    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
                    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
                    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
                    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
            };
};

Chip8 *Chip8::m_instance = nullptr;
#endif //CHIP8EMULATOR_CHIP8_H
