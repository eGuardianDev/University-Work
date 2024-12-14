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
    
    for(let i =0;i<=1;i+=0.001){
        
        let pos =calculateAtPos(i);
        ctx.beginPath();
        ctx.fillRect(pos.resX, pos.resY, 1, 1);
        ctx.stroke();
    }


}