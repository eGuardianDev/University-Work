# Продължение

**Предмет:** ЛП 
**Дата:** 15.10.26 г.
**Лекция:** 2
**Седмица:** 3

---

## TOC & introduction

Бележки от Лекция 2 (Седмица 3) по съждителна логика. Страниците са подредени по реда на качване и по кръглите номера в ръба на листа. Листовете без номер следват предишния номериран лист.

1. **Въведение и булеви оценки** – логически функции $H_\neg, H_\&, \dots$, разширение $\tilde I$ на оценка, "вярна при", $\models$, тавтология, изпълнима формула, модел (стр. 1)
2. **Тавтология ⇔ отрицанието е неизпълнимо** – твърдение и доказателство в двете посоки (стр. 1, продължение)
3. **Лема: две оценки със съвпадащи стойности на променливите** – доказателство с индукция по построението на формулата (стр. 2 и продължение)
4. **Алгоритъм за изпълнимост** – проверка на всички оценки на крайния брой променливи (стр. 3)
5. **Алгоритъм за тавтология, NP / co-NP** – свеждане до изпълнимост; изпълнимост на множества формули (стр. 3, продължение)
6. **Изпълнимост на множество формули** – Γ = {φ₁, …, φₙ}, подмножества (стр. 4 и продължение)
7. **Теорема за компактност** (стр. 4, продължение)
8. **Логическо следване** – $\Gamma \models \varphi$, еквивалентност с неизпълнимост на $\Gamma \cup \{\neg\varphi\}$ (стр. 5 и продължение)

---

# ═══ Страница 1  ═══

*(Заглавие в кутия: **Продължение**; в кутия горе вдясно: 15.10.26г., ЛП)*

## Логически функции

$$H_\neg,\ H_\&,\ H_\vee,\ H_\Rightarrow,\ H_\Leftrightarrow$$

Ще ни интересува верността на съждения.
Въведохме формален език. Индуктивна дефиниция въведохме.
Съждителни променливи $\mathrm{For}(\mathrm{PVAR})$

---

*(Кутия: **Лекция 2. Седмица 3**)*

## Булева оценка и нейното разширение

Булева (съждителна) оценка, още записана $I : \mathrm{PVAR} \to \{\mathrm{И}, \mathrm{Л}\}$

$I$ има еднозначно разширение $\tilde I : \mathrm{For}(\mathrm{PVAR}) \to \{\mathrm{И}, \mathrm{Л}\}$

$$\tilde I(P) = I(P),\quad P \in \mathrm{PVAR}$$

$$\tilde I(\neg\varphi) = H_\neg\big(\tilde I(\varphi)\big)$$

$$\tilde I(\varphi_1 \,\sigma\, \varphi_2) = H_\sigma\big(\tilde I(\varphi_1), \tilde I(\varphi_2)\big),\quad \sigma \in \{\&, \vee, \Rightarrow, \Leftrightarrow\}$$

## Дефиниция: вярна при оценка

**Дефиниция:** Казваме, че $\varphi$ е вярна при булевата оценка $I$, ако $\tilde I(\varphi) = \mathrm{И}$.

$\tilde I(\varphi) = \mathrm{Л} \to \varphi$ не е вярна при $I$.

- $I \models \varphi$ е съкращение за $\tilde I(\varphi) = \mathrm{И}$
- $I \not\models \varphi$ е съкращение за $\tilde I(\varphi) = \mathrm{Л}$

$$I \models P \iff I(P) = \mathrm{И}$$

$$I \models \neg P \iff I(P) = \mathrm{Л}$$

$$I \models (\varphi \,\&\, \psi) \iff \tilde I(\varphi) = \tilde I(\psi) = \mathrm{И}$$

## Тавтология

**Дефениция:** Казваме, че съждителната формула. $\varphi$ е **съждителна тавтология**, ако за $\forall$ булева оценка $I$: $I \models \varphi$ ($\varphi$ е вярна за $\forall I$).

// Можем ли да разпознаваме тавтологиите?

## Изпълнимост, модел

**Дефинция:** Формулата $\varphi$ се нарича **изпълнима**, ако $\exists$ съжд. оценка $I$, $I \models \varphi$.

Ако $I \models \varphi$, казваме, че $I$ е **модел за** $\varphi$.
Ако $I \not\models \varphi$, казваме, че $I$ **опровергава** $\varphi$.

---

# ═══ Страница 1 ═══

*(Чертеж горе вляво: двоично дърво с променливите $P_0, P_1, \dots$ и стойности И/Л по клоновете)*

