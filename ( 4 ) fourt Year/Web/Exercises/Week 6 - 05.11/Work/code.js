

function render(todos){

    todos.forEach(element => {
        const item = document.createElement('li');
        item.textContent = element.title;
        document.getElementById("List").append(item);

        if(element.completed){
            item.classList.add('done');
            
        }
    });



}

async function getTasks(){
    const response = await fetch('https://jsonplaceholder.typicode.com/todos?userId=1');
    const todos = await response.json();
    // console.log(todos); 
    render(todos);
}

getTasks();