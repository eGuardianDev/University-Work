function binomialCoefficient(n, k) {
    if (k === 0 || k === n) return 1;
    let res = 1;
    for (let i = 1; i <= k; i++) {
        res *= (n - i + 1) / i;
    }
    return res;
}

const b = (i,n,t) =>{
    return binomialCoefficient(n,i)*Math.pow(t,i)*Math.pow(1-t,n-i);
};

function calculateAtPos(t){
    
    let resX = 0, resY =0;
    let count = controlPoints.length;
    for(let i = 0;i<count;++i){
        resX += b(i,count-1,t) * controlPoints[i].x;
        resY += b(i,count-1,t) * controlPoints[i].y;
    }
    return {resX,resY};
}

function drawCurve(event){
    // controlPoints
    
    let pos =calculateAtPos(0);
    ctx.lineWidth = 2;
    ctx.strokeStyle = "grey";
    for(let i =0;i<=1;i+=0.001){
        
        
        pos =calculateAtPos(i);
        // behold - the bad anti-aliasing 
        ctx.beginPath();
        ctx.moveTo(pos.resX, pos.resY); 
        pos =calculateAtPos(i+0.001);
        ctx.lineTo(pos.resX, pos.resY); 
        ctx.stroke();
    }
    ctx.strokeStyle = "black";
    ctx.lineWidth = 0.5;
    for(let i =0;i<=1;i+=0.001){        
        pos =calculateAtPos(i);
        ctx.beginPath();
        ctx.moveTo(pos.resX, pos.resY); 
        pos =calculateAtPos(i+0.001);
        ctx.lineTo(pos.resX, pos.resY); 
        ctx.stroke();
    }
    ctx.strokeStyle = "black";

   


}