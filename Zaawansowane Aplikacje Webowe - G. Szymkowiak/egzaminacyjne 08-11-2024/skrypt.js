function toSecondBlock() {
    document.getElementById('blok1').style.display = 'none';
    document.getElementById('blok2').style.display = 'block';
}

function toThirdBlock() {
    document.getElementById('blok2').style.display = 'none';
    document.getElementById('blok3').style.display = 'block';
}

function confirm() {
    event.preventDefault()

    const imie = document.querySelectorAll('#blok1 input[type="text"]')[0].value;
    const nazwisko = document.querySelectorAll('#blok1 input[type="text"]')[1].value;

    const haslo1 = document.querySelectorAll('#blok3 input[type="password"]')[0].value;
    const haslo2 = document.querySelectorAll('#blok3 input[type="password"]')[1].value;

    if (haslo1 !== haslo2) {
        alert("Podane hasła różnią się");
    } else {
        console.log(`Witaj ${imie} ${nazwisko}`);
    }

}