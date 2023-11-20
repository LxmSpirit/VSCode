// 设置画布

const canvas = document.querySelector('canvas');
const ctx = canvas.getContext('2d');

const width = canvas.width = window.innerWidth;
const height = canvas.height = window.innerHeight;

// 生成随机数的函数

function random(min,max) {
  const num = Math.floor(Math.random() * (max - min)) + min;
  return num;
}


function randomColor() {
  return 'rgb(' +
         random(0, 255) + ', ' +
         random(0, 255) + ', ' +
         random(0, 255) + ')';
}

// 这个构造器中定义了每个小球需要的参数：

// x 和 y 坐标 —— 小球在屏幕上最开始时候的坐标。坐标的范围从 0（左上角）到浏览器视口的宽和高（右下角）。
// 水平和竖直速度（velX 和 velY）—— 我们会给每个小球一个水平和竖直速度。实际上，当我们让这些球开始运动时候，每过一帧都会给小球的 x 和 y 坐标加一次这些值。
// color —— 每一个小球会有自己的颜色。
// size —— 每一个小球会有自己的大小 — 也就是小球的半径，以像素为单位。
// 这里说明了小球的属性，那么方法呢？别忘了我们要让小球动起来。

function Ball(x, y, velX, velY, color, size) {
  this.x = x;
  this.y = y;
  this.velX = velX;
  this.velY = velY;
  this.color = color;
  this.size = size;
}


// 通过使用这个函数，通过使用我们之前定义的 ctx对象 的方法，我们就可以让在屏幕上画出小球了。ctx 的内容区域就像是一张纸，现在我们就可以命令我们的笔画一点东西。

// 首先，我们使用 beginPath() 来声明我们现在要开始在纸上画一个图形了。
// 然后，我们使用 fillStyle 来定义这个图形的颜色 — 这个值正是小球的颜色属性。
// 接下来，我们使用 arc() 方法来在纸上画出一段圆弧。有这些参数：
// x 和 y 是圆弧的中心的坐标 —— 也就是小球的中心坐标。
// 圆弧的半径 —— 小球的半径。
// 最后两个参数是开始和结束，也就是圆弧对应的夹角，单位以弧度表示。这里我们用的是 0 和 2 * PI，也就是 360 度（如果你设置成 0 和 1 * PI，则只会出现一个半圆，也就是 180 度）
// 最后，我们使用 fill() 方法，也就是声明我们结束了以 beginPath() 开始的绘画，并且使用我们之前设置的颜色进行填充。

Ball.prototype.draw = function() {
  ctx.beginPath();
  ctx.fillStyle = this.color;
  ctx.arc(this.x, this.y, this.size, 0, 2 * Math.PI);
  ctx.fill();
}

// 函数的前四个部分用来检查小球是否碰到画布的边缘。如果碰到，我们反转小球的速度方向来让它向反方向移动。就比如说，如果小球正向上移动（正 velY），然后垂直速度发生改变，小球就向下移动（负 velY）。

// 在这四部分中，我们：

// 检查小球的 x 坐标是否大于画布的宽度（小球会从右边缘离开）。
// 检查小球的 x 坐标是否小于 0（小球会从左边缘离开）。
// 检查小球的 y 坐标是否大于画布的高度（小球会从下边缘离开）。
// 检查小球的 y 坐标是否小于 0（小球会从上边缘离开）。
// 在每种情况下，我们都会加上小球的半径，因为 x/y 坐标是小球中心的坐标，我们希望小球在其边界接触浏览器窗口的边界时反弹，而不是小球的一部分都不见了再返回。

// 最后两行，我们将 velX 的值加到 x 的坐标上，将 velY 的值加到 y 坐标上 —— 每次调用这个方法的时候小球就移动这么多。


Ball.prototype.update = function() {
  if ((this.x + this.size) >= width) {
    this.velX = -(this.velX);
  }

  if ((this.x - this.size) <= 0) {
    this.velX = -(this.velX);
  }

  if ((this.y + this.size) >= height) {
    this.velY = -(this.velY);
  }

  if ((this.y - this.size) <= 0) {
    this.velY = -(this.velY);
  }

  this.x += this.velX;
  this.y += this.velY;
}

