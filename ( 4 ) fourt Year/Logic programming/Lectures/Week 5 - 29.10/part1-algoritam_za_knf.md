# Алгоритъм за привеждане на съждителна формула в Конюнктивна Нормална форма (КНФ)

**Предмет:** ЛП (лекция)
**Дата:** 29.10.26
**Седмица:** 5
**Тема (горен ред на листа):** Конюнктивна нормална форма. Ще се разглежда

> Означение: $\varphi \mathrel{\dashv\vDash} \psi$ = логическа еквивалентност (в записките – двойно следване).

---

## TOC & introduction

В лекцията се въвеждат **литерал**, **дуален литерал**, **елементарна дизюнкция** и **КНФ**. След това се описва алгоритъм, който за произволна съждителна формула построява логически еквивалентна формула в КНФ, на няколко стъпки: (1) премахване на $\Leftrightarrow$, (2) премахване на $\Rightarrow$, (3) придвижване на отрицанията до променливите, (4) разпределяне на $\vee$ над $\&$. Страниците са по реда на качване (файлове 829 → 838); кръгли номера са на 2, 3, 4 и 5 страница, а неномерираните листове следват предишния.

1. **Литерали и дуален литерал** (стр. 1)
2. **Елементарна дизюнкция** (стр. 1 и 1-продължение)
3. **Определение на КНФ** (стр. 1-продължение)
4. **Стъпка 1: премахване на $\Leftrightarrow$** (стр. 2, 2-продължение, 3)
5. **Стъпка 2: премахване на $\Rightarrow$** (стр. 3 и 3-продължение)
6. **Стъпка 3: отрицания само пред променливи** (стр. 4 и 4-продължение)
7. **Следствие и стъпка 4: привеждане към КНФ** (стр. 5 и 5-продължение)

---

# ═══ Страница 1 (файл 1000029829) ═══

*(Горе: заглавие; горе вдясно в рамка: 29.10.26, ЛП-лекция, Седмица 5)*

## Алгоритъм за привеждане на съждителна формула в КНФ

## Литерал

**Дефо:** Литерал наричаме *(?)* формула от вида $P$ и $\neg P$. Означаваме с $L$.

$\neg L$ дали е литерал?

- $L \equiv P$, $\quad \neg L \equiv \neg P$ – да, литерал е
- $L \equiv \neg P$, $\quad \neg L \equiv \neg\neg P \mathrel{\dashv\vDash} P$ – (под $\neg\neg P$ стрелка) **не е**

*(Дясна колона:)* Това ни позволява да използваме отрицанието, но ни трябва подход да представим обратен на литерал *(?)*

## Дуален литерал

**Дефо:** Нека $L$ е литерал. **Дуален литерал** е литералът $L^{\partial}$, дефиниран така:

$$L^{\partial} \equiv \begin{cases} \neg P, & \text{ако } L \equiv P \\ P, & \text{ако } L \equiv \neg P \end{cases}$$

$$I:\quad \tilde I(L) = H_\neg\big(\tilde I(L^{\partial})\big)$$

$$\tilde I(L^{\partial}) = H_\neg\big(\tilde I(L)\big)$$

## Елементарна дизюнкция

**Дефо:** **Елементарна дизюнкция** е съждителна формула, която се получава само с операцията $\vee$ от литерали.

$$L_1 \qquad L_1 \vee L_2 \qquad (L_1 \vee L_2) \vee (L_3 \vee L_1)$$

Ако $E$ е елементарна дизюнкция и за построяването ѝ са използвани всички литерали $L_1, \dots, L_n$, казваме, че $E$ е елементарна дизюнкция на $L_1$ до $L_n$.

---

# ═══ Страница 1 – продължение (файл 1000029830) ═══

Литералите ги гледаме като едно цяло.

$$E \equiv (P_0 \vee \neg P_1) \vee (P_3 \vee \neg P_1)$$

← Тук литерал $L = P_1$ не е използван. Той се среща като поддума, но не и в построяването му. *(?)*

Колко са елементарните дизюнкции на $L_1 \dots L_n$ → **Много!**

$$\{P_0 \vee (\neg P_1 \vee (P_3 \vee \neg P_1))\}$$

