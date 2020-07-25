
function createArrayOfFunctions(y) {
    var arr = [];
    for(var i = 0; i<y; i++) {
     arr[i] = F;
    
    }
    return arr;
  }

function F(x,j){
    return x+j;
}

var array = createArrayOfFunctions(5);
for (var k=0;k<5;k++){
    var x = 5;
    console.log(array[k](x,k))
}