// 这个方法有一点点复杂，如果不理解的话不必过分担心，下面是对它的解释：
// 对于每个小球，我们都要检查其他的小球是否和当前这个小球相撞了。为了达到此目的，我们构造另外一个 for 循环来遍历 balls[] 数组中的小球。
// 在循环里面，我们使用一个 if 语句来检查遍历的小球是否是当前的小球。我们不希望检测到一个小球撞到了自己！
// 为了达到这个目的，我们需要检查当前小球(即正在调用 collisionDetect 方法的球) 是否和被循环到的小球(for 循环检测中的当前遍历所引用的球) 是不是同一个。
// 我们使用! 来否定判断，因此只有两个小球不是同一个时，条件判断中的代码才会运行。
// 我们使用了一个常见的算法来检测两个小球是否相撞了，两个小球中心的距离是否小于两个小球的半径之和。这些会在 2D 碰撞检测 介绍地更加详细。
// 如果检测到了碰撞，会运行 if 语句中的代码。我们会将两个小球的颜色都设置成随机的一种。
// 我们也可以将这步操作变得复杂一点，比如让两个小球弹开，那样需要植入更加复杂的代码。像这样的物理场景，有以下专门的库比如 PhysicsJS，matter.js，Phaser 等。

Ball.prototype.collisionDetect = function() {
  for (let j = 0; j < balls.length; j++) {
    if (this !== balls[j]) {
      const dx = this.x - balls[j].x;
      const dy = this.y - balls[j].y;
      const distance = Math.sqrt(dx * dx + dy * dy);

      if (distance < this.size + balls[j].size) {
        balls[j].color = this.color = randomColor();
      }
    }
  }
}


// 首先我们需要一个地方储存小球
let balls = [];

while (balls.length < 25) {
    let size = random(10, 20);
    let ball = new Ball(
      // 为避免绘制错误，球至少离画布边缘球本身一倍宽度的距离
      random(0 + size, width - size),
      random(0 + size, height - size),
      random(-7, 7),
      random(-7, 7),
      randomColor(),
      size
    );
    balls.push(ball);
}
  
// loop() 函数做了下面的事情：
// 将整个画布的颜色设置成半透明的黑色。然后使用 fillRect()（这四个参数分别是起始的坐标、绘制的矩形的宽和高）画出一个填充满整个画布的矩形。
// 这是在下一个视图画出来时用来遮住之前的视图的。如果不这样做得话，你就会在屏幕上看到一条蛇的形状而不是小球的运动了。
// 用来填充的颜色设置成半透明的rgba(0, 0, 0, 0.25)，也就是让之前的视图留下来一点点，从而你可以看到小球运动时的轨迹。
// 如果你将 0.25 设置成 1 时，你就完全看不到了。试着改变其中的值查看造成的影响。
// 当且仅当小球数量小于 25 时，将 random() 函数产生的数字传入新的小球实例从而创建一个新的小球，并且加入到数组中。
// 因此当屏幕上有 25 个小球时，不会再出现更多小球。你可以改变这个值，从而看到不同小球个数造成的影响。如果你的电脑或者浏览器性能不怎么样的话，几千个小球的速度就会明显慢下来。
// 遍历数组中的所有小球，并且让每个小球都调用 draw() 和 update() 函数来将自己画出来，并且再接下来的每一帧都按照其速度进行位置的更新。
// 使用 requestAnimationFrame() 方法再运行一次函数 —— 当一个函数正在运行时传递相同的函数名，从而每隔一小段时间都会运行一次这个函数，这样我们可以得到一个平滑的动画效果。
// 这主要是通过递归完成的 —— 也就是说函数每次运行的时候都会调用自己，从而可以一遍又一遍得运行。


function loop() {
  ctx.fillStyle = 'rgba(0, 0, 0, 0.25)';
  ctx.fillRect(0, 0, width, height);

  for (let i = 0; i < balls.length; i++) {
    balls[i].draw();
    balls[i].update();
    balls[i].collisionDetect();
  }

  requestAnimationFrame(loop);
}

loop();


