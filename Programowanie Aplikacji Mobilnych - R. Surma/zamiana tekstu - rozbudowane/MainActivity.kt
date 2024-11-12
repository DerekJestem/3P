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
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.compose.ui.tooling.preview.Preview
import com.example.myapplication.ui.theme.MyApplicationTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            MyApplicationTheme() {
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colorScheme.background
                ) {
                    AppElements()
                }
            }
        }
    }
}

@OptIn(ExperimentalMaterial3Api::class) // Needed for TextField
@Composable
fun AppElements() {
    Column(horizontalAlignment = Alignment.CenterHorizontally) {
        CenterAlignedTopAppBar(
            title = {
                Text(
                    "AUTOR XYZ", // Updated app title
                    fontSize = 26.sp,
                    fontWeight = FontWeight.Bold // Fixed the fontWeight assignment
                )
            },
            colors = TopAppBarDefaults.centerAlignedTopAppBarColors(
                containerColor = Color.Green.copy(alpha = 0.3f)
            )
        )

        var inputText by remember { mutableStateOf("") }
        var inputText2 by remember { mutableStateOf("") }
        var finalText by remember { mutableStateOf("Old text") }

        Text("Metoda 1:", fontSize = 30.sp, modifier = Modifier.padding(vertical = 10.dp))
        Text(inputText, modifier = Modifier.padding(vertical = 10.dp), color = Color.Magenta)

        Spacer(modifier = Modifier.height(30.dp))

        TextField(
            value = inputText,
            onValueChange = { inputText = it },
            placeholder = { Text("Wpisz coś tutaj...") }
        )

        Spacer(modifier = Modifier.height(40.dp))

        Divider(color = Color.Gray, thickness = 2.dp)

        Spacer(modifier = Modifier.height(40.dp))

        Text("Method 2:", fontSize = 30.sp, modifier = Modifier.padding(vertical = 10.dp))
        Text(finalText, modifier = Modifier.padding(vertical = 10.dp), color = Color.Magenta)

        Spacer(modifier = Modifier.height(30.dp))

        TextField(
            value = inputText2,
            onValueChange = { inputText2 = it }, // Fixed the variable name
            placeholder = { Text("Wpisz coś tutaj...") }
        )

        Spacer(modifier = Modifier.height(30.dp))

        Button(onClick = { finalText = inputText2 }) {
            Text(text = "Zamień tekst")
        }
    }
}

@Preview(showBackground = true)
@Composable
fun PreviewAppElements() {
    MyApplicationTheme {
        AppElements()
    }
}