# Преговор: Автоморфизми

**Предмет:** ЛП
**Дата:** 21.10.26
**Седмица:** 4
**Упражнение:** 3

---

## TOC & introduction

Преговор на автоморфизмите и определимите синглетони в структурите $\langle \mathbb{N},\mathbb{Z},\mathbb{Q},\mathbb{R}; +, \cdot \rangle$. Страниците са по реда на качване (файлове 526 → 529); листовете без кръгъл номер следват предишния.

1. **Автоморфизми и синглетони** – $h(\{n\}) = \{n\}$, $h = id$; определимост при $+$ (стр. 1)
2. **Умножение в $\langle\mathbb{R},\cdot\rangle$ и $\langle\mathbb{Q},\cdot\rangle$** – формули за $\{0\},\{1\},\{-1\}$, автоморфизми (стр. 1)
3. **Автоморфизми на $\langle\mathbb{N},\cdot\rangle$** – чрез разлагане на прости множители; релацията $p^A$ (стр. 1, продължение)
4. **Таблица на определимите синглетони и прости числа** (стр. 2)
5. **Геометрия: кръгчета в равнината** и теория на множествата (стр. 2, продължение)

---

# ═══ Страница 1 ═══

*(Горе вляво: **Седмица 4 | Упр 3**; горе вдясно в рамка: 21.10.26, ЛП)*

## Преговор: Автоморфизми

$\{n\}$ – синглетон $n$

$$h(\{n\}) = \{n\} \to h(n) = n \qquad h = id\ \text{за произволен}\ h$$

$$\mathbb{N},\ \mathbb{Z},\ \mathbb{Q},\ \mathbb{R} \qquad +,\ \cdot,\ +\ \text{и}\ \cdot$$

## Определимост при събиране (+)

- $\mathbb{N}$ определя $\{n\}$
- $\mathbb{Z}$ $\{0\}$ → използваме $h(x) = -x$
- $\mathbb{Q}$ $\{0\}$ → като това ↑
- $\mathbb{R}$ $\{0\}$ → ↑

$$h(x+y) = h(x) + h(y) \quad \Big\}\ \text{за } (+)$$

## За умножение

$\langle \mathbb{R}, \cdot \rangle$

$$\varphi_0(x) \triangleq \forall a\ x \cdot a \doteq x$$

$$\varphi_1(x) \triangleq \forall a\ x \cdot a \doteq a$$

↓ $\{0\}, \{1\}, \{-1\}$

$$f_{-1}(x) \triangleq \forall y\,\big(\varphi_1(y) \to x \cdot x \doteq y\big) \wedge \neg\varphi_1(x) \qquad /\!/\ \text{провери за случаи}$$

$$\exists y\,\big(\varphi_1(y) \wedge x \cdot x \doteq y\big) \wedge \neg\varphi_1(x)$$

$$h(x \cdot y) = h(x) \cdot h(y) \to \text{биекция} \to \text{хомоморфизъм} \qquad \to h(x) = x^3$$

*(Чертеж: графика на $h(x)=x^3$ – кубична крива през началото, с отбелязани точки при $x = -1, 0, 1$)*

**!** Ако не разместват дадени точки, те не са определими изцяло, а са кандидати да са определими.

> **Корен е само в $\mathbb{R}$?**

## Автоморфизъм на $\langle \mathbb{Q}, \cdot \rangle$

$$h(x) = \begin{cases} \dfrac{1}{x}, & x \neq 0 \\[4pt] 0, & \text{иначе} \end{cases}$$

← проверяваме с пример

проверяваме: биекция, автоморфизъм

---

# ═══ Страница 1 – продължение ═══

$$h(\{x\}) = \{x\}\ \text{при}\ (-1),\ 1\ \text{и}\ 0$$

↳ $\{0\},\ \{1\},\ \{-1\}$

## Автоморфизми на $\langle \mathbb{N}, \cdot \rangle$

$\langle \mathbb{N}, \cdot \rangle$

Много силен автоморфизъм за умножение с естествени числа и подобни на умножение.

$$n = p_1^{\alpha_1} p_2^{\alpha_2} \cdots p_n^{\alpha_n} \cdots \qquad \to\ p_1^{\infty} p_2^{\infty} \cdots p_n^{\infty} \cdots \text{ е } 0$$

$$h(n) = p_1^{\alpha_2} \cdot p_2^{\alpha_1} \cdot p_3^{\alpha_3} \cdots p_n^{\alpha_n} \cdots \ $$

→ Общо са много автоморфизмите, защото може да изберем различни две $\alpha$ и да ги разменяме, при което да образуваме нов автоморфизъм

