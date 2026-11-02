# Определимост в структура от подмножества на $\mathbb{N}$ *(?)*

**Предмет:** ЛП
**Дата:** 28.10.26 *(?)* (датата е частично изрязана на снимката)
**Седмица:** 5
**Упражнение:** Упр *(?)* (в овал горе вляво, номерът не се чете)

> Заглавието е определено по съдържанието (в бележките няма изписано име на темата).

---

## TOC & introduction

Упражнение върху **определимост**. В първата част се определят релации между две кръгчета в равнината (шест случая). Във втората част се разглежда структурата $A$ с универсум $|A| = 2^{\mathbb{N}}$ (всички подмножества на $\mathbb{N}$) и релация $p^A$, зададена като $\langle a,b,c\rangle \in p^A \iff a \cap b = c$, и се показва кои множества са определими. В края са автоморфизмите (размяна на два елемента). Страниците са по реда на качване (файлове 853 → 856); няма кръгли номера.

1. **Две кръгчета в равнината – шест случая и формули** (стр. 1)
2. **Структурата $2^{\mathbb{N}}$ и определими множества** (стр. 1)
3. **Определимост на $\{\emptyset\}$ и $\{\mathbb{N}\}$** (стр. 1 и 2)
4. **Определимост на $\cap$-равенството и на $\cup$** (стр. 2 и 3)
5. **Автоморфизми – размяна на два елемента** (стр. 3 и 4)

---

# ═══ Страница 1 (файл 1000029853) ═══

*(Горе вдясно в рамка: 28.10.26 *(?)*, ЛП, Седмица 5; горе вляво в овал: Упр)*

## Две кръгчета в равнината – шест случая

*(Чертежи – всяка двойка е отбелязана с номер:)*

```
 1 ◯            2  ◯◯ (пресичат се)  │  3  ◯  ◯ (отделни)     4  ◎ (концентрични)

 5  ◯◯ (допират се / вътрешно)         6  ⊖ (едното в другото)
```

*(Разположението и номерата са според скицата; някои може да са сменени *(?)*)*

Ще дефинираме 5 *(?)*:

$$\varphi_4(x,y) \triangleq \neg\exists x\,\big(p(x,y) \wedge p(x,z)\big) \ \textit{(?)}$$

$$\varphi_{\le}(x,y) \triangleq \forall z\,\big(\varphi_4(z,x) \to \varphi_4(z,y)\big)$$

$$\varphi_6(x,y) \triangleq \varphi_{\le}(x,y) \wedge \neg\varphi_4(x,y)$$

$$\varphi_3(x,y) \triangleq \neg\exists z\,\big(\varphi_{\le}(z,x) \,\&\, \varphi_{\le}(z,y)\big) \,\&\, \neg\varphi_5(x,y)$$

$$\varphi_2(x,y) \triangleq \exists z\,\exists w\,\big(\varphi_{\le}(z,x) \wedge \neg\varphi_{\le}(z,y) \wedge \varphi_{\le}(w,y) \wedge \neg\varphi_{\le}(w,x)\big) \wedge \exists t\,\big(\varphi_{\le}(t,x) \wedge \varphi_{\le}(t,y)\big)$$

С 1 и 2 ... да се деф. другите *(?)*

---

## Структура от подмножества

$$|A| = 2^{\mathbb{N}} \qquad \langle a, b, c\rangle \in p^{A} \iff a \cap b = c$$

*(Дясна колона – лични бележки:)*
- логическо противоречие
- оценяване *(?)*
- $\Rightarrow$ Трябва да вземе правилното
- $\Leftarrow$ трябва да док. че $X$ е празното

## Кои синглетони са определими

- $\{\emptyset\}$
- $\{\mathbb{N}\}$
- $\{\langle a, a\rangle \mid a \subseteq \mathbb{N}\}$
- $\{\langle a, b\rangle \mid a \subseteq b\}$
- $\{\langle a, b, c\rangle \mid a \cup b = c\}$
- Няма други определими синглетони *(?)*

## Определяне на $\{\emptyset\}$

$$\varphi_{\emptyset}(x) \triangleq \forall y\ p(x, y, x)$$

**⇒** Нека $v(x) = \emptyset$

$$x \cap y \overset{?}{=} x$$