```
     .
   /   \
  Л     И    P_0
 / \   / \
Л   И Л   И  P_1
|   | |   |
...........
```

## Тавтология ⇔ отрицанието е неизпълнимо

**Твърдение:** Нека $\varphi$ е съжд. фо., следните са еквивалентни:

1) $\varphi$ е съжд. тавтология, $\models \varphi$
2) $\neg\varphi$ не е изпълнимо, т.е. е неизпълнима

**Док (1) → (2):**

Нека $\models \varphi$. Да допуснем, че $\neg\varphi$ е изпълнима.

⇒ Тогава съществува б.о., при която $\neg\varphi$ е вярна (значи има някъде такава оценка).

Нека $I_0$ свидетелства за това съществуване.

$I_0$ е б.о. $I_0 \models \neg\varphi$

$$\to \tilde I_0(\neg\varphi) = \mathrm{И}$$

$$\tilde I_0(\neg\varphi) = H_\neg\big(\tilde I(\varphi)\big)$$

→ Следователно $\tilde I_0(\varphi)$ е лъжа, $I_0 \not\models \varphi$.

Тъй като $\varphi$ е съжд. тавтология, налага при всяка $P$ има стойност И, в частност $I_0 \models \varphi$. *(противоречие)*

**(2) → (1):**

Нека $\neg\varphi$ е неизпълнима, т.е. няма оценка, при която $\neg\varphi$ е вярна.

Нека $I$ е произволна оценка.

$I$ е б.о.: $I \not\models \neg\varphi$. Тогава $\tilde I(\neg\varphi) = \mathrm{Л}$, т.е. $H_\neg(\tilde I(\varphi)) = \mathrm{Л}$, след $\tilde I(\varphi) = \mathrm{И}$, $I \models \varphi$.

Тогава за $\forall$ б.о. $I$ е в сила $I \models \varphi$, т.е. $\models \varphi$.

---

# ═══ Страница 2 ═══

## Дърво на формулата

*(Чертеж горе вляво: дърво с корен $\&$; левият наследник е $\vee$, десният е $\Rightarrow$. Под $\vee$: $\Rightarrow$ с листа $P_0, P_4$ и лист $P_3$. Под десния $\Rightarrow$: лист $P_0$ и $\neg$ с лист $P_4$.)*

```
                &
              /   \
            ∨      ⇒
           / \    / \
          ⇒   P3 P0  ¬
         / \         |
       P0   P4       P4
```

Една оценка, дава стойности на променливи

## Твърдение (лема)

**Твърдение:** Нека $\varphi$ е съжд. формула. Тогава $\forall$ път, когато $I_1$ и $I_2$ са булеви оценки със свойството

$$(*)\quad \{\, I_1(P) = I_2(P) \ \text{за}\ \forall \text{ съжд. пром. } P \text{, участва във } \varphi \,\}$$

е в сила равенството $\tilde I_1(\varphi) = \tilde I_2(\varphi)$

$$/\!/\ I_1 \models \varphi \iff I_2 \models \varphi$$

## Доказателство

**Док:** Индукция относно построението на формулата $\varphi$

**1)** $\varphi \equiv P \in \mathrm{PVAR}$ – $\varphi$ е съжд. променлива.

Нека $I_1$ и $I_2$ са б.оц., за които $(*)$ е изпълнено. $P$ участва във $\varphi$.

Следователно св-во $(*)$ ни дава $I_1(P) = I_2(P)$.

$$\tilde I_1(\varphi) = I_1(P) = I_2(P) = \tilde I_2(\varphi)$$

**2)** $\varphi \equiv \neg\psi$ и за $\psi$ тв. е вярно.

↳ Нека $I_1$ и $I_2$ са б.о. и за $\forall$ съжд. пром. $P$, участва във $\varphi$, $I_1(P) = I_2(P)$.

Нека $P$ е съжд. пром., участваща в $\psi$ (нека взет случаен съжд. пром. $P$ от $\psi$).

Тогава $P$ уч. във $\varphi$, от $(*)$ $I_1(P) = I_2(P)$.

Следователно индуктивното предп. за $\psi$ е изп. $I_1$ и $I_2$:

$$\tilde I_1(\psi) = \tilde I_2(\psi),\quad \text{тогава } H_\neg\big(\tilde I_1(\psi)\big) = H_\neg\big(\tilde I_2(\psi)\big)$$

