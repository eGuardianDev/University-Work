
const circleRadius = 10;
const offset_Selector = 0.1;





let VisibleControlPoligon = true;

function updateControlPoligon(caller){
  CleanCanvas();
  Redraw();
}


function updateDrawingCurve(caller){
  CleanCanvas();
  Redraw();
}
function updateFirstPolarDraw(caller){
  CleanCanvas();
  Redraw();
}
function updateDrawControlPoints(caller){
  if(!caller.checked){
    document.getElementById("DrawTextCheckbox").checked = false;
  }
  CleanCanvas();
  Redraw();
}
function updateDrawText(caller){
  CleanCanvas();
  Redraw();
}
function updateFirstPolar(caller){
  let polarControlPointCheckBox =  document.getElementById("DrawPolarControlPointsCheckbox");
  polarControlPointCheckBox.checked = caller.checked;
  polarControlPointCheckBox.disabled = !caller.checked;
  
  CleanCanvas();
  Redraw();
}

function updatePolarSlider(caller){
  let polarSlider =  document.getElementById("polarSlider");
  let polarNumberBox =  document.getElementById("polarNumberBox");
  if(caller == polarSlider){
    polarNumberBox.value = polarSlider.value;
  }else{
    let val = polarNumberBox.value;
    if(val < 0) val = 0;
    else if(val > 1) val = 1;
    else{
      polarSlider.value = val;
      // polarNumberBox.value = val;
    }
  }
  
  CleanCanvas();
  Redraw();
}
function updatePolarNumber(caller){
  let val = caller.value;
  if(val < 0) val = 0;
  else if (val >1) val = 1;
  caller.value = val;
}


const canvas = document.getElementById("DisplayBox");
document.addEventListener("DOMContentLoaded", function () {
  canvas.width = window.innerWidth * 70 / 100;
  canvas.height = window.innerHeight * 97 / 100;
});

var ctx;
function draw() {
  if (canvas.getContext) {
    ctx = canvas.getContext("2d");
    canvas.width = window.innerWidth * 70 / 100;
    canvas.height = window.innerHeight * 97 / 100;
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
  ctx.color = "black";
  ctx.font = "25px Arial";
  

  if(document.getElementById("ControlPoligonCheckbox").checked){
    for(let i =1;i<controlPoints.length; ++i){
      ctx.beginPath(); // Start a new path
      ctx.moveTo(controlPoints[i-1].x, controlPoints[i-1].y); // Move the pen to (30, 50)
      ctx.lineTo(controlPoints[i].x, controlPoints[i].y); // Draw a line to (150, 100)
      ctx.stroke(); // Render the path
    }
  }

  for(let i =0;i<controlPoints.length; ++i){
    // console.log(controlPoints[i]);
    ctx.beginPath();


    var tempX = controlPoints[i].x;
    if(i <controlPoints.length-1){
      tempX -= controlPoints[i+1].x;
    }else{
      if(controlPoints.length >1){
        tempX -= controlPoints[i-1].x;
      }
    }

    var offsetX =10
    if(tempX < 0) offsetX = -40;

    
    if(document.getElementById("DrawTextCheckbox").checked){
      ctx.color = "black";
      ctx.fillText("b"+i,controlPoints[i].x + offsetX, controlPoints[i].y);
    }


    if(document.getElementById("DrawControlPointsCheckbox").checked){
      ctx.arc(controlPoints[i].x, controlPoints[i].y, circleRadius, 0, 2 * Math.PI, true);
      ctx.arc(controlPoints[i].x, controlPoints[i].y, circleRadius, 0, 2 * Math.PI, true);
      ctx.stroke();
    }
  }

  if(document.getElementById("DrawingCurveCheckbox").checked){
    drawCurve();
  }
  
  if(document.getElementById("DrawingFirstPolarCheckbox").checked){
    let t0 = document.getElementById("polarSlider").value;
    let drawPolarControlPoints = document.getElementById("DrawPolarControlPointsCheckbox").checked;
    drawFirstPolar(t0,drawPolarControlPoints);
  
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
  
  var radios = document.getElementsByName('SelectMode');
  for (var i = 0, length = radios.length; i < length; i++) {
    if (radios[i].checked) {
      CurrentControl = radios[i].value;
      break;
    }
  }

}); 

canvas.addEventListener("mousedown", function (e) {
  getMousePosition(canvas, e);
}); 

var download = function(){
  var link = document.createElement('a');
  link.download = 'Bezier.png';
  link.href = document.getElementById('DisplayBox').toDataURL()
  link.click();
  link.remove();  
}

