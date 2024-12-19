const area = document.getElementById('game-area');
const ctx = area.getContext('2d');

let ballRadius = 10;
let aw = area.width;
let ah = area.height;
let balls = [];
let speedFactor = 1.5;

function rndCol() {
    const letters = '0123456789ABCDEF';
    let color = '#';
    for (let i = 0; i < 6; i++) {
        color += letters[Math.floor(Math.random() * 16)];
    }
    return color;
}

for (let i = 0; i < 5; i++) {
    balls.push({
        x: Math.random() * (aw - 2 * ballRadius) + ballRadius,
        y: Math.random() * (ah - 2 * ballRadius) + ballRadius,
        dx: (Math.random() * 2 - 1) * 2,
        dy: (Math.random() * 2 - 1) * 2,
        color: rndCol()
    });
}

function draw() {
    ctx.clearRect(0, 0, aw, ah);
    balls.forEach(ball => {
        ctx.beginPath();
        ctx.arc(ball.x, ball.y, ballRadius, 0, Math.PI * 2);
        ctx.fillStyle = ball.color;
        ctx.fill();
        ctx.closePath();
    });
}

function updatePos() {
    balls.forEach(ball => {
        ball.x += ball.dx;
        ball.y += ball.dy;

        if (ball.x + ball.dx > aw - ballRadius || ball.x + ball.dx < ballRadius) {
            ball.dx = -ball.dx;
        }
        if (ball.y + ball.dy > ah - ballRadius || ball.y + ball.dy < ballRadius) {
            ball.dy = -ball.dy;
        }
    });
}

function anim() {
    draw();
    updatePos();
    requestAnimationFrame(anim);
}

document.addEventListener('keydown', (event) => {
    if (event.key === 'ArrowUp') {
        event.preventDefault();
        balls.forEach(ball => {
            ball.dx *= speedFactor;
            ball.dy *= speedFactor;
        });
    } else if (event.key === 'ArrowDown') {
        event.preventDefault();
        balls.forEach(ball => {
            ball.dx /= speedFactor;
            ball.dy /= speedFactor;
            if (Math.abs(ball.dx) < 0.1) ball.dx = 1;
            if (Math.abs(ball.dy) < 0.1) ball.dy = 1;
        });
    }
});

anim();