$$H_\neg\big(\tilde I_1(\psi)\big) = \tilde I_1(\varphi) \qquad\qquad \tilde H_\neg\big(\tilde I_2(\psi)\big) = I_2(\varphi)$$

**3)** $\Rightarrow$ …

---

# ═══ Страница 2 – продължение ═══

**3)** (? $\varphi$ = ) $(\psi_1 \,\sigma\, \psi_2)$, $\sigma \in \{\&, \vee, \Rightarrow, \Leftrightarrow\}$ // за това $\varphi$ не съм сигурен дали да го има)

и за $\psi_1$ и $\psi_2$ индуктивната хипотеза е в сила.

Нека $I_1$ и $I_2$ са булеви оценки и $(*)$ е изпълнено за $I_1$, $I_2$ и $\varphi$.

Нека $P$ е съжд. променлива участваща в $\psi_j$, $j \in \{1,2\}$.

Тогава $P$ уч. и във $\varphi$. Значи от $(*)$ има $I_1(P) = I_2(P)$.

Следователно за $\psi_j$, $j \in \{1,2\}$, И.Х. е изпъленено (т.е. е приложено?), че $I_1$ и $I_2$:

$$\tilde I_1(\psi_1) = \tilde I_2(\psi_1)$$

$$\tilde I_1(\psi_2) = \tilde I_2(\psi_2)$$

$$H_\sigma\big(\tilde I_1(\psi_1), \tilde I_1(\psi_2)\big) = H_\sigma\big(\tilde I_2(\psi_1), \tilde I_2(\psi_2)\big)$$

$$\tilde I_1(\varphi) \qquad\qquad\qquad\qquad \tilde I_2(\varphi)$$

---

# ═══ Страница 3  ═══

## Означение $\varphi[P_1, \dots, P_n]$

*(Кутия)*

$\varphi \subset \varphi[P_0, P_1, \dots, P_n]$

Означаваме фактa, че пром., които оз. във $\varphi$ са изчерпани $P_1 \dots P_n$.

$$\varphi[P_1, \dots, P_n];\quad I_1 \upharpoonright \{P_1, \dots, P_n\} = I_2 \upharpoonright \{P_1, \dots, P_n\}$$

$$\to I_1 \models \varphi \iff I_2 \models \varphi$$

Нека $\{P_1, \dots, P_n\}$ са $\forall$ пром., срещащи се във $\varphi$.

Тогава $I_1[P_j] = I_2[P_j]$, $j = 1, 2, \dots, n \to (I_1 \models \varphi \iff I_2 \models \varphi)$

Ако $I(P_1) = a_1, \dots, I(P_n) = a_n$ $\ (a_j \in \{\mathrm{И}, \mathrm{Л}\})$

Тогава за краен брой стъпки можем да намерим $\tilde I(\varphi)$.
При това за полиномиално време.

## Алгоритъм за изпълнимост

**Твърдение:** Има алгоритъм, който по дадено $\varphi$ за краен брой стъпки разрешава дали $\varphi$ е изпълнимо.

**Док:**

1. По дадено $\varphi$ пресмятаме списък $P_1, \dots, P_n$ от $\forall$ пром. участващи във $\varphi$, т.че $P_i \neq P_j$ за $i \neq j$.

2. Последователно изпробваме крайната редица $a_1, \dots, a_n$, $a_j \in \{\mathrm{И}, \mathrm{Л}\}$.

Като за текуща породена е $a_1, \dots, a_n$ пресмятаме стойността на $\tilde I(\varphi)$, $I[P_j] = a_j$.

Ако $\tilde I(\varphi) = \mathrm{И}$, то алгоритъм спира и дава отговор „ДА", т.е. $\varphi$ е изпълнимо. 

Ако сме породили всички крайни редици $a_1 \dots a_n$ от $\{\mathrm{И}, \mathrm{Л}\}^n$  и всеки път получава лъжа, то алгоритъма завършва и дава отговор „НЕ", т.е. $\varphi$ не е изпълнена.

---

# ═══ Страница 3 – продължение ═══

## Алгоритъм за тавтология

*(Две кутии: **Алгоритъм за тавтология** | **Ал. за $\models \varphi$**)*

**Вход:** $\varphi$

1: добавяме отрицание и става $\neg\varphi$

2: пускаме алгоритъма от предходния пример с $\neg\varphi$

- Ако той даде отговора „НЕ" → спираме с отг. „ДА"
- Ако отговора е „ДА" → „НЕ" ($\not\models \varphi$)

