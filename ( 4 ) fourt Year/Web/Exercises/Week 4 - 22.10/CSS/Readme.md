
# CSS introduction


## how to modify
### in html head
```html
<style>
p{
    color:red;
}
</style>
```
### in html body
```html
<p style = "color:red"></p>
```

## Applying html
### Apply to all
```css
* {
    box-sizing: border-box;
}
```

### Select by class
HTML
```html
<h1 class="price">Hello world</h1>
```
CSS
```css
.price{
    color: red;
}
```

### Select by id
HTML
```html
<h1 id="price">Hello world</h1>
```
CSS
```css
#price{
    color: red;
}
```


### Влагане
```css
main a{
    color: yellow;
}
```

### няколко наведнъж
```css
main, a{
    color: yellow;
}
```
### нещо от някакъв клас
```css
h1.small{
    color: yellow;
}
```


### neighbours
```css
h2 + p{
    ...
}
```

### direct children
```css
ul > li{
    ...
}
```


### first child
```css 
li:first-child{

}
```
### nth child
```css 
tr:nth-child(2){

}
```

### everything in element
```css
div *
{
}
```

### all incoming neighbours
```
bento ~ pickle
```

### leaf of tree
```
plate orange:first-child
{

}
```


### hover
when cursor is on specific element
```css 
a:hover{
    color:red
}
```

### focus
when you select something in any way possible
```css 
a:focus{
    color:red
}
```

### focus-visible
only when selecteting something with `TAB` key from keyboard
```css 
a:focus-visible{
    color:red
}
```



## which style wins
```css
p{color:green;}
.my-class{color:blue;}
#my-id{color:red;}
```
``` html
<p class="my-class" id="my-id">text very cool</p>
```
Как работи избирането на специфичиност:
my-id -> my-class -> p


## duplicated
```css
#my-id{color:red;}
#my-id{color:yellow;}
```
``` html
<p class="my-class" id="my-id">text very cool</p>
```
печели последния 

## attribute
```css
p{color:green;}
.my-class{color:blue;}
#my-id{color:red;}
```
``` html
<p class="my-class" id="my-id" style="color:yellow">text very cool</p>
```
Винаги печели `style` атрибута в html

## important
```css
p{color:green;}
.my-class{color:blue; !important}
#my-id{color:red;}
```
``` html
<p class="my-class" id="my-id" style="color:yellow">text very cool</p>
```
`!important` overwrites всичко, дори атрибутите
> Много лоша практика

може да се слага в `style` атрибута


## Наследяване
има стилове които се наследяват:
- font-style
- color

няма да се наследят всички неща, като например:
- border


## Inspect

- Styles
    - може да видим от кои файлове се извикват
    - ако изберем атрибут може да използваме стрелките, за да scroll-ваме
    - може да използваме `color picker` и да изберем цвят от целия екран
- Computed
    - крайните изчисления на стила

## colors
- С име - има около 140 именувани цвята `yellow`
- hex - десетично RGB `#f31a54` - от `00` до `ff` за всяко
- rgb - `rgb(236, 45, 45)` - от `0` до `255`
- rgb + alpha - `rgb(236, 45, 45, 0.5)` - от `0` до `1`
- rgb + alpha (modern) - `rgb(236 45 45 / 0.5)`
- hsl - `hsl(0,50%,15%)` - от `0` до `100`


## Мерни единици
Важно е кога се използват

- pixel - `px`
    - шрифта под разбиране е 16 px
- room em - `rem`
    - спрямо размера на шрифта на цялата страницата
    - 1rem = 16px
    - 2rem = 32px
    - за да го смениме трябва да използваме `html{font-size:10px}`
    - много често ползвано - user defined size в браузъра им
- em - `em`
    - спрямо размера на шрифта на избрания елемента
    - има капан, примерно при `ul - unordered list`
- % - `%`
    - спрямо родителя
- view width, view height - `vw`, `vh`
    - спрямо ширината и височината на прозореца


Проблем с `rem` и `em`


### допълнително
за следващия час
`padding`
`marin`

# Game
CSS remembering game - https://flukeout.github.io/  
