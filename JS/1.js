//传入这些方法中的函数会接收三个参数：数组项的值、该项在数组中的位置和数组对象本身
var numbers = [1, 2, 3, 4, 5, 4, 3, 2, 1];
var someResult = numbers.some(function (item, index, array) {
    return (item > 2);
});
//alert(someResult);
console.log(someResult)

var numbers = [1,2,3,4,5,4,3,2,1];
var filterResult = numbers.filter(function(item, index, array){
return (item > 2);
});
console.log(filterResult)



