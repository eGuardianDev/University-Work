

console.log("Hello world");

let age = 21;
age = 20;


const name = "Maria";


if(false){
    console.log("false");
}
if(0){
    console.log("false");
}
if(undefined){
    console.log("false");
}
if(null){
    console.log("false");
}


const title = document.querySelector('#title');
console.log(title);

const drinks = document.querySelectorAll('.drink');
console.log(drinks);

const byId = document.getElementById("title");
console.log(byId);

drinks.forEach(d => console.log(d.textContent));


// title.textContent = "Main text";
// title.style.color = "red";


title.classList.add('highlight');

// const input = document.querySelector('#email').value;

// button.dataset.filter


// const item = document.createElement('li');

// item.textContent = 'Coffe';
// item.classList.add('drink');

// document.querySelector('ul').append(item);

// item.remove();

const button = document.querySelector('#hello');
button.addEventListener('click', function (event){
    console.log("Hello");
});
// click
// input - като запишем текст
// change - смяна на фокус
// submit - при пращане на form
// keydown - като натиснем клавиш докато е selected
// - document.addEvenetListenre('keydown' ... ) за целия документ


// FormData.addEventListener('submit', function(event){
//     event.preventDefault();
// }) // спира да се изпрати и да се refresh-не страницата

const student = {name: 'Ivan', year: 4}

const text = JSON.stringify(student); // object to text
const back = JSON.parse(text); // text to object

console.log(text); // text 
console.log(back); // object




async function loadUsers(){
    const response = await fetch('https://jsonplaceholder.typicode.com/users'); // без да презарежда страницата
    const users = response.json();
    console.log(users);
}

// loadUsers();

async function sendMessage(){
    const response = await fetch('https://jsonplaceholder.typicode.com/posts',{
        method:'POST',
        header: {'Content-Type': 'application/json'},
        body: JSON.stringify({title: 'Hi', body:'Message'})
    }); 
    const result = response.json();
    console.log(result);
} //AJAX - background talking between server and page


sendMessage();
