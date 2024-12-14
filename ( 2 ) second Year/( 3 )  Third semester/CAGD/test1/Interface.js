
const circleRadius = 10;
const offset_Selector = 0.1;

let VisibleControlPoligon = true;

function updateControlPoligon(caller){
  VisibleControlPoligon = caller.checked;
  CleanCanvas();
  Redraw();
}


const canvas = document.getElementById("DisplayBox");
var ctx;
function draw() {
  if (canvas.getContext) {
    ctx = canvas.getContext("2d");
  }else{
    DebugLog("This browser doesn't support canvas functionality in 2D");

  }
}
window.addEventListener("load", draw);



const UIControl = {
  add: "Add",
  move: "Move",
  delete: "Delete"
};
controlPoints = []
let CurrentControl = UIControl.add;

// when moved
let currentMovingElementFlag = false;
let currentMovingElementIndex = -1;

function getMousePosition(canvas, event) {
  let rect = canvas.getBoundingClientRect();
  let x = event.clientX - rect.left;
  let y = event.clientY - rect.top;
  DebugLog("Coordinate: "+ x + ","+ y);
 

  switch(CurrentControl){
    case UIControl.add:
      controlPoints.push({x,y});
      CleanCanvas();
      Redraw();
      
      break;
    case UIControl.move:
      SelectControlPoint(event);
      CleanCanvas();
      Redraw();
      
      break;
    case UIControl.delete:
      RemoveElement(event);
      break;
    default:
      DebugLog("Non Selected/Invalid Selected");

  }
  
  // ctx.clearRect(0, 0, canvas.width, canvas.height);
  // ctx.beginPath();
  // ctx.arc(x, y, 10, 0, 2 * Math.PI, true);
  // ctx.stroke();
}


function SelectControlPoint(event){
    let rect = canvas.getBoundingClientRect();
    let x = event.clientX - rect.left;
    let y = event.clientY - rect.top;
  for(let i = 0;i<controlPoints.length;++i){
    let aX = controlPoints[i].x - circleRadius - offset_Selector;
    let bX = controlPoints[i].x + circleRadius + offset_Selector;
    let aY = controlPoints[i].y - circleRadius - offset_Selector;
    let bY = controlPoints[i].y + circleRadius + offset_Selector;
    
    if(aX< x && x< bX && aY < y && y < bY){
      currentMovingElementIndex = i;
      currentMovingElementFlag = true;
      MovingElement(event);
      break;
    }
    
  }
}
function RemoveElement(event){
  if((CurrentControl == UIControl.delete )){
    let rect = canvas.getBoundingClientRect();
    let x = event.clientX - rect.left;
    let y = event.clientY - rect.top;
    let removingElementIndex = -1;
    for(let i = 0;i<controlPoints.length;++i){
      let aX = controlPoints[i].x - circleRadius - offset_Selector;
      let bX = controlPoints[i].x + circleRadius + offset_Selector;
      let aY = controlPoints[i].y - circleRadius - offset_Selector;
      let bY = controlPoints[i].y + circleRadius + offset_Selector;
      
      if(aX< x && x< bX && aY < y && y < bY){
        removingElementIndex = i;
        break;
      }
   }  

    if(removingElementIndex != -1){
      controlPoints.splice(removingElementIndex,1);
      CleanCanvas();
      Redraw();
    }

  }  
}

function MovingElement(event){
  if((CurrentControl == UIControl.move ) && currentMovingElementFlag){
    let rect = canvas.getBoundingClientRect();
    let x = event.clientX - rect.left;
    let y = event.clientY - rect.top;
    controlPoints[currentMovingElementIndex]= {x,y}   
    
    CleanCanvas();
    Redraw();
  }  
}
function ReleaseElementFromMoving(event){
  if((CurrentControl == UIControl.move ) && currentMovingElementFlag == true ){
    currentMovingElementFlag = false;
    currentMovingElementIndex = -1;
    CleanCanvas();
    Redraw();
  }  
}






//  * === Standart Drawing Functions ===
function CleanCanvas(){
  ctx.clearRect(0, 0, canvas.width, canvas.height);
}

function Redraw(){
  for(let i =0;i<controlPoints.length; ++i){
    // console.log(controlPoints[i]);
    ctx.beginPath();
    ctx.arc(controlPoints[i].x, controlPoints[i].y, circleRadius, 0, 2 * Math.PI, true);
    ctx.stroke();
  }

  if(VisibleControlPoligon){
    for(let i =1;i<controlPoints.length; ++i){
      ctx.beginPath(); // Start a new path
      ctx.moveTo(controlPoints[i-1].x, controlPoints[i-1].y); // Move the pen to (30, 50)
      ctx.lineTo(controlPoints[i].x, controlPoints[i].y); // Draw a line to (150, 100)
      ctx.stroke(); // Render the path
    }
  }
  
}



function DetectPoint(event){
  let rect = canvas.getBoundingClientRect();
  let x = event.clientX - rect.left;
  let y = event.clientY - rect.top;

  for(let i = 0;i<controlPoints.length;++i){
    let aX = controlPoints[i].x - circleRadius - offset_Selector;
    let bX = controlPoints[i].x + circleRadius + offset_Selector;
    let aY = controlPoints[i].y - circleRadius - offset_Selector;
    let bY = controlPoints[i].y + circleRadius + offset_Selector;
    
    if(aX< x && x< bX && aY < y && y < bY){
      return i;
    }
 }  

 return -1;
}



function GlowSelectablePoint(event){
  if(CurrentControl == UIControl.delete || CurrentControl == UIControl.move)
  {
    if(currentMovingElementFlag) return;

    let i =DetectPoint(event);
    
    CleanCanvas();
    Redraw();
    if(i != -1){
      ctx.strokeStyle='red';
      ctx.beginPath();
      ctx.arc(controlPoints[i].x, controlPoints[i].y, circleRadius+5, 0, 2 * Math.PI, true);
      ctx.arc(controlPoints[i].x, controlPoints[i].y, circleRadius+4, 0, 2 * Math.PI, true);
      ctx.arc(controlPoints[i].x, controlPoints[i].y, circleRadius+3, 0, 2 * Math.PI, true);
      ctx.stroke();
    }
    ctx.strokeStyle='black';
  }  

}



// * == event listeners ===

canvas.addEventListener("mouseup", function (e) {
  ReleaseElementFromMoving(e);
  GlowSelectablePoint(e);
}); 

canvas.addEventListener("mousemove", function (e) {
  MovingElement(e);
  GlowSelectablePoint(e);

  var selector = document.getElementById( "modesSelectorId" );
  CurrentControl = selector.options[ selector.selectedIndex ].value

}); 

canvas.addEventListener("mousedown", function (e) {
  getMousePosition(canvas, e);
}); 