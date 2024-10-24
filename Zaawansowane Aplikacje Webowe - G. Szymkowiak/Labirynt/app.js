
const area = document.querySelector(".area");
const ctx = area.getContext("2d");

const width = area.width;
const height = area.height;

const size = 20;
const step = size;

let x = 0;
let y = 20;

const maze = [
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1],
    [1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1],
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1],
    [1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1],
    [1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1],
    [1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1],
    [1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1],
    [1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1],
    [1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1],
    [1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1],
    [1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1],
    [1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1],
    [1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1],
    [1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1],
    [1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1],
    [1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1],
    [1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 2],
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
];

function drawMaze()
{
    ctx.fillStyle = "grey";

    for(let i = 0; i < maze.length; i++)
    {
        for(let j = 0; j < maze.length; j++)
        {
            if(maze[i][j] == 1)
            {
                let mazeX = (j * size) + 0.5;
                let mazeY = (i * size) + 0.5;
                ctx.fillRect(mazeX, mazeY, size - 1, size - 1);
            }
        }
    }
}

function isWon()
{
    let mazeX = x / size;
    let mazeY = y / size;

    if(maze[mazeY][mazeX] == 2)
    {
        alert("Wygrałeś");
        location.reload();
    }
}

function clear()
{
    ctx.clearRect(x, y, size, size);
}

function canMove(xDirection, yDirection)
{
    let xStepDirection = xDirection * step;
    let yStepDirection = yDirection * step;

    if(y + yStepDirection + size > height || y + yStepDirection < 0 || x + xStepDirection + size > width || x + xStepDirection < 0)
        return false;

    let mazeX = x / size + xDirection;
    let mazeY = y / size + yDirection;

    if(maze[mazeY][mazeX] == 1)
        return false;

    return true;
}

function drawSquare()
{
    ctx.fillStyle = "red";
    ctx.fillRect(x, y, size, size);
}

function moveSquare(e)
{
    switch(e.key)
    {
        case "ArrowUp":
            clear();
            if (canMove(0, -1)) y -= step;
            break;
        case "ArrowDown":
            clear();
            if (canMove(0, 1)) y += step;
            break;
        case "ArrowLeft":
            clear();
            if (canMove(-1, 0)) x -= step;
            break;
        case "ArrowRight":
            clear();
            if (canMove(1, 0)) x += step;
            break;
    }

    drawSquare();

    setTimeout(isWon, 100);
}

window.addEventListener("keydown", moveSquare);

drawMaze();
drawSquare();