**Твърдение:** Ако $E$ е елементарна дизюнкция на $L_1 \dots L_n$, то за $\forall$ б.оц. $I$ имаме

$$I \models E \iff \text{има поне 1 от } L_1 \dots L_n \text{ т.че } I \models L_i$$

---

$$E \equiv E_i \ \textit{(?)} \qquad E \text{ е елементарна дизюнкция на } E_i \ \textit{(?)}$$

$$E \equiv E_1 \vee E_2$$

## КНФ

**Дефо:** Казваме, че $P$ е в **КНФ**, ако $P$ е построена от елементарни дизюнкции само чрез използването на конюнкции.

1) Ако $E$ е елем. дизюнкция → $E$ е в КНФ.
2) $P_1$ и $P_2$ са в КНФ → $P_1 \,\&\, P_2$ е в КНФ.

$$P \equiv (P_1 \,\&\, P_2)$$

---

# ═══ Страница 2 (файл 1000029831, кръгъл номер 2) ═══

Нека $P$ е в КНФ.

Тогава $P \equiv E_1 \,\&\, E_2 \,\&\, E_3 \,\&\, \dots \,\&\, E_n$ и $n \ge 1$ съотв. *(?)*

*(Задраскано: $E_1$)*

$$(E_1 \,\&\, E_2) \,\&\, (E_3 \,\&\, \dots \,\&\, E_n)$$

**Твърдение:** За $\forall$ б.оц. $I$

$$I \models E_1 \,\&\, E_2 \,\&\, \dots \,\&\, E_n \iff I \models E_1 \text{ и } I \models E_2 \dots \text{ и } I \models E_n$$

## Премахване на $\Leftrightarrow$

**Твърдение:** Има алгоритъм, който по произволна съждителна формула $P$ дава съждителна формула $P_1$, такава че

- $P \mathrel{\dashv\vDash} P_1$
- във $P_1$ не се среща $\Leftrightarrow$ (еквивалентност)

**Док:** Инд. по построяване на $P$

- Ако $P \equiv P$, то резултатът е $P_1 \equiv P$
- Ако $P \equiv \neg\Psi$ и за $\Psi$ ал. е дефиниран, то $P_1 \equiv \neg\Psi_1$, където $\Psi_1$ е резултат от работата на алгоритъма за $\Psi$, т.е.
  - $\Psi \mathrel{\dashv\vDash} \Psi_1$
  - $\Psi_1$ няма $\Leftrightarrow$

  Тогава $\neg\Psi \mathrel{\dashv\vDash} \neg\Psi_1$ и обявяваме $\neg\Psi_1$ за резултата от работата на ал. над $\neg\Psi$.

---

# ═══ Страница 2 – продължение (файл 1000029832) ═══

