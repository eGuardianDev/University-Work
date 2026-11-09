# Припомняне: Дизюнкт. Метод на съждителната резолюция

**Предмет:** ЛП
**Дата:** 05.11.26 *(?)* (горният ред на датата е частично изрязан)
**Седмица:** 6
**Част 2** (в кутия при „Метод на съжд. резолюция")

> Заглавието е определено по съдържанието; горният ред на първата страница е „Припомняне: Дизюнкт – крайно м-во от литерали".

> Означение: $\mathcal{D}$ – дизюнкт, $\blacksquare$ – празен дизюнкт, $L^{\partial}$ – дуален литерал, $L_I = \{L \mid L \text{ е литерал и } I \models L\}$, $S \vdash \mathcal{D}$ – резолвентен извод.

---

## TOC & introduction

Лекция върху **метода на съждителната резолюция**: припомняне на дизюнкт и модел на множество от дизюнкти, свързване на множество от литерали с булева оценка, лема за резолвентата, **правило за съждителна резолюция**, **резолвентен извод**, **коректност** на резолютивния извод и затвореност $S^{*}$. В края на последния лист започва нова тема – **трансверзала на фамилия от множества**. Страниците са по реда на качване (файлове от 105532 до 105633); кръгли номера има на 2, 3, 4 и 5 страница; неномерираните листове следват предишния.

1. **Припомняне: дизюнкт, празен дизюнкт, модел на $S$** (стр. 1)
2. **Множество от литерали $U$ и оценка $I$: $U = L_I$** (стр. 1-продължение и стр. 2)
3. **Следствие и лема за резолвентата** (стр. 2-продължение, стр. 3)
4. **Правило за съждителна резолюция** (стр. 3 и 3-продължение)
5. **Резолвентен извод** (стр. 4)
6. **Коректност на резолютивния извод** (стр. 4-продължение, стр. 5 и стр. 5-продължение)
7. **Затвореност $S^{*}$** (стр. 5, стр. 5-продължение)
8. **Трансверзала за фамилия от множества** (последен лист)

---

# ═══ Страница 1 (файл 20261109_105532) ═══

*(Горе вдясно в рамка: дата, ЛП, Седмица 6)*

## Припомняне: дизюнкт

**Припомняне:** Дизюнкт – крайно м-во от литерали.

- **Празен дизюнкт.** Каквато и оценка да е – няма литерал → няма оценка (празният дизюнкт никога не е верен).

Елементарна дизюнкция $E \to \mathcal{D}$ (съответстващ дизюнкт)

$$I:\ I \models E \to I \models \mathcal{D}_E$$

*(Дясна бележка:)* формули и просто множество крайно (дизюнкт)

## Формула в КНФ и множество от дизюнкти

$$P \mathrel{\dashv\vDash} E_1 \,\&\, \dots \,\&\, E_n$$

$$I \models P \iff I \models E_1 \,\&\, \dots \,\&\, E_n$$

$$\iff I \models E_1 \text{ и } I \models E_2 \text{ и } \dots I \models E_n \iff I \models \{E_1, \dots, E_n\}$$

$$\iff I \models \mathcal{D}_1 \text{ и } I \models \mathcal{D}_2 \text{ и } \dots I \models \mathcal{D}_n$$

## Модел на множество от дизюнкти

**Дефо:** $S$ е множество от дизюнкти, $I$ е б.о.

$$I \models S \iff \text{за } \forall \text{ дизюнкт } \mathcal{D} \in S,\ I \models \mathcal{D}$$

$S \neq \emptyset \to$ за $\forall$ б.оц. $I$, $I \models S$ *(в оригинала е написано $\neq$; по смисъл вероятно $S = \emptyset$ *(?)*)*

$$I \models S \iff \text{за } \forall \text{ диз. } \mathcal{D} \in S,\ I \models \mathcal{D}$$

$$\iff \text{за } \forall \text{ диз. } \mathcal{D} \in S\ \text{има лит. } L \in \mathcal{D},\ I \models L$$

$$\iff \text{за } \forall \text{ диз. } \mathcal{D} \in S,\ \mathcal{D} \cap L_I \neq \emptyset$$

$$I \longmapsto L_I = \{L \mid L \text{ е литерал и } I \models L\}$$

Когато едно мн-во от литерали $U$ има *(?)* бул. оц. $I$ така че $U = L_I$.

Нека $U$ е м-во от литерали. Тогава следните са екв.:

---

# ═══ Страница 1 – продължение (файл 20261109_105538) ═══

Тогава следните са екв.:

1. Съществува б.оц. $I$, $\ U = L_I$
2. За $\forall$ произволно $P$ точно едно $P \in U$ или $\neg P \in U$

## (1) → (2)

Нека $U$ е мн-во от литерали и $\exists$ б.оц. $I$: $U = L_I$.

Нека $I_0$ е б.оц., $U = L_{I_0}$.

Нека $P$ е пр. пром.:

- $I_0 \models P$, тогава $P \in L_{I_0}$
- $I_0 \not\models P$, тогава $I_0 \models \neg P$, $\neg P \in L_{I_0}$

Тъй като е невъзможно $I_0 \models P$ и $I_0 \models \neg P$,

точно едно от тип. $P, \neg P$ е от $L_{I_0}$ и значи

тогава един от тип. $P, \neg P$ е от $U$.

## (2) → (1)

Нека за $\forall$ пром. $P$ тогава един от тип. $P, \neg P$ е от $U$.

Нека $P$ е произволна променлива.

$$I(P) \triangleq \begin{cases} \mathrm{И}, & P \in U \\ \mathrm{Л}, & P \notin U \end{cases}$$

---

# ═══ Страница 2 (файл 20261109_105543, кръгъл номер 2) ═══

Тог. деф. б.оц. $I$. Твърдим, че $U = L_I$.

**[⊆]** Наистина – $L \in U$: $L$ е $P$ или $\neg P$.

- $P \in U$. Тогава $I(P) = \mathrm{И} \to P \in L_I$
- $\neg P \in U$. Тогава $P \notin U$, $I(P) = \mathrm{Л}$, $I \models \neg P \to \neg P \in L_I$

Следователно $L \in U \to L \in L_I$.

**[⊇]** Нека $L \in L_I$.

- $L = P$: $P \in L_I$, $I \models P$, $I(P) = \mathrm{И} \Rightarrow P \in U$ (от деф. на $I$)
- $L = \neg P$: $\neg P \in L_I$, $I \models \neg P$, $\tilde I(\neg P) = \mathrm{И}$, $I(P) = \mathrm{Л}$, $P \notin U$

От условие (2) знаем, че точно едно от следните $P \in U$, $\neg P \in U$ е вярно.

Следователно $\neg P \in U$.

Значи $L \in L_I \to L \in U$.

Следователно $L_I = U$.

---

# ═══ Страница 2 – продължение (файл 20261109_105549) ═══

## Следствие

**Следствие:** Нека $S$ е м-во от дизюнкти. Тогава $S$ е изпълнимо точно тогава, когато съществува м-во $U$ от литерали, удовл. усл. (2).

- Ако $\blacksquare \in S$, то $S$ е неизпълнимо

  (Док: противоречие: $S$ е изпълнимо, но ни оценка на $\blacksquare$ ... *(?)*)

## Лема за резолвентата

**Лема:** Нека $L \in \mathcal{D}_1$ и $L^{\partial} \in \mathcal{D}_2$. Нека $I$ е б.оц.

> **Важна!**
> $$I \models \{\mathcal{D}_1, \mathcal{D}_2\} \quad \text{Тогава} \quad I \models (\mathcal{D}_1 \setminus \{L\}) \cup (\mathcal{D}_2 \setminus \{L^{\partial}\})$$

// В $\mathcal{D}_1$ може да има $L^{\partial}$ и в $\mathcal{D}_2$ да има $L$.

**Док:** Нека $L \in \mathcal{D}_1$, $L^{\partial} \in \mathcal{D}_2$, $I \models \mathcal{D}_1$, $I \models \mathcal{D}_2$.

**1 сл.** $I \models L$. Тогава $I \not\models L^{\partial}$.

$I \models \mathcal{D}_2$. Сл. $\exists L^{*} \in \mathcal{D}_2$, $I \models L^{*}$.

$L^{*} \neq L^{\partial}$, $L^{*} \in \mathcal{D}_2 \setminus \{L^{\partial}\} \subseteq (\mathcal{D}_1 \setminus \{L\}) \cup (\mathcal{D}_2 \setminus \{L^{\partial}\})$

$$\Rightarrow I \models (\mathcal{D}_1 \setminus \{L\}) \cup (\mathcal{D}_2 \setminus \{L^{\partial}\})$$

**2 сл.** $I \not\models L$. Тогава $I \models \mathcal{D}_1$. Значи $\exists L^{**} \in \mathcal{D}_1$, $I \models L^{**}$.

За $L \neq L^{**}$ Сл. $L^{**} \in \mathcal{D}_1 \setminus \{L\} \subseteq (\mathcal{D}_1 \setminus \{L\}) \cup (\mathcal{D}_2 \setminus \{L^{\partial}\})$

$$I \models (\mathcal{D}_1 \setminus \{L\}) \cup (\mathcal{D}_2 \setminus \{L^{\partial}\})$$

---

# ═══ Страница 3 (файл 20261109_105555, кръгъл номер 3) ═══

## Два дуални литерала – защо не

$L_1, L_2 \in \mathcal{D}_1$ ; $L_1^{\partial}, L_2^{\partial} \in \mathcal{D}_2$ ; $L_1, L_2, L_1^{\partial}, L_2^{\partial}$ са разл.

$$\mathcal{D} \triangleq (\mathcal{D}_1 \setminus \{L_1, L_2\}) \cup (\mathcal{D}_2 \setminus \{L_1^{\partial}, L_2^{\partial}\})$$

Вярно ли е, че ако $I \models \mathcal{D}_1$ и $I \models \mathcal{D}_2$, то $I \models \mathcal{D}$? **НЕ!!**

**Пример:** $\mathcal{D}_1 = \{P_1, P_2\}$, $\ \mathcal{D}_2 = \{\neg P_1, \neg P_2\}$

$$\mathcal{D} = (\{P_1, P_2\} \setminus \{P_1, P_2\}) \cup (\{\neg P_1, \neg P_2\} \setminus \{\neg P_1, \neg P_2\}) = \emptyset \cup \emptyset = \emptyset$$

т.е. $\mathcal{D} = \blacksquare$, $\ I \not\models \blacksquare$

---

*(В кутия: **Част 2**)*

## Метод на съждителната резолюция

**Дефо:** Нека $\mathcal{D}_1$ и $\mathcal{D}_2$ са дизюнкти. Казваме, че правилото за съждителната резолюция е приложимо към $\mathcal{D}_1$ и $\mathcal{D}_2$ относно литерала $L$, ако $L \in \mathcal{D}_1$, $L^{\partial} \in \mathcal{D}_2$.

$$!\,R_L(\mathcal{D}_1, \mathcal{D}_2)$$

$L_1 \neq L_2$: $\ !R_{L_1}(\mathcal{D}_1, \mathcal{D}_2)$ и $!R_{L_2}(\mathcal{D}_1, \mathcal{D}_2)$

**Дефо:** Казваме, че дизюнктът $\mathcal{D}$ е **резултат от прилагането на правилото за съжд. рез.** към диз. $\mathcal{D}_1$ и $\mathcal{D}_2$ от лит. $L$, ако $!R_L(\mathcal{D}_1, \mathcal{D}_2)$ и

$$\mathcal{D} = (\mathcal{D}_1 \setminus \{L\}) \cup (\mathcal{D}_2 \setminus \{L^{\partial}\}) \ \textit{(в оригинала и във второто е } \{L\} \textit{ *(?)*)}$$

---

# ═══ Страница 3 – продължение (файл 20261109_105602) ═══

Ако $\mathcal{D}$ е резултат от прилагане прав. за с.р. към $\mathcal{D}_1$ и $\mathcal{D}_2$ отн. $L$ и $I$ е модел за $\{\mathcal{D}_1, \mathcal{D}_2\}$, то

$$I \models \{\mathcal{D}_1, \mathcal{D}_2, \mathcal{D}\}$$

**Дефо:** Казваме, че дизюнктът $\mathcal{D}$ е съжд. **резолвента** на $\mathcal{D}_1$ и $\mathcal{D}_2$, ако $\mathcal{D}$ е резултат от прилагането на прав. съжд. рез. към $\mathcal{D}_1$ и $\mathcal{D}_2$ относно някой литерал.

Нека $\mathcal{D}$ е резолвента на диз. $\mathcal{D}_1$ и $\mathcal{D}_2$. Всеки път като $I \models \{\mathcal{D}_1, \mathcal{D}_2\}$, $I \models \mathcal{D}$.

Нека $\mathcal{D}_1$ и $\mathcal{D}_2$ са диз., като има поне един техен резолвент. Тогава всеки път, като $I$ е модел за $\{\mathcal{D}_1, \mathcal{D}_2\}$, $I$ е модел за $\forall$ тяхна резолвента.

## Резолвентен извод

**Дефо:** Нека $S$ е мн. от дизюнкти. **Резолвентен извод от $S$** е крайна редица от дизюнкти

$$\mathcal{D}_1, \mathcal{D}_2, \dots, \mathcal{D}_n,$$

такава че всеки пореден член е от $S$ или е резолвента на два предходни.

Така, за $\forall i$, $1 \le i \le n$:

$\mathcal{D}_i \in S$ или има съществ. $j_1, j_2 < i$ и $\mathcal{D}_i$ е резолвента на $\mathcal{D}_{j_1}$ и $\mathcal{D}_{j_2}$.

---

# ═══ Страница 4 (файл 20261109_105609, кръгъл номер 4) ═══

Нека $\mathcal{D}_1, \mathcal{D}_2, \dots, \mathcal{D}_n$ е рез. извод от $S$.

Тогава за $\forall k: 1 \le k \le n$

$\mathcal{D}_1 \dots \mathcal{D}_k$ е също резолвентен извод.

Ако $\mathcal{D}_1 \dots \mathcal{D}_n$ е р.и. от и $\mathcal{D}_1' \dots \mathcal{D}_k'$ е р.и. от д.. *(?)*

*(Задраскан ред)*

$$\mathcal{D}_1 \dots \mathcal{D}_n\ \mathcal{D}_n \dots \mathcal{D}_n\ ? \ \textit{(?)}$$

---

**Дефо:** Казваме, че дизюнктът $\mathcal{D}$ е **резолвентно изведен от $S$**, ако съществува ред. $\mathcal{D}_1 \dots \mathcal{D}_n$ от $S$, такъв че $\mathcal{D}_n = \mathcal{D}$.

За всяка такава редица се казва, че е р.и. на $\mathcal{D}$ от $S$.

$$\boxed{S \vdash \mathcal{D}}$$

**Тв:** Нека $S$ е мн. от съжд. и $S \vdash \mathcal{D}$. Нека $I \models S$. Тогава $I \models \mathcal{D}$.

**Док:** Нека $S \vdash \mathcal{D}$. Нека $I \models S$.

Тогава има резолвентен извод (р.и.) на $\mathcal{D}$ от $S$.

Нека $\mathcal{D}_1 \dots \mathcal{D}_n$ е р.и. на $\mathcal{D}$ от $S$ // (р.и. от $S$: $\mathcal{D}_n = \mathcal{D}$)

С индукция от $k$, $1 \le k \le n$, док. $I \models \mathcal{D}_k$.

Нека тв. е за $\forall\, 1 \le k_0 \le k < n$.

$\mathcal{D}_{k+1} \dots$ *(продължава на следващия лист; в кръг отбелязано „?")*

---

# ═══ Страница 4 – продължение (файл 20261109_105620) ═══

## Теорема: коректност на резолютивния извод

**Теорема:** Коректност на резолютивния извод.

Ако от $S \vdash \blacksquare$, то $S$ е неизпълнимо.

**Док:** Нека $S \vdash \blacksquare$. Да доп. че $S$ е изп.

Нека $I \models S$. От Тв. следва $I \models \blacksquare$ (противоречие).

Следва $S$ е неизпълнимо.

## Затворено множество

**Дефо:** За множество от диз. $S$ казваме, че е **затворено относно правилото за съжд. рез.**, ако от всеки път, когато $\mathcal{D}_1, \mathcal{D}_2 \in S$ и $\mathcal{D}$ е резолвента на $\mathcal{D}_1$ и $\mathcal{D}_2$, следва $\mathcal{D} \in S$.

**Тв.** Нека $S$ е мн-во от дизюнкти. Тогава, че

$$S^{*} \triangleq \{\mathcal{D} \mid S \vdash \mathcal{D}\}$$

е затворено относно правилото за резолюцията и

$$S \text{ е изп.} \iff S^{*} \text{ е изпълнимо}$$

**Док:** **1.** Затворено от правилото за съжд. резолюция.

Нека $\mathcal{D}', \mathcal{D}'' \in S^{*}$ и $\mathcal{D}$ е резолвента на $\mathcal{D}'$ и $\mathcal{D}''$.

- $S \vdash \mathcal{D}'$: Нека $\mathcal{D}_1' \dots \mathcal{D}_n'$ е рез. изв. от $S$ на $\mathcal{D}'$, $\mathcal{D}_n' = \mathcal{D}'$.
- $S \vdash \mathcal{D}''$: Нека $\mathcal{D}_1'' \dots \mathcal{D}_k''$ е рез. изв. от $S$ на $\mathcal{D}''$.

Тогава $\mathcal{D}_1' \dots \mathcal{D}_n', \mathcal{D}_1'' \dots \mathcal{D}_k''$ е рез. изв. от $S$.

---

# ═══ Страница 5 (файл 20261109_105627, кръгъл номер 5) ═══

Да рез. $\mathcal{D}_1' \dots \mathcal{D}_n', \mathcal{D}_1'' \dots \mathcal{D}_k'', \mathcal{D}$

Тъй като $\mathcal{D}$ е резолвента на $\mathcal{D}_n'$ и $\mathcal{D}_k''$, то този ред е р.и. от $S$ на $\mathcal{D}$.

То $S \vdash \mathcal{D}$. Сл. $\mathcal{D} \in S^{*}$.

---

**2.** $S$ е изп. $\iff$ $S^{*}$ е изп.

- Нека $S$ е изп.

  Нека $I$ е б.оц., която е модел за $S$, $I \models S$. Тогава твърдим, че $I \models S^{*}$.

  Наистина, нека $\mathcal{D} \in S^{*}$, $\exists$ път *(?)*, $S \vdash \mathcal{D}$.

  Тог. $I \models S$, $S \vdash \mathcal{D}$. От дока тв. $I \models \mathcal{D}$. Тогава и $I \models S^{*}$.

- Нека $S^{*}$ е изп. Нека $I \models S^{*}$. $S \subseteq S^{*}$. Сл. $I \models S$

  // Ако $\mathcal{D} \in S$, то едноч. р. $\mathcal{D}$ е р.и. от $S$ е р.и. на $\mathcal{D}$ от $S \vdash \mathcal{D}$

---

Искаме *(?)* да пок. *(?)*, т.е. $S$ е неизп. $\to S \vdash \blacksquare$

Ще док. че $S \not\vdash \blacksquare$, то $S^{*}$ е значи и $S$ е изп.

Ще докаже *(?)*, че има $U$ (множество) т.че има $L_I$, $I \models S^{*}$.

$L_I \cap \mathcal{D} \neq \emptyset$ то $\mathcal{D} \in S^{*}$

---

# ═══ Страница 5 – продължение (файл 20261109_105633) ═══

*(Горе вдясно: зачертан кръгъл номер „3" *(?)* – вероятно нов лист; нова тема)*

## Трансверзала за фамилия от множества

*(Заглавие, част от което е зачертана: „Трансверзала за ~~формули от тип …~~ фамилия от множества")*

**Дефо:** Нека $\mathcal{X}$ е фамилия от м-ва (т.е. $\forall$ елемент на $\mathcal{X}$ е множество).

**Трансверзала** за $\mathcal{X}$ е м-во $Y$, т.че $Y \subseteq \bigcup\mathcal{X}$ $\left(\bigcup_{x \in \mathcal{X}} x\right)$ и

$$(\forall x \in \mathcal{X})\,(Y \cap x \neq \emptyset)$$

**Наблюдение:** $\mathcal{X}$ има трансверзала $\iff (\forall x \in \mathcal{X})(x \neq \emptyset)$

**[⟹]** Нека $\mathcal{X}$ има трансверзала. Нека $Y$ е трансверзала за $\mathcal{X}$. Нека $x \in \mathcal{X}$. Тогава $Y \cap x \neq \emptyset$.

$x \supseteq Y \cap x$, сл. $x \neq \emptyset$.

**[⟸]** Нека $(\forall x \in \mathcal{X})(x \neq \emptyset)$.

Деф. $Y \triangleq \bigcup\mathcal{X}$.

Нека $x \in \mathcal{X}$. Тог. $x \subseteq \bigcup\mathcal{X} = Y$, сл. $Y \cap x = x \neq \emptyset$.

$Y \cap x \neq \emptyset$

*(Дясна кутия:)* За $\forall Y'$, ако $Y' \subset Y$, $Y' \neq Y$, то $Y'$ не е трансв. на $\mathcal{X}$.

**Дефо:** Нека $\mathcal{X}$ е фамилия от м-ва. Казваме, че $Y$ е **минимална трансверзала** за $\mathcal{X}$,

- $Y$ е трансверзала за $\mathcal{X}$
- ~~∃~~ *(второто условие е отрязано/зачертано)*
