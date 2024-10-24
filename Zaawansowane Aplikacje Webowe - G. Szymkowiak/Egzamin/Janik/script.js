const chat = document.getElementById("chat");

function wyslij()
{
    let wiadomosc = document.getElementById("wiadomosc").value;

    chat.innerHTML += `<div class="wiadomosc-jolanta">
                        <img src="./Jolka.jpg">
                        <p>${wiadomosc}</p>
                    </div>`;

                    
    chat.lastChild.scrollIntoView();
}

function generujOdpowiedz()
{
    const teksty = ["Świetnie!", "Kto gra główną rolę?", "Lubisz filmy Tego reżysera?", "Będę 10 minut wcześniej", "Może kupimy sobie popcorn?","Ja wolę Colę", "Zaproszę jeszcze Grześka", "Tydzień temu też byłem w kinie na Diunie", "Ja funduję bilety"]

    var losowaLiczba = (Math.random() * 8).toFixed();

    chat.innerHTML += `<div class="wiadomosc-krzysztof">
                        <img src="./Krzysiek.jpg">
                        <p>${teksty[losowaLiczba]}</p>
                    </div>`;

    chat.lastChild.scrollIntoView();
}