Принципно този алгоритъм е  $\to \underline{\mathrm{NP}}\text{-пълен} - 2^n$

Ще изпозлваме 
co-NP-пълна алгоритми за разпознаване на $\models$ → метод на резолюцията

Има следните подходи: Метод на унификация и метод на разолюцията

## Изпълнимост на съждителни формули

**Дефо:** Нека $\Gamma$ е мн. от съждителни формули.

**①** $\Gamma$ се нарича **изпълнимо**, ако има б.о. $I$, която е модел за $\forall$ една от формулите на $\Gamma$

$$\tilde I(\varphi) = \mathrm{И}\ \text{за}\ \forall \varphi \in \Gamma$$

$$I \models \varphi\ \text{за}\ \forall \varphi \in \Gamma$$

**②** $\Gamma$ се нарича **неизпълнима**, ако $\Gamma$ не е изпълнимо. $\Gamma$ няма модел.

- Няма б.о. $I$, т.че $\tilde I(\varphi) = \mathrm{И}$ за $\forall \varphi \in \Gamma$
- Няма б.о. $I$, т.че за $\forall \varphi \in \Gamma$, $I \models \varphi$
- Всеки път, когато $I$ е б.оц., има формула $\varphi \in \Gamma$, $I \not\models \varphi$

---

- $\forall$ б.о. $I$ е модел за празното м-во от съжд. фо. ($\emptyset$). Празното м-во е изпълнимо.
- $\mathrm{For}(\mathrm{PVAR})$ не е изпълнимо.

**Означение:** $I \models \Gamma$ означава, че всяка фо. $\varphi$ от $\Gamma$ е вярна за $I$.

$$I \models \{P\}$$

---

# ═══ Страница 4  ═══

## Крайни множества формули

Нека $\Gamma = \{\varphi_1, \dots, \varphi_n\}$

$$I \models \{\varphi_1, \dots, \varphi_n\} \iff I \models \big((\varphi_1 \,\&\, \varphi_2) \,\&\, \dots \,\&\, \varphi_n\big)$$

Разглеждаме:

- Инд. по $n$: $n > 1$ – Ok /точно
- ИХ: $n$ е естествено число и еквивалентно е вярна за произволно м-во от съжд. формули.

- Нека видим за $n+1$
$$I \models \{\varphi_1, \dots, \varphi_n, \varphi_{n+1}\} \overset{\text{def}}{\iff} I \models \varphi_1 \text{ и } I \models \varphi_2 \dots I \models \varphi_n \text{, и } I \models \varphi_{n+1}$$

$$\overset{\text{ИХ}}{\iff} I \models \big((\varphi_1 \& \varphi_2) \dots \& \varphi_n\big) \text{ и } I \models \varphi_{n+1}$$

$$\iff I \models \big((\dots(\varphi_1 \& \varphi_2) \& \dots \& \varphi_n) \& \varphi_{n+1}\big)$$


**Накрая:**
$$\{\varphi_1, \dots, \varphi_n\} \text{ е изпълнимо} \iff \big(((\varphi_1 \& \varphi_2) \& \dots \& \varphi_n)\big)$$

## Подмножества

- Нека $\Delta \subseteq \Gamma$.
  - Ако $\Gamma$ е изпълнимо, то $\Delta$ е изпълнимо.
  - Ако $\Delta$ е неизпълнимо, то и $\Gamma$ е неизпълнимо.

- Нека $\Delta \subseteq \Gamma$.
  $\Gamma$ е изп. $\Rightarrow \exists I$ б.о. т.че $I \models \Gamma$ ($I$ е модел на $\Gamma$) $\to \forall \varphi$ формула $\in \Gamma$, $I \models \varphi$

Нека разгледаме:
  - Нека $I_0$ е б.о., която е модел за $\Gamma$ ($I \models \Gamma$).
  Тогава $I_0$ е модел за $\Delta$.

  - Нека $\varphi$ е произволна формула от $\Delta$ ($\varphi \in \Delta$), то $\varphi \in \Gamma$ и $I \models \varphi$.

  - Така $\forall$ път, когато $\varphi \in \Delta$, то $I \models \varphi$.

  - Т.е. $I$ е модел на $\Delta$ ($I \models \Delta$).

---

# ═══ Страница 4 – продължение ═══

Нека $\Delta \subseteq \Gamma$. Нека $\Delta$ е неизп.

Да допуснем, че $\Gamma$ е изп. Тогава има б.о. $I$, което е модел на $\Gamma$.

