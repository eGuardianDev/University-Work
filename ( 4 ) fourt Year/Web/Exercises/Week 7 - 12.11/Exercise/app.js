

async function getData(){
    const response = await fetch('https://jsonplaceholder.typicode.com/todos?userId=1');
    // console.log(response.json());   // if this is on, the below is
    const data = await response.json() // response already consumed
    return data
}

todos = []

function setupPage(){
    const loadingElement = document.getElementById("LoadingText");
    loadingElement.textContent = "Списък със задачи.";

}

function taskClickFunction(item, index){
    item.classList.toggle("done");
    todos[index].completed = !todos[index].completed;
    const element = document.getElementById('CompletedCount');
    element.textContent = `Приключени: ${todos.filter((task) => task.completed).length} / ${todos.length}`;
}

function displayTask(element,index){
    const item = document.createElement('li');
    item.textContent = element.title;
    document.getElementById("List").append(item);
    item.setAttribute("data-id", index)

    if(element.completed){
        item.classList.add("done");
    }
    return item;
    
}
function updateCount(){
    const element = document.getElementById('CompletedCount');
    element.textContent = `Приключени: ${todos.filter((task) => task.completed).length} / ${todos.length}`;
}

async function render(){

    try{

        const response = await fetch('https://jsonplaceholder.typicode.com/todos?userId=1');
        if(!response.ok){
            throw new Error("Грешка");
        }
        todos = await response.json();
        setupPage();

        todos.forEach((element,index) => {
            const item = displayTask(element,index);
            item.addEventListener('click', () => {
                taskClickFunction(item, index);
            });
        });
    }catch(error){
        loadingElement.textContent = `Проблем при зареждането`;
    }
}

function addTask(){
    
}

const form = document.querySelector("form");
form.addEventListener('submit', async(e) => {
    e.preventDefault();

    const formData = new FormData(form);
    const text = formData.get('text');

    //check if text is not valid with `trim`

    const response = await fetch('https://jsonplaceholder.typicode.com/todos',{
        method: 'POST',
        // add header content type json
        body: JSON.stringify({text, complete: false, userId:1 })
    });

    const result = await response.json();
    console.log(result);
    //check response

    // push to todo
    // render again
})

render();

