

// * Some default parameters
// * ====================================
const circleRadius = 10;
const offset_Selector = 0.1;



// * Checkbox settings sync
// * ============================================
// This functions help the checkboxes change value,
// if "parent box" is toggled or not

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
    document.getElementById("DrawTextCheckbox").checked = caller.checked;
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
  
  CleanCanvas();
  Redraw();
}


// sync text box and slider for first polar parameter
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
    }
  }
  
  CleanCanvas();
  Redraw();
}

// This function is used for limiting the textbox with 
// first polar parameter in the interface
function updatePolarNumber(caller){
  let val = caller.value;
  if(val < 0) val = 0;
  else if (val >1) val = 1;
  caller.value = val;
}


// * First loading dynamic fixes
// * ============================================
//This functions help configure canvas size when page is loaded

const canvas = document.getElementById("DisplayBox");
const BernsteinPolynomialGraph = document.getElementById("BernsteinPolynomialGraph");

document.addEventListener("DOMContentLoaded", function () {
  canvas.width = window.innerWidth * 70 / 100;
  canvas.height = window.innerHeight * 97 / 100;
});

var ctx;
var graphCtx;
function InitalizeSizeOfCanvas() {
  if (canvas.getContext) {
    ctx = canvas.getContext("2d");
    canvas.width = window.innerWidth * 70 / 100;
    canvas.height = window.innerHeight * 97 / 100;
  }else{
    DebugLog("This browser doesn't support canvas functionality in 2D");

  }
  if (BernsteinPolynomialGraph.getContext) {
    graphCtx = BernsteinPolynomialGraph.getContext("2d");
  }else{
    DebugLog("This browser doesn't support canvas functionality in 2D");

  }
}

window.addEventListener("load", InitalizeSizeOfCanvas);




// * Control elements/Points
// * ================================
// This function help controlling the control points
// of the curve
// Here elements and points are used interchangeably

const UIControl = {
  add: "Add",
  move: "Move",
  delete: "Delete"
};
controlPoints = []
let CurrentControl = UIControl.add;

// when moved
let currentMovingControlPointFlag = false;
let currentMovingControlPointIndex = -1;

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
      RemoveControlPoint(event);
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
      currentMovingControlPointIndex = i;
      currentMovingControlPointFlag = true;
      MovingControlPoint(event);
      break;
    }
    
  }
}
function RemoveControlPoint(event){
  if((CurrentControl == UIControl.delete )){
    let rect = canvas.getBoundingClientRect();
    let x = event.clientX - rect.left;
    let y = event.clientY - rect.top;
    let removingControlPointIndex = -1;
    for(let i = 0;i<controlPoints.length;++i){
      let aX = controlPoints[i].x - circleRadius - offset_Selector;
      let bX = controlPoints[i].x + circleRadius + offset_Selector;
      let aY = controlPoints[i].y - circleRadius - offset_Selector;
      let bY = controlPoints[i].y + circleRadius + offset_Selector;
      
      if(aX< x && x< bX && aY < y && y < bY){
        removingControlPointIndex = i;
        break;
      }
    }  

    if(removingControlPointIndex != -1){
      controlPoints.splice(removingControlPointIndex,1);
      CleanCanvas();
      currentSelectedPoint = -1;
      Redraw();
      
    }

  }  
}

function MovingControlPoint(event){
  if((CurrentControl == UIControl.move ) && currentMovingControlPointFlag){
    let rect = canvas.getBoundingClientRect();
    let x = event.clientX - rect.left;
    let y = event.clientY - rect.top;
    controlPoints[currentMovingControlPointIndex]= {x,y}   
    
    CleanCanvas();
    Redraw();
  }  
}
function ReleasePointFromMoving(event){
  if((CurrentControl == UIControl.move ) && currentMovingControlPointFlag == true ){
    currentMovingControlPointFlag = false;
    currentMovingControlPointIndex = -1;
    CleanCanvas();
    Redraw();
  }  
}



function CleanCanvas(){
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  graphCtx.clearRect(0,0,BernsteinPolynomialGraph.width,BernsteinPolynomialGraph.height);
}


