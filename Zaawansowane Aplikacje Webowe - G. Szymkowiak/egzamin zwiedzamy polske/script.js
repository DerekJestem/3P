let images = [1, 2, 3, 4, 5, 6, 7]
let image = 1

const imageElement = document.getElementById('main-image')

function next() {
    image++
    
    if (image == images.length+1) {
        image = 1
    }

    imageElement.src = `${image}.jpg`
}

function prev() {
    image--
    
    if (image == 0) {
        image = images.length
    }

    imageElement.src = `${image}.jpg`
}


document.getElementById('button-prev').addEventListener("click", () => {
    prev()
})

buttonPrev = document.getElementById('button-next').addEventListener("click", () => {
    next()
})