$$\emptyset \cap y = \emptyset$$

*(стрелка)* $\emptyset$ ⟶ е вярно *(?)*

---

# ═══ Страница 1 – продължение (файл 1000029854) ═══

**[⇐]** Нека $y = \emptyset$, $\ p(x, y, x)$

$$\emptyset = x \cap \emptyset = x \cap y \overset{?}{=} x$$

---

## Определяне на $\{\mathbb{N}\}$

$$\varphi_{\mathbb{N}}(x) \triangleq \forall y\ p(x, y, y)$$

**⇒** $v(x) = \mathbb{N}$

$$y = \mathbb{N} \cap y = x \cap y \overset{?}{=} y \quad \text{при произволно } y$$

Сл. формулата е вярна.

**[⇐]** за $y = \mathbb{N}$: $\ p(x, y, y)$

$$x = x \cap \mathbb{N} = x \cap y = y = \mathbb{N}$$

---

## Равенство на множества

$$\underbrace{p(a,b,a) \wedge p(a,b,b)}_{\varphi_{=}(a,b)} \ \textit{(?)}$$

$$\Rightarrow\ a = a',\ b = a' \ \textit{(?)}$$

$$a \cap b = a' \cap a' = a' = a = b$$

*(Задраскан ред)*

## Определяне на $\cup$

$$\varphi_{\cup}(a,b,c) \triangleq \varphi_{\le}(a,c) \wedge \varphi_{\le}(b,c) \wedge \forall z\,\big(\varphi_{\le}(a,z) \wedge \varphi_{\le}(b,z) \to \varphi_{\le}(c,z)\big)$$

**[⇒]** $a \cup b = c$

- $\varphi_{\le}(a,c)$, защото $a \subseteq c$
- $\varphi_{\le}(b,c)$, защото $b \subseteq c$

$a \subseteq z$, $b \subseteq z$, $c \overset{?}{\subseteq} z$

---

# ═══ Страница 1 – продължение (файл 1000029855) ═══

**[⇐]** $\varphi_{\le}(a,c) \to a \subseteq c$ ; $\ \varphi_{\le}(b,c) \to b \subseteq c$ $\ \Rightarrow\ a \cup b \subseteq c$

$x \in c$

Нека $z = a \cup b$:

$$\forall z\,\big(\varphi_{\le}(a,z) \wedge \varphi_{\le}(b,z) \to \varphi_{\le}(c,z)\big)$$

$$a \subseteq a \cup b,\quad b \subseteq z = a \cup b \quad\to\quad c \subseteq a \cup b$$

От това следва $a \cup b \subseteq c$ и $c \subseteq a \cup b$

$$\Rightarrow a \cup b = c$$

---

Ако имаме $\forall z$, избираме нещо, което да ни върши работа (както в този случай горе).

---

## Автоморфизми

- Няма други. $h(a) \cap h(b) = h(a \cap b)$

*(Дясно:)* $m, n \in \mathbb{N}$, $h$ е за елемент:

$$h(q) = \begin{cases} m, & q = n \\ n, & q = m \\ q, & \text{иначе} \end{cases}$$

↓ биекция за елементите

$$H(A) = \{h(a) \mid a \in A\}$$

$$\{0,1,2\} \to \{0,1,2\}$$

$$\{1\} \to \{0\}$$

$$\{0,2\} \to \{1,2\}$$

*(при $h$, разменящо $0$ и $1$)*

$$H_{m,n}(A) = \dots \ \text{за } h \text{ разменящо } m \text{ и } n$$

---

# ═══ Страница 1 – продължение (файл 1000029856) ═══

Инволюция – доказва се с повторение *(?)*: $\quad H(H(A)) = A$

Хомоморфизъм *(?)*

**Въпрос:** Как да избера $H$ за $A$, с което да е вярно *(?)*, че едно отговор *(?)*

Само за $\emptyset$ и $\mathbb{N}$ не може да се случи, защото $\emptyset$ няма елементи, а $\mathbb{N}$ има всички и няма как да вземем отвън.

$$A \neq \emptyset,\quad A \neq \mathbb{N}$$

$$m \in A,\ n \notin A \ \Rightarrow\ H_{m,n}(A) \neq A$$