const binomialCache = {};
function binomial(n, k) {
  
  if (k > n) return 0;
  if (k === 0 || k === n) return 1;
  
  let key = `${n},${k}`;
  if (binomialCache[key] !== undefined) return binomialCache[key];

  binomialCache[key] = binomial(n - 1, k - 1) + binomial(n - 1, k);
  return binomialCache[key];
}

function RedrawBernsteinGraph(){
  let count = controlPoints.length;
  for(let i = 0;i<count; ++i){

    if(currentSelectedPoint == i){
      graphCtx.lineWidth = 2;
      graphCtx.strokeStyle = "red";
    }else{
      graphCtx.lineWidth = 1;
      graphCtx.strokeStyle = "black";
    }
    let translate = 256;
    
    let width =  BernsteinPolynomialGraph.width;
    let height = BernsteinPolynomialGraph.height;
    let step = 0.2;
    graphCtx.beginPath(); 
    for(let t= 0;t<= 1;t+=0.001){   
      let data =  binomial(count-1,i) 
                  * Math.pow(1-t,i)
                  * Math.pow(t,count-1-i);
      
      let x = width-(t*translate);
      let y = height-(data*translate);
      graphCtx.moveTo(x,      y);
      graphCtx.lineTo(x+step, y+step); 
    }
    graphCtx.stroke(); 
  }
}


// Redraw function checks from html if specific checkbox is toggled
// if so, specific rendering function is called
function Redraw(){
  RedrawBernsteinGraph();

  ctx.lineWidth = 2;
  ctx.fillStyle = "black";
  ctx.font = "25px Arial";
  

  if(document.getElementById("ControlPoligonCheckbox").checked){
    for(let i =1;i<controlPoints.length; ++i){
      ctx.beginPath(); 
      ctx.moveTo(controlPoints[i-1].x, controlPoints[i-1].y); 
      ctx.lineTo(controlPoints[i].x, controlPoints[i].y); 
      ctx.stroke(); 
    }
  }

  for(let i =0;i<controlPoints.length; ++i){
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
      ctx.fillStyle = "black";
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
  let t1 = document.getElementById("polarSlider").value;
  
  if(document.getElementById("DrawingFirstPolarCheckbox").checked){
    drawFirstPolar(t1);
  }

  if(document.getElementById("DrawPolarControlPointsCheckbox").checked 
      && controlPoints.length > 2){
    
      let polarControlPoints = PolarControlPoints(t1,controlPoints);
    for(let i = 0; i<polarControlPoints.length; ++i){

        ctx.beginPath();
        ctx.arc(polarControlPoints[i].x,
                polarControlPoints[i].y,
                 5, 0, 2 * Math.PI);
        ctx.fillStyle = "gray";
        ctx.fill();
        ctx.lineWidth = 1;
        ctx.strokeStyle = "DodgerBlue";
        ctx.stroke();
    }
    ctx.strokeStyle = "black";  
  }
}

// When mouse is over point
// used in events
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


// mark point as selectable
// adds red circle around point
// used in event
currentSelectedPoint = -1;
function GlowSelectablePoint(event){
  if(CurrentControl == UIControl.delete || CurrentControl == UIControl.move)
  {
    if(currentMovingControlPointFlag) return;

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
    currentSelectedPoint = i;
    ctx.strokeStyle='black';
  }  

}



// * == event listeners for mouse control on canvas ===
// * ==================================================

canvas.addEventListener("mouseup", function (e) {
  ReleasePointFromMoving(e);
  GlowSelectablePoint(e);
}); 

canvas.addEventListener("mousemove", function (e) {
  MovingControlPoint(e);
  GlowSelectablePoint(e);

  
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


// additional functions


function download(){
  var link = document.createElement('a');
  link.download = 'Bezier.png';
  link.href = document.getElementById('DisplayBox').toDataURL()
  link.click();
  link.remove();  
}

function CleanEveryPoint(){
  controlPoints = [];
  CleanCanvas();
}