function calculateAtPos(t,LocalControlPoints){
    let count = LocalControlPoints.length;

    let intermediatePoints = [LocalControlPoints]  

    for(let i = 0;i<count-1;++i){
        let prev = intermediatePoints[i];
        let newPoints = new Array(prev.length-1);
        
        for(let j =0;j<prev.length-1;++j){
            let first = prev[j];
            let second = prev[j+1];
            newPoints[j] = {
                x: (1-t)* first.x + t * second.x,
                y: (1-t)* first.y + t * second.y
            }
        }
        intermediatePoints.push(newPoints);
    
    }
    
    return intermediatePoints[intermediatePoints.length-1][0];
}

function calculateAtPosFirstPolar(t0,t,LocalControlPoints){
    let count = LocalControlPoints.length;
    
    let intermediatePoints = [LocalControlPoints]  

    for(let i = 0;i<count-1;++i){
        let prev = intermediatePoints[i];
        let newPoints = new Array(prev.length-1);
        for(let j =0;j<prev.length-1;++j){
            
            let first = prev[j];
            let second = prev[j+1];
            
            if(i == 0){
                newPoints[j] = {
                    x: (1-t0)* first.x + t0 * second.x,
                    y: (1-t0)* first.y + t0 * second.y
                }
            }else{
                newPoints[j] = {
                    x: (1-t)* first.x + t * second.x,
                    y: (1-t)* first.y + t * second.y
                }
            }
        }
        intermediatePoints.push(newPoints);
    }
    return intermediatePoints[intermediatePoints.length-1][0];
}

function PolarControlPoints(t0,LocalControlPoints){
    
    
    let count = LocalControlPoints.length;
    if(count <= 2) {
        return [];
    }
    let PolarControlPoints = new Array(count-1);
        
    for(let j =0;j<count-1;++j){
        
        let first = LocalControlPoints[j];
        let second = LocalControlPoints[j+1];
        
        PolarControlPoints[j] = {
            x: (1-t0)* first.x + t0 * second.x,
            y: (1-t0)* first.y + t0 * second.y
        }

    }

    return PolarControlPoints;
}

function drawCurve(){
    if(controlPoints.length <=1){
        return;
    }
    ctx.lineWidth = 2;
    ctx.strokeStyle = "grey";

    for(let i =0;i<=1;i+=0.001){   
        pos =calculateAtPos(i,controlPoints);

        ctx.beginPath();
        ctx.moveTo(pos.x, pos.y); 

        pos =calculateAtPos(i+0.001,controlPoints);
        
        ctx.lineTo(pos.x, pos.y); 
        ctx.stroke();
    }
    
    ctx.strokeStyle = "black";
}


function drawFirstPolar(t0){
    
    if(t0 < 0 || t0 > 1){
        DebugError("Polar t0 is out of [0,1] bound");
        return;
    }

    if(controlPoints.length <=2){
        return;
    }

    for(let i =0;i<=1;i+=0.001){   
        let pos =calculateAtPosFirstPolar(t0,i,controlPoints);

        ctx.beginPath();
        ctx.moveTo(pos.x, pos.y); 

        pos =calculateAtPosFirstPolar(t0,i+0.001,controlPoints);
        
        ctx.lineTo(pos.x, pos.y); 
        ctx.lineWidth = 2;
        ctx.strokeStyle = "green";
        ctx.stroke();
    }

   
    ctx.strokeStyle = "black";
}