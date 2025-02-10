
const DEBUG = false

function DebugLog(message){
  if(!DEBUG) return;
  console.log("%cDebug logs : " + message, 'color: lime');
}

function DebugError(message){
  if(!DEBUG) return;
  console.log("%cDebug error : " + message, 'color: red');
}


DebugLog("Debug mode is on");
