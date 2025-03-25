package com.example.wieczorek

import android.content.Context
import android.media.AudioManager
import android.media.MediaPlayer
import android.media.ToneGenerator
import android.os.Bundle
import android.widget.Toast
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.*
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.buildAnnotatedString
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.compose.ui.text.withStyle
import androidx.compose.foundation.Image
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.text.SpanStyle
import androidx.compose.ui.text.font.FontWeight
import com.example.wieczorek.ui.theme.WieczorekTheme
import kotlin.random.Random

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            WieczorekTheme {
                WszystkieElementy()
            }
        }
    }
}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun WszystkieElementy() {
    val kontekstDlaWszystkichElementow = LocalContext.current
    var oczka by remember { mutableStateOf(listOf<Int>()) }
    var wynikRzutu by remember { mutableStateOf(0) }
    var sumaOgolna by remember { mutableStateOf(0) }
    var iloscProb by remember { mutableStateOf(0) }

    Column(
        modifier = Modifier.fillMaxSize(),
        verticalArrangement = Arrangement.Top,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        CenterAlignedTopAppBar(
            title = {
                Text("Gra w kości", fontWeight = FontWeight.ExtraBold, fontSize = 34.sp)
            },
            colors = TopAppBarDefaults.topAppBarColors(
                containerColor = Color(47, 79, 79, 255),
                titleContentColor = Color.White,
            )
        )
        Spacer(modifier = Modifier.height(40.dp))
        Row(
            horizontalArrangement = Arrangement.Center,
            verticalAlignment = Alignment.CenterVertically,
            modifier = Modifier.fillMaxWidth(),
        ) {
            if (oczka.isEmpty()) {
                repeat(5) {
                    Image(
                        painter = painterResource(id = R.drawable.znak_zapytania),
                        contentDescription = "Znaki zapytania",
                        modifier = Modifier
                            .size(64.dp)
                            .padding(4.dp)
                    )
                }
            } else {
                oczka.forEach { liczba ->
                    Image(
                        painter = painterResource(id = wczytajObrazek(liczba)),
                        contentDescription = "Wartość oczek: $liczba",
                        modifier = Modifier
                            .size(64.dp)
                            .padding(4.dp)
                    )
                }
            }
        }

        Spacer(modifier = Modifier.height(40.dp))
        val tekstWylosowaneOczka = buildAnnotatedString {
            withStyle(style = SpanStyle(color = Color.Gray)) {
                append("Wylosowane oczka: ")
            }
            oczka.forEachIndexed { index, liczba ->
                append("$liczba")
                if (index < oczka.size - 1) {
                    withStyle(style = SpanStyle(color = Color.Gray)) {
                        append(", ")
                    }
                }
            }
        }
        Text(tekstWylosowaneOczka, fontSize = 20.sp)
        Spacer(modifier = Modifier.height(16.dp))

        val tekstSumaOczek = buildAnnotatedString {
            withStyle(style = SpanStyle(color = Color.Gray)) {
                append("Suma oczek: ")
            }
            append("$wynikRzutu")
            withStyle(style = SpanStyle(color = Color.Gray)) {
                append(".")
            }
        }
        Text(tekstSumaOczek, fontSize = 20.sp)
        Spacer(modifier = Modifier.height(16.dp))

        val tekstIloscRzutow = buildAnnotatedString {
            withStyle(style = SpanStyle(color = Color.Gray)) {
                append("Ilość prób: ")
            }
            append("$iloscProb")
            withStyle(style = SpanStyle(color = Color.Gray)) {
                append(".")
            }
        }
        Text(tekstIloscRzutow, fontSize = 20.sp)
        Spacer(modifier = Modifier.height(16.dp))

        val tekstSumaOgolna = buildAnnotatedString {
            withStyle(style = SpanStyle(color = Color.Gray)) {
                append("Suma ogólna: ")
            }
            withStyle(style = SpanStyle(color = Color.Red, fontSize = 24.sp, fontWeight = FontWeight.Bold)) {
                append("$sumaOgolna")
            }
            withStyle(style = SpanStyle(color = Color.Gray)) {
                append(".")
            }
        }
        Text(tekstSumaOgolna, fontSize = 20.sp)
        Spacer(modifier = Modifier.height(16.dp))

        Row {
            Button(onClick = {
                if (iloscProb >= 15) {
                    iloscProb = 0
                    wynikRzutu = 0
                    sumaOgolna = 0
                }
                oczka = List(5) { Random.nextInt(1, 7) }
                wynikRzutu = oczka.sum()
                iloscProb += 1
                sumaOgolna += wynikRzutu
                if (iloscProb <= 4) {
                    playBeep()
                } else {
                    // Do nothing for now
                }
                if (iloscProb == 5) {
                    playSound(kontekstDlaWszystkichElementow)
                    Toast.makeText(
                        kontekstDlaWszystkichElementow,
                        "Koniec gry. Zdobyto $sumaOgolna punktów.",
                        Toast.LENGTH_LONG
                    ).show()
                }
            }, modifier = Modifier.padding(10.dp)) {
                Text("Losuj")
            }

            Button(onClick = {
                oczka = emptyList()
                wynikRzutu = 0
                iloscProb = 0
                sumaOgolna = 0
            }, modifier = Modifier.padding(10.dp)) {
                Text("Reset")
            }
        }
    }
}

fun wczytajObrazek(liczba: Int): Int {
    return when (liczba) {
        1 -> R.drawable.kostka1
        2 -> R.drawable.kostka2
        3 -> R.drawable.kostka3
        4 -> R.drawable.kostka4
        5 -> R.drawable.kostka5
        6 -> R.drawable.kostka6
        else -> R.drawable.znak_zapytania
    }
}

private fun playBeep() {
    val generatorTonow = ToneGenerator(AudioManager.STREAM_MUSIC, 80)
    generatorTonow.startTone(ToneGenerator.TONE_PROP_BEEP, 200)
}

private fun playSound(context: Context) {
    val odtwarzaczMediow = MediaPlayer.create(context, R.raw.goodresult)
    if (odtwarzaczMediow.isPlaying) {
        odtwarzaczMediow.stop()
        odtwarzaczMediow.reset()
    }
    odtwarzaczMediow.setVolume(0.1f, 0.1f)
    odtwarzaczMediow.start()
}

@Preview(showBackground = true)
@Composable
fun Podglad() {
    WieczorekTheme {
        WszystkieElementy()
    }
}
