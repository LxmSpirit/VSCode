/** 
其中的模式（pattern）部分可以是任何简单或复杂的正则表达式。

标志（flags），用以标明正则表达式的行为，支持下列3 个标志：

g：表示全局（global）模式，即模式将被应用于所有字符串，而非在发现第一个匹配项时立即停止

i：表示不区分大小写（case-insensitive）模式，即在确定匹配项时忽略模式与字符串的大小写

m：表示多行（multiline）模式，即在到达一行文本末尾时还会继续查找下一行中是否存在与模式匹配的项。


* 匹配第一个"bat"或"cat"，不区分大小写

var pattern1 = /[bc]at/i;

* 与pattern1 相同，只不过是使用构造函数创建的

var pattern2 = new RegExp("[bc]at", "i");

模式中使用的所有元字符都必须转义。正则表达式中的元字符包括：( [ { \ ^ $ | ) ? * + .]}

*/

var text = "mom and dad and baby";
var pattern = /mom( and dad( and baby)?)?/gi;
var matches = pattern.exec(text);
// alert(matches.index); // 0
// alert(matches.input); // "mom and dad and baby"
// alert(matches[0]); // "mom and dad and baby"
// alert(matches[1]); // " and dad and baby"
// alert(matches[2]); // " and baby"
console.log(matches);