$$h(a) \cdot h(b) = h(ab)$$

$$6 = 2^1 \cdot 3^1 \cdot 5^0 \cdots$$

но $2^0, 3^1, 5^1, \dots$ никога не е $6$, а $15$

За дадено $\{n\}$ си избираме автоморфизъм от вида $n = p_1^{\alpha_1} \cdots p_n^{\alpha_n} \cdots$, че да го счупи.

**Само 0 и 1 не се чупят!**

$$0 = p_1^{\infty} \cdots p_n^{\infty} \cdots \qquad \text{и} \qquad 1 = p_1^{0} \cdots p_n^{0} \cdots$$

---

## Релацията $p^A$

$$\langle m, n, k \rangle \in p^{A} \iff m^5 n^4 = k$$

$\langle \mathbb{N}, p^A \rangle$ $\{n\}$ е опр. $n = ?$

---

$$\varphi_0(x) \triangleq \forall a\ p(a, x, x) \qquad \{0\}$$

$$a^5 x^4 = x$$

$$a^5 x^4 - x = 0 \$$

$$x\,(a^5 x^3 - 1) = 0$$

---

$$p(x,x,x) \qquad \{0, 1\}$$

$$p(x,x,x) \wedge \neg\varphi_0(x)$$

**Автоморфизъм** → размяна на $m^5$ и $n^4$ степените

---

# ═══ Страница 2 ═══

## Таблица на определимите синглетони

| Структура | $+$ | $\cdot$ | $+$ и $\cdot$ |
|---|---|---|---|
| $\mathbb{N}$ | $\{n\}$ | $\{0\}, \{1\}$ | *(не е попълнено)* |
| $\mathbb{Z}$ | $\{0\}$ | $\{0\}, \{1\}, \{-1\}$ | |
| $\mathbb{Q}$ | $\{0\}$ | $\{0\}, \{1\}, \{-1\}$ | |
| $\mathbb{R}$ | $\{0\}$ | $\{0\}, \{1\}, \{-1\}$ | |

---

## Определяне на $\mathbb{N}$

$\varphi_{\mathbb{N}}(x)$

$$/\!/\ t_{\mathbb{N}}(x) \triangleq \exists t\ \varphi_0(t \,\&\, \exists r\, \varphi_{\le}(t, r, x)) \ \textit{(?)}$$

ако $r$ ако е отрицателно *(?)*: $t + r \doteq x$

$$\{0, 1, 2, \dots\}$$

$$\varphi_0(x) \vee \varphi_1(x) \vee \varphi_2(x) \vee \cdots$$

Сума на четири *(?)* квадрата ни дава естествено число.

$$\neg\exists a_1 \exists a_2 \exists a_3 \exists a_4\ \ b \doteq (a_1 \cdot a_2 + a_2 \cdot a_2) + a_3 \cdot a_3 + a_4 \cdot a_4 \ \textit{(?)}$$

## Прости числа в $\langle \mathbb{N}, \cdot \rangle$

$m(a, b, c)$: $a \cdot b = c$

$$\varphi_p(x) \triangleq \neg\exists a \exists b\,\big(m(a,b,x) \wedge \neg\varphi_1(a) \wedge \neg\varphi_1(b)\big) \wedge \neg\varphi_1(x)$$

$\langle \mathbb{N}, \cdot \rangle$

$$\forall a \forall b\,\big(m(a,b,x) \to \varphi_1(a) \vee \varphi_1(b)\big) \wedge \neg\varphi_1(x)$$

↑ може и $\neg m(x,x,x)$

$$\forall a \forall b\,\big(m(a,b,x) \to a \doteq x \vee b \doteq x\big) \wedge (\neg\, x \cdot x \doteq x)$$

---

# ═══ Страница 2 – продължение ═══

## Геометрия

↳ $\forall$ ненулеви кръгчета в равнината ($r > 0$)

Шест възможни разположения на две окръжности *(номерата са както са написани; подредбата е по скицата, някои може да са от съседна фигура *(?)*)*:

```
 1 (съвпадат)    2 (пресичат се)   3 (не се докосват)     5 (допират се)   4 (допират се отвътре)        6 (вложени)
   ◎               ◯◯               |         ○ ○            ◯◯           ⊙ (вложени)
```

Нека $\varphi$ е 5-ото – две кръгчета се допират.

от Теория на множествата $\forall x\,(x \in A \iff x \in B)$

$$\forall x\,\big(p(x,y) \iff p(x,z)\big) \iff \varphi_{=}(y,z) $$

$$\varphi_{\subseteq}(x,y) \quad \to \text{за домашно}$$
