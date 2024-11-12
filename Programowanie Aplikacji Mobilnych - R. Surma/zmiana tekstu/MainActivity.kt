package com.example.myapplication

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.*
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.myapplication.ui.theme.MyApplicationTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            MyApplicationTheme(){
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colorScheme.background
                ) {
                    MojeElementy()
                }
            }
        }
    }
}

@OptIn(ExperimentalMaterial3Api::class) // Needed for TextField
@Composable
fun MojeElementy() {
    Column(horizontalAlignment = Alignment.CenterHorizontally) {
        CenterAlignedTopAppBar(
            title = {
                Text(
                    "Zamiana tekstu",
                    fontSize = 26.sp,
                    fontWeight = FontWeight.Bold
                )
            },
            colors = TopAppBarDefaults.centerAlignedTopAppBarColors(
                containerColor = Color.Green.copy(alpha = 0.3f)
            )
        )
        var wpisywanyTekst by remember { mutableStateOf("") }
        Text("Wpisz tekst:", fontSize = 30.sp, modifier = Modifier.padding(horizontal = 0.dp, vertical = 10.dp))
        Text(wpisywanyTekst, modifier = Modifier.padding(horizontal = 0.dp, vertical = 10.dp), color = Color.Magenta)
        Spacer(modifier = Modifier.height(30.dp))
        TextField(
            value = wpisywanyTekst,
            onValueChange = { wpisywanyTekst = it },
            placeholder = { Text("Wpisz tekst...") }
        )
    }
}

@Preview(showBackground = true)
@Composable
fun Podglad() {
    MyApplicationTheme() {
        MojeElementy()
    }
}