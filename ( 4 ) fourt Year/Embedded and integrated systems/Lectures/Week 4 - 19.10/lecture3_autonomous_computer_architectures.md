**Date:** 19.10.26
**Subject:** ВАС 
**Lecture:** 3 (Лекция 3)
**Week:** 4 (Седмица 4)
**Presentation:** 2 (Презентация 2)

# Autonomous Computer Architectures (Автономни компютърни архитектури)

## TOC & introduction

Short overview of the notes (translated from Bulgarian; original terms are given in parentheses where useful).

1. **Classes (Класове)**: comparison of low / medium / high class embedded systems (processor, RAM, development cost, unit cost, production volume, lifetime).
2. **Multiple embedded systems in one device**: e.g. 3 in one camera.
3. **USB**: serial from the outside, but actually a bus.
4. **Memory types**: ROM, EEPROM, FLASH.
5. **Pipeline**: consists of stages.
6. **Cache level 1**: instruction and data split 50:50, L1 size over time.
7. **Logical and physical address / Virtual memory**.
8. **Trigger Gate** 
9. **Parallel vs Serial interface**: internal vs external, RS232 / USB.
10. **Timers**.
11. **Quartz oscillator**: SiO₂, 60+ kHz pulse, 5 V.
12. **ADC / DAC**: Analog/Digital and Digital/Analog converters.
13. **DPCM**: Differential Pulse Code Modulation.
14. **Sampling theorem**: minimum sampling frequency ×2; aperiodic signals?
15. **Other graphical interfaces** *(?)*.

---

# Page 1

## Classes (Класове)

| | Low (ниско) | Medium (средни) | High (високо) |
|---|---|---|---|
| Processor (процесор) | 8 bit | 16 bit | 32 bit |
| RAM (рам) | 16 KB | 64 KB – 1 MB | > 1 MB |
| Development cost (цена разработка) | 100K $ | 1M $ | 1M $ |
| Unit cost (цена единица) | 10 $ | 1000 $ | 10000 $ |
| Production volume (серийност) *(?)* | 100 | 10 000 | > 10K |
| Lifetime (живот) | months (месеци) | years (години) | long (дълго) |

> **? "A bit doesn't sound right"** (малко не звучи правилно) *(personal remark, arrow points at the last rows of the table)*

## Multiple embedded systems in one device

**!** Several embedded systems in one, for example 3 in one camera.

## USB

- Serial: always serial comms from outside the pcb, but actually it is a bus inside

## Memory types

ROM, EEPROM, FLASH

## Pipeline

Pipeline → consists of *Stages*

## Cache

- Cache level 1 → Instruction & Data → 50:50 split
- L1 cache size is 64 KB since 19XX ~200X 
 - // note from me: има процесори с 384kb cache така че се е дигнало.

## Logical and physical address (Логически и физически адрес)

- \# Virtual memory (виртуална памет) **GOOD TO CHECK!!!**

## Trigger Gate

Trigger used to store bits via transistors

## Parallel vs Serial interface

- Parallel → Internal
- Serial → External
- RS232 / USB

## Timers (Таймери)


---

# Page 2

## Quartz oscillator (Кварцов осцилатор)

- switches from insulator into conductor (сменя от изолатор в проводник)
- Quartz oscillator: $\mathrm{SiO_2}$
- Diagram: crystal symbol with polarity (+ / −), supply $5\,\mathrm{V}$. ``` 5V +  -> --|□|-- -> Oscillating output```
- not aways good because problems in the quarts can create different changes in the oscilation output - one system is faster, other is slower by factor of 0.001
- Diagram: a rectangular pulse plotted on a time axis, marked with a width of $60+\,\mathrm{kHz}$.

## ADC / DAC

- **ADC / DAC**: Analog/Digital Converter (Аналогов/Цифров Преобразовател)
- Digital/Analog (Цифров/Аналогов)

## DPCM

**DPCM** – Differential PCM – Pulse Code Modulation

## Sampling theorem

- Theorem for the minimum sampling frequency of the signal: $\times 2$
  (i.e. $f_s \ge 2 f_{max}$ *(interpretation of the written "×2")*)
- Aperiodic signal?

## Other graphical interfaces

- Next lecture -graphical interfaces
