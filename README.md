# yeti-8

an 8-bit fantasy console

to compile assembly programs for it, look at https://github.com/yeti0904/y8sm

## specs

RAM: 65kB

## instructions
```
(0x00) NOP - does nothing
(0x01) STO [reg] [addr] - writes byte/s at [reg] into [addr]
(0x02) LD [reg] [addr] - loads byte/s at [addr] into [reg]
(0x03) RCP [regd] [regs] - copies [regs] to [regd]
(0x04) MOV [reg] [constant] - copies [constant] into [reg]
(0x05) MVI [reg] [constant] - copies [constant] into [reg] if accumulator is non-zero
(0x06) CMP [reg1] [reg2] - writes 255 to ac if both register's contents are equal, 0 if not
(0x07) ADD [reg1] [reg2] - adds contents of [reg1] and [reg2] together and saves in ac
(0x08) SUB [reg1] [reg2] - subtracts [reg2] from [reg1] and saves in ac
(0x09) MUL [reg1] [reg2] - multiplies [reg1] with [reg2] and saves in ac
(0x0A) DIV [reg1] [reg2] - divides [reg1] by [reg2] and saves in ac
(0x0B) NOT [reg] - performs bitwise not on [reg] and saves result in ac
(0x0C) PUSH [reg] - pushes the contents of [reg] into the stack
(0x0D) POP [reg] - decrements the stack pointer and puts the previous top of the stack in [reg]
(0xFF) HLT - stops execution of the program
```

### registers
```
(0x00) ac (8-bit) - accumulator
(0x01) sp (16-bit) - stack pointer
(0x02) pc (16-bit) - program counter
(0x03) hl (16-bot) - general purpose register
(0x04) r1 (8-bit) - general purpose register
(0x05) r2 (8-bit) - general purpose register
(0x06) r3 (8-bit) - general purpose register
(0x07) r4 (8-bit) - general purpose register
(0x08) r5 (8-bit) - general purpose register
(0x09) r6 (8-bit) - general purpose register
(0x0A) r7 (8-bit) - general purpose register
(0x0B) r8 (8-bit) - general purpose register
(0x0C) r9 (8-bit) - general purpose register
```