- $P \equiv (\Psi_1 \,\sigma\, \Psi_2)$, където $\sigma \in \{\&, \vee, \Rightarrow\}$ (без $\Leftrightarrow$)

  и за $\Psi_1$ и $\Psi_2$ ал. е дефиниран.

  Нека $\Psi_1'$ и $\Psi_2'$ са резултат от работата на алгоритъма съотв. за $\Psi_1$ и $\Psi_2$:

  $$\begin{cases} \Psi_1 \mathrel{\dashv\vDash} \Psi_1' \\ \Psi_1' \text{ няма } \Leftrightarrow \end{cases} \qquad \begin{cases} \Psi_2 \mathrel{\dashv\vDash} \Psi_2' \\ \Psi_2' \text{ няма } \Leftrightarrow \end{cases}$$

  Тогава

  $$P \equiv (\Psi_1 \,\sigma\, \Psi_2) \mathrel{\dashv\vDash} (\Psi_1' \,\sigma\, \Psi_2')$$

  *(Задраскана бележка: „Ор. за рез. от работата на алгоритъм ф. $(\Psi_1'\sigma\Psi_2')$ ???" *(?)*)*

- $P \equiv (\Psi_1 \Leftrightarrow \Psi_2)$

  $$\begin{cases} \Psi_1 \mathrel{\dashv\vDash} \Psi_1' \\ \Psi_1' \text{ няма } \Leftrightarrow \end{cases} \qquad \begin{cases} \Psi_2 \mathrel{\dashv\vDash} \Psi_2' \\ \Psi_2' \text{ няма } \Leftrightarrow \end{cases}$$

  $$P \equiv (\Psi_1 \Leftrightarrow \Psi_2) \mathrel{\dashv\vDash} (\Psi_1 \,\&\, \Psi_2) \vee (\neg\Psi_1 \,\&\, \neg\Psi_2)$$

  $$\mathrel{\dashv\vDash} (\Psi_1' \,\&\, \Psi_2') \vee (\neg\Psi_1' \,\&\, \neg\Psi_2') \quad \text{– обявяваме като отговор на алгоритъма}$$

---

*(Друга възможност под чертата:)*

$$P \equiv (\Psi_1 \Rightarrow \Psi_2) \,\&\, (\Psi_2 \Rightarrow \Psi_1)$$

$$\mathrel{\dashv\vDash} (\Psi_1' \Rightarrow \Psi_2') \,\&\, (\Psi_2' \Rightarrow \Psi_1')$$

---

# ═══ Страница 3 (файл 1000029833, кръгъл номер 3) ═══

**Индукция относно срещанията на „$\Leftrightarrow$" във формулата $P$** ③

- Ако има 0 срещания → резултатът е готов

Вземаме едно срещане $P \equiv \{\ \dots(\varphi_1 \Leftrightarrow \varphi_2)\dots$

в $\varphi_1$ и $\varphi_2$ не се среща „$\Leftrightarrow$" (еквивалентност)

*(Сега заместване с теоремата/алгоритъма както описахме досега)*

*(Чертеж: дърво на формулата, в което избираме най-дълбокия възел $\Leftrightarrow$ – под него са две поддървета без $\Leftrightarrow$)*

```
          /\
         /  \
        / ⇔  \          да вземем срещане такова, че „⇔" го няма в
       /  |   \         поддърветата му, т.е. в дървото отдолу
      /   |    \
     Δ    Δ     A  ← (замества се)
     └────────────┘
```

## Премахване на $\Rightarrow$

Има алгоритъм, който по произволна съжд. формула $P$ дава съжд. формула $P_2$, такава че

$$\begin{cases} P_1 \mathrel{\dashv\vDash} P_2 \\ \text{във } P_2 \text{ не се среща } \Rightarrow \end{cases}$$

*(Пояснение:)* При това ако във $P$ няма „$\Leftrightarrow$", то и във $P_2$ няма „$\Leftrightarrow$" *(?)*

**Док:** Инд. по построяването, че

- $P \equiv P \to P_2 \equiv P$
- $P \equiv \neg\Psi$ и за $\Psi$ отговорът е дефиниран в $\Psi_2$:

  $$\begin{cases} \Psi \mathrel{\dashv\vDash} \Psi_2 \\ \Psi_2 \text{ няма срещане на „}\Rightarrow\text{"} \ \textit{(?)} \end{cases}$$

  $$P \equiv \neg\Psi \mathrel{\dashv\vDash} \neg\Psi_2$$

  в $\Psi_2$ няма „$\Rightarrow$"

---

# ═══ Страница 3 – продължение (файл 1000029834) ═══

- $P \equiv (\Psi' \,\sigma\, \Psi'')$, $\sigma \in \{\&, \vee\}$ и ал. е дефиниран за $\Psi'$ и $\Psi''$

  $$\begin{cases} \Psi' \mathrel{\dashv\vDash} \Psi_2' \\ \Psi_2' \text{ няма } \Rightarrow \end{cases} \qquad \begin{cases} \Psi'' \mathrel{\dashv\vDash} \Psi_2'' \\ \Psi_2'' \text{ няма } \Rightarrow \end{cases}$$

  $$P \equiv (\Psi' \sigma \Psi'') \mathrel{\dashv\vDash} (\Psi_2' \,\sigma\, \Psi_2''),\quad \sigma \in \{\&, \vee\}$$

  $$\begin{cases} P_2 \triangleq (\Psi_2' \,\sigma\, \Psi_2'') \\ \text{в } P_2 \text{ не се среща „}\Rightarrow\text{"} \end{cases}$$

- $P \equiv \Psi' \Leftrightarrow \Psi''$ и за $\Psi', \Psi''$ // $\Psi_2', \Psi_2''$

  $$P \mathrel{\dashv\vDash} (\Psi_2' \Leftrightarrow \Psi_2'') \quad (\text{няма } \Rightarrow) \ \textit{(?)}$$

- $P \equiv \Psi' \Rightarrow \Psi''$ ; $\Psi_2', \Psi_2''$

  $$P \equiv (\Psi' \Rightarrow \Psi'') \mathrel{\dashv\vDash} \neg\Psi' \vee \Psi'' \mathrel{\dashv\vDash} \neg\Psi_2' \vee \Psi_2''$$

  *(Алгоритъмът работи аналогично на този за „$\Leftrightarrow$")*

---

**II начин:** Инд. по броя на „$\Rightarrow$"

- 0 импликации: 0
- $n+1$ „$\Rightarrow$":

$$P \equiv \alpha(\Psi' \Rightarrow \Psi'')\beta \qquad \text{в } \Psi' \text{ и } \Psi'' \text{ няма „}\Rightarrow\text{"}$$

---

# ═══ Страница 4 (файл 1000029835, кръгъл номер 4) ═══

$$P \xrightarrow{\text{I ал}} P_1 \xrightarrow{\text{II ал}} P_2$$

$P$ след алгоритъм I е $P_1$:

$$\begin{cases} P \mathrel{\dashv\vDash} P_1 \\ \text{във } P_1 \text{ няма } \Leftrightarrow \end{cases} \qquad \begin{cases} P_1 \mathrel{\dashv\vDash} P_{12} \\ \text{във } P_{12} \text{ няма } \Rightarrow \end{cases}$$

Тогава $P \mathrel{\dashv\vDash} P_{1,2}$

във $P_{1,2}$ не се среща „$\Rightarrow$" и „$\Leftrightarrow$"

---

## Премахване на двойните отрицания и придвижване на $\neg$ към променливите

**Твърдение:** Има алгоритъм, който по дадена формула $P$ без „$\Rightarrow$" и „$\Leftrightarrow$", две формули *(?)* (логически еквивалентни), получени от литерали само с използването на *(?)* $\&$ и $\vee$ *(?)*

*(Диаграма:)* // няма $\Leftrightarrow, \Rightarrow$: $P_1 \longrightarrow P_3$

$$\begin{cases} P_3 \mathrel{\dashv\vDash} P \\ \text{всяко срещане на } \neg \text{ е от вида } \underline{\neg P} \end{cases} \quad \to \text{т.е. няма } \neg(\sim) \text{ и } \neg\neg(\sim)$$

---

**Док:** С индукция по дължината на $P$ доказваме тв.

- $P$ е с дължина 1: $P \equiv P$
- Нека $n$ е естествено число и за $\forall$ фо. с дължина $\le n$ алгоритъмът завършва по подходящ начин.

---

# ═══ Страница 4 – продължение (файл 1000029836) ═══

Нека $P$ е формула с дължина $n+1$.

Тогава е получена една от следните *(?)*:

- $P \equiv \neg\varphi'$
- $P \equiv (\varphi' \,\&\, \varphi'')$
- $P \equiv (\varphi' \vee \varphi'')$

*(Дясно:)* $P \equiv \neg\varphi'$ – случаи за $\varphi'$:

- $(*)$ $\varphi' \equiv P$
- $(**)$ $\varphi' \equiv \neg\Psi'$
- $(***)$ $\varphi' \equiv (\Psi' \,\sigma\, \Psi'')$, $\sigma \in \{\&, \vee\}$

---

~~$(*)\ P \mathrel{\dashv\vDash} \neg P$~~

$(**)$ $\quad P \mathrel{\dashv\vDash} \neg\neg\Psi' \mathrel{\dashv\vDash} \Psi' \qquad |\Psi'| < |P|$

$$\Psi' \longmapsto \Psi_3'$$

$(***)$ $\quad \varphi' \equiv (\Psi' \,\&\, \Psi'')$

$$P \equiv \neg(\Psi' \,\&\, \Psi'') \mathrel{\dashv\vDash} (\neg\Psi' \vee \neg\Psi'')$$

$|\neg\Psi'| < |P|$, $\ |\neg\Psi''| < |P|$

$$\neg\Psi' \longmapsto \tilde\Psi_3 \qquad \neg\Psi'' \longmapsto \tilde{\tilde\Psi}_3$$

$$P_3 \triangleq (\tilde\Psi_3 \vee \tilde{\tilde\Psi}_3)$$

---

$\varphi' \equiv (\Psi' \vee \Psi'')$

$$P \equiv \neg(\Psi' \vee \Psi'') \mathrel{\dashv\vDash} (\neg\Psi' \,\&\, \neg\Psi'')$$

$|\neg\Psi'| < |P|$, $\ |\neg\Psi''| < |P|$

$$\neg\Psi' \longmapsto \tilde\Psi_3 \qquad \neg\Psi'' \longmapsto \tilde{\tilde\Psi}_3$$

$$\mathrel{\dashv\vDash} (\tilde\Psi_3 \,\&\, \tilde{\tilde\Psi}_3)$$

---

# ═══ Страница 5 (файл 1000029837, кръгъл номер 5) ═══

**Следствие:** Има алгоритъм, който по произволна дадена съжд. фо. $P$ дава формула $P_0$, която има сл. св-ва:

$$\begin{cases} \bullet\ P \mathrel{\dashv\vDash} P_0 \\ \bullet\ \text{във } P_0 \text{ не се срещат } \Rightarrow, \Leftrightarrow \\ \bullet\ \text{всяко срещане на } \neg \text{ е непосредствено пред съжд. пром.}\ \alpha\neg P\beta \end{cases}$$

$P_0$ е построена от литерали само с изп. на $\&$ и $\vee$.

- Има алгоритъм, който от формулата $P_0$ дава формула $P_C$ в КНФ

  $$P_0 \mathrel{\dashv\vDash} P_C,\ \text{а значи и}\ P \mathrel{\dashv\vDash} P_C$$

**Док:** Инд. по дължината на формулата

- Ако $n$ е 1, тогава това е съжд. променлива и е в КНФ
- $P_0$ е във вида $(\chi_1 \,\&\, \chi_2)$ или $P_0 \equiv (\chi_1 \vee \chi_2)$

  $P \equiv (\chi_1 \,\&\, \chi_2)$, $\quad |\chi_1| < |P|$ и $|\chi_2| < |P|$

  $$\left.\begin{aligned} \chi_1 &\longmapsto \chi_{1C} \\ \chi_2 &\longmapsto \chi_{2C} \end{aligned}\right\}\ \text{КНФ}$$

  $$P \mathrel{\dashv\vDash} (\chi_{1C} \,\&\, \chi_{2C})$$

---

# ═══ Страница 5 – продължение (файл 1000029838) ═══

$$P \equiv (\chi_1 \vee \chi_2) \mathrel{\dashv\vDash} (\chi_{1C} \vee \chi_{2C}) \to \text{не е в КНФ}$$

**1 сл.** $\chi_{1C} \equiv E_1$ (елементарна дизюнкция), $\chi_{2C} \equiv E_2$

$\chi_{1C}$ и $\chi_{2C}$ е елем. дизюнкция и значи е в КНФ

**2 сл.** $\chi_{1C} \equiv (E_1 \,\&\, \chi_{1C}')$

$$(\chi_{1C} \vee \chi_{2C}) \mathrel{\dashv\vDash} \big((E_1 \,\&\, \chi_{1C}') \vee \chi_{2C}\big)$$

$$\mathrel{\dashv\vDash} (E_1 \vee \chi_{2C}) \,\&\, (\chi_{1C}' \vee \chi_{2C})$$

и това е по-късо, така че пак може да се приложи индукция

---

$$\chi_{1C} \equiv E_1 \,\&\, E_2 \,\&\, \dots \,\&\, E_n$$

$$\chi_{2C} \equiv E_1' \,\&\, E_2' \,\&\, \dots \,\&\, E_k'$$

$$\chi_{1C} \vee \chi_{2C} \mathrel{\dashv\vDash} (E_1 \vee E_1') \,\&\, (E_1 \vee E_2') \,\&\, \dots \,\&\, (E_1 \vee E_k') \,\&$$

$$(E_2 \vee E_1') \,\&\, (E_2 \vee E_2') \dots (E_2 \vee E_k')$$

$$\vdots$$

$$(E_n \vee E_1') \,\&\, \dots \dots (E_n \vee E_k')$$
