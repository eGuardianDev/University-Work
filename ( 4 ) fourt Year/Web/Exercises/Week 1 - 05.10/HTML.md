# какво е html

- тагове
- Hyper Link Markdown Language
- определя структурата

- first webpage ever - (link)[https://info.cern.ch/hypertext/WWW/TheProject.html]

- DOM - Document Object Model

- HTML -> parse bytes -> text -> build DOM -> visualize images -> estimate sizes -> drawing pixels

# How to debug

- F12 or right click inspect
- Sources - how html is written -> the server returns this file

## Network tab
- see data that is coming from server
 - Reload and record button

## Console
- javascript

## Elements / Inspect
- Parsed html file

# Where to write html
- every note editor
- vs code is recommended

- Use "!" and press enter in vs code to display the recommended stuff

# Tags
```<!DOCTYPE html>``` - not html element. Standard node to inform browser to not make problems with old html or something

```<html lang="en"> ... </html>``` - Root of tree. ```lang="en"``` 

For homework use ```lang=bg```. This is used by language reading software in browser. (Text to speech )

## Meta
```<head> ... </head>``` - main stuff for holding data. stores meta data.

```<meta charset="UTF-8">``` - encoding in the browser. **UNICODE** to use beter.

```<meta name="viewport" content="width=device-width, initial-scale=1.0">``` - size of device

```<title>Document</title>``` - name of tab

## Body
```<body> ... </body>``` - main structure of website

## Headers
```h1, h2, h3, h4, h5, h6```

```<h1></h1>```

## Секции несемантични
- несемантични - нямат значение във файла
    
```html
<span> Inline text here. </span>
<div> Block content here. </div>
```
- div - събирателен content 
 - доста antipattern да се изпозлва навсякъде
 - използвайте го в краен случай, ползвай го ако няма алтернатива за него

### Span vs div
- Span е inline, тоест може да ги слагаме един след друг.
- Div е целия ред


добре е да си оправяме таговете и да ги затваряме

### Link

```<a href="" title="" target="_blank" rel="noopener noreferrer"> text </a>```
 - href - link
 - title - some meta data
 - text - visualzied link as "text"
 - `target="_blank"` - opens in new tab
 - `rel="noopener noreferrer"` - the new site cannot control original page and cannot see where the page was open from


### images
```<img src="http://example.com/image.jpg" alt="Example Image" />```
- `src="http://example.com/image.jpg"` - where is image stores. It is not part of html, it is downloaded from browser separately
- `alt="Example Image"` - describes the image. used by Text-to-speech systems also or if the image is missing, this text is displayed

### favicon
```<link rel="icon" href="Cat.png" type="image/png">``` - display image as favicon ( the image left of the tab )



# select element 
- горе-отляво на inspect и може да видим къде се намира някакъв елемент от страницата в самия html 




# Resources
- https://webtech.w3c.fmi.uni-sofia.bg/w16labs/INTRO.html#1
- https://info.cern.ch/hypertext/WWW/TheProject.html