Значи, тогава и $\Delta$ има модел.

Това противоречи на допускането, че $\Delta$ не е изпълнимо. Тогава $\Gamma$ е неизпълнимо.

## Теорема за компактност на изпълнимостта

Нека $\Gamma$ е мн-во от съжд. фо. Следните са еквивалентни:

(1) $\Gamma$ е изпълнимо

(2) всяко <u>крайно</u> подмножество на $\Gamma$ е изпълнимо

(1) → (2) тривиално

(2) → (1) е дълбока теория

---

(1′) $\Gamma$ е неизпълнимо

(2′) Има крайно подмножество на $\Gamma$, което не е изпълнимо

## Логическо следване

**Дефиниция:** Нека $\Gamma$ е мн-во от съжд. ф-ли.
Казваме, че от $\Gamma$ логически следва формула $\varphi$, ако всеки модел на $\Gamma$ е модел на $\varphi$.

**Пример:** $\Gamma \models \varphi$

Всеки път, когато $I$ е б.оц., която има свойството за $\forall \psi \in \Gamma$, $\tilde I(\psi) = \mathrm{И}$, $I \models \psi$, е в сила $\tilde I(\varphi) = \mathrm{И}$ (т.е. $I \models \varphi$).

---

# ═══ Страница 5 ═══

## $\Gamma \not\models \varphi$

$\Gamma \not\models \varphi$ | Има модел за $\Gamma$, който не е модел за $\varphi$.

Има б.оц. $I$, за $\forall \psi \in \Gamma$, $I \models \psi$, но $I \not\models \varphi$.

---

Вместо $\{\varphi_1, \dots, \varphi_n\} \models \varphi$ имаме (ще пишем) $\varphi_1, \dots, \varphi_n \models \varphi$.

2. $\emptyset \models \varphi$ пишем $\models \varphi$ (еквивалентно на тавтология).

$$\emptyset \models \varphi \iff \varphi \text{ е съжд. тавтология}$$

## Твърдение

**Твърдение:** Следните са еквивалентни:

1) $\Gamma \models \varphi$
2) $\Gamma \cup \{\neg\varphi\}$ е неизпълнимо

**Док (1) → (2):**

Нека $\Gamma \models \varphi$. Да доп., че $\Gamma \cup \{\neg\varphi\}$ е изпълнимо.

Тогава $\Gamma \cup \{\neg\varphi\}$ има б.о.

Нека $I_0 \models \Gamma \cup \{\neg\varphi\}$ 

$$\psi \in \Gamma \to \psi \in \Gamma \cup \{\neg\varphi\} \to I_0 \models \psi \qquad \to I_0 \models \Gamma$$

Тъй като $\Gamma \models \varphi$, $I_0 \models \varphi$. Така че $I_0 \not\models \neg\varphi$, но $\neg\varphi \in \Gamma \cup \{\neg\varphi\}$ и $I_0 \models \Gamma \cup \{\neg\varphi\}$ .

Значи $I_0$ е модел за формулите от $\Gamma \cup \{\neg\varphi\}$ .

Значи $I_0 \models \neg\varphi$. **Абсурд** ⇒ $\Gamma \cup \{\neg\varphi\}$ е неизпълнимо.

---

# ═══ Страница 5 – продължение ═══

**(2) → (1).** Нека $\Gamma \cup \{\neg\varphi\}$ е неизпълнимо.

Нека $I$ е произволен модел на $\Gamma$.

„Имаме $I, \varphi$"

**Сл. 1:** $I \models \varphi$ $\to$ логично е, че обединението не е изпълнимо. (Пишето всичко както си трябва, а не само "Ясно е", защото се заяждат за това)

**Сл. 2:** $I \not\models \varphi$ ⇒ Тогава $I \models \neg\varphi$

Така в този случай получаваме, че $\forall$ ф-ла от $\Gamma \cup \{\neg\varphi\}$ е вярна при $I$.

Значи $I \models \Gamma \cup \{\neg\varphi\}$, т.е. има $\Gamma \cup \{\neg\varphi\}$ е изпълнено, което е абсурд.

С други думи следва, че е неизпълнимо.

Така $I \models \Gamma$, то $I \models \varphi$, $\boxed{\Gamma \models \varphi}$

---

- Ако $\models \varphi$, то за произволно $\Gamma$ е в сила $\Gamma \models \varphi$.
- Ако $\Gamma$ е неизпълнимо, то за произволно $\varphi$ е в сила $\Gamma \